// TgcFpsCamera.cpp: implementation of the TgcFpsCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "TgcFpsCamera.h"
#include "GuiController.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const float TgcFpsCamera::DEFAULT_ROTATION_SPEED = 2.0f;
const float TgcFpsCamera::DEFAULT_MOVEMENT_SPEED = 100.0f;
const float TgcFpsCamera::DEFAULT_JUMP_SPEED = 100.0f;
const Vector3 TgcFpsCamera::CAMERA_VELOCITY(DEFAULT_MOVEMENT_SPEED, DEFAULT_JUMP_SPEED, DEFAULT_MOVEMENT_SPEED);
const Vector3 TgcFpsCamera::CAMERA_POS(0.0f, 1.0f, 0.0f);
const Vector3 TgcFpsCamera::CAMERA_ACCELERATION(400.0f, 400.0f, 400.0f);

//Ejes para ViewMatrix
const Vector3 TgcFpsCamera::WORLD_XAXIS(1.0f, 0.0f, 0.0f);
const Vector3 TgcFpsCamera::WORLD_YAXIS(0.0f, 1.0f, 0.0f);
const Vector3 TgcFpsCamera::WORLD_ZAXIS(0.0f, 0.0f, 1.0f);
const Vector3 TgcFpsCamera::DEFAULT_UP_VECTOR(0.0f, 1.0f, 0.0f);

TgcFpsCamera::~TgcFpsCamera()
{

}

TgcFpsCamera::TgcFpsCamera()
{
	resetValues();
}

void TgcFpsCamera::resetValues()
{
	moveForwardsPressed = false;
	moveBackwardsPressed = false;
	moveRightPressed = false;
	moveLeftPressed = false;
	moveUpPressed = false;
	moveDownPressed = false;
	
	accumPitchDegrees = 0.0f;
	rotationSpeed = DEFAULT_ROTATION_SPEED;
	eye = Vector3(0.0f, 0.0f, 0.0f);
	xAxis = Vector3(1.0f, 0.0f, 0.0f);
	yAxis = Vector3(0.0f, 1.0f, 0.0f);
	zAxis = Vector3(0.0f, 0.0f, 1.0f);
	viewDir = Vector3(0.0f, 0.0f, 1.0f);
	lookAt = eye + viewDir;
	
	accelerationEnable = false;
	acceleration = CAMERA_ACCELERATION;
	currentVelocity = Vector3(0.0f, 0.0f, 0.0f);
	velocity = CAMERA_VELOCITY;
	viewMatrix.Identity();
	setPosition(CAMERA_POS);
	
	rotateMouseButton = MouseButtons_BUTTON_LEFT;
}

void TgcFpsCamera::setCamera( Vector3 eye, Vector3 target, Vector3 up )
{
	this->eye = eye;
	
	zAxis = target - eye;
	zAxis.Normalize();
	
	viewDir = zAxis;
	lookAt = eye + viewDir;
	
	xAxis = Vector3::Cross(up, zAxis);
	xAxis.Normalize();
	
	yAxis = Vector3::Cross(zAxis, xAxis);
	yAxis.Normalize();
	//xAxis.Normalize();
	
	viewMatrix.Identity();
	
	viewMatrix.M11 = xAxis.X;
	viewMatrix.M21 = xAxis.Y;
	viewMatrix.M31 = xAxis.Z;
	viewMatrix.M41 = -Vector3::Dot(xAxis, eye);
	
	viewMatrix.M12 = yAxis.X;
	viewMatrix.M22 = yAxis.Y;
	viewMatrix.M32 = yAxis.Z;
	viewMatrix.M42 = -Vector3::Dot(yAxis, eye);
	
	viewMatrix.M13 = zAxis.X;
	viewMatrix.M23 = zAxis.Y;
	viewMatrix.M33 = zAxis.Z;
	viewMatrix.M43 = -Vector3::Dot(zAxis, eye);
	
	viewMatrix.LookAtLH(eye, target, up);
	
	// Extract the pitch angle from the view matrix.
	accumPitchDegrees = Geometry::RadianToDegree((float)-asin((double)viewMatrix.M23));
}

void TgcFpsCamera::setCamera( Vector3 pos, Vector3 lookAt )
{
	setCamera(pos, lookAt, DEFAULT_UP_VECTOR);
}

void TgcFpsCamera::move( float dx, float dy, float dz )
{
	Vector3 auxEye = this->eye;
	Vector3 forwards;
	
	// Calculate the forwards direction. Can't just use the camera's local
	// z axis as doing so will cause the camera to move more slowly as the
	// camera's view approaches 90 degrees straight up and down.
	forwards = Vector3::Cross(xAxis, WORLD_YAXIS);
	forwards.Normalize();
	
	
	auxEye += xAxis * dx;
	auxEye += WORLD_YAXIS * dy;
	auxEye += forwards * dz;
	
	setPosition(auxEye);
}

void TgcFpsCamera::move( Vector3 direction, Vector3 amount )
{
	eye.X += direction.X * amount.X;
	eye.Y += direction.Y * amount.Y;
	eye.Z += direction.Z * amount.Z;
	
	reconstructViewMatrix(false);
}

void TgcFpsCamera::rotate( float headingDegrees, float pitchDegrees, float rollDegrees )
{
	rollDegrees = -rollDegrees;
	rotateFirstPerson(headingDegrees, pitchDegrees);
	reconstructViewMatrix(true);
}

void TgcFpsCamera::rotateSmoothly( float headingDegrees, float pitchDegrees, float rollDegrees )
{
	headingDegrees *= rotationSpeed;
	pitchDegrees *= rotationSpeed;
	rollDegrees *= rotationSpeed;
	
	rotate(headingDegrees, pitchDegrees, rollDegrees);
}

void TgcFpsCamera::updatePosition( Vector3 direction, float elapsedTimeSec )
{
	if(currentVelocity.LengthSq() != 0.0f)
	{
		// Only move the camera if the velocity vector is not of zero length.
		// Doing this guards against the camera slowly creeping around due to
		// floating point rounding errors.
		
		Vector3 displacement;
		if (accelerationEnable)
		{
			displacement = (currentVelocity * elapsedTimeSec) +
                (0.5f * acceleration * elapsedTimeSec * elapsedTimeSec);
		}
		else
		{
			displacement = (currentVelocity * elapsedTimeSec);
		}
		
		
		// Floating point rounding errors will slowly accumulate and cause the
		// camera to move along each axis. To prevent any unintended movement
		// the displacement vector is clamped to zero for each direction that
		// the camera isn't moving in. Note that the updateVelocity() method
		// will slowly decelerate the camera's velocity back to a stationary
		// state when the camera is no longer moving along that direction. To
		// account for this the camera's current velocity is also checked.
		
		if (direction.X == 0.0f && fabsf(currentVelocity.X) < 1e-6f)
			displacement.X = 0.0f;
		
		if (direction.Y == 0.0f && fabsf(currentVelocity.Y) < 1e-6f)
			displacement.Y = 0.0f;
		
		if (direction.Z == 0.0f && fabsf(currentVelocity.Z) < 1e-6f)
			displacement.Z = 0.0f;
		
		move(displacement.X, displacement.Y, displacement.Z);
	}
	
	// Continuously update the camera's velocity vector even if the camera
	// hasn't moved during this call. When the camera is no longer being moved
	// the camera is decelerating back to its stationary state.
	
	if (accelerationEnable)
	{
		updateVelocity(direction, elapsedTimeSec);
	}
	else
	{
		updateVelocityNoAcceleration(direction);
	}
}

void TgcFpsCamera::setPosition( Vector3 pos )
{
	eye = pos;
	reconstructViewMatrix(false);
}

void TgcFpsCamera::rotateFirstPerson( float headingDegrees, float pitchDegrees )
{
	accumPitchDegrees += pitchDegrees;
	
	if (accumPitchDegrees > 90.0f)
	{
		pitchDegrees = 90.0f - (accumPitchDegrees - pitchDegrees);
		accumPitchDegrees = 90.0f;
	}
	
	if (accumPitchDegrees < -90.0f)
	{
		pitchDegrees = -90.0f - (accumPitchDegrees - pitchDegrees);
		accumPitchDegrees = -90.0f;
	}
	
	float heading = Geometry::DegreeToRadian(headingDegrees);
	float pitch = Geometry::DegreeToRadian(pitchDegrees);
	
	Matrix rotMtx;
	Vector4 result;
	
	// Rotate camera's existing x and z axes about the world y axis.
	if (heading != 0.0f)
	{
		rotMtx.RotationY(heading);
		
		result = Vector3::Transform(xAxis, rotMtx);
		xAxis = Vector3(result.X, result.Y, result.Z);
		
		result = Vector3::Transform(zAxis, rotMtx);
		zAxis = Vector3(result.X, result.Y, result.Z);
	}
	
	// Rotate camera's existing y and z axes about its existing x axis.
	if (pitch != 0.0f)
	{
		rotMtx.RotationAxis(xAxis, pitch);
		
		result = Vector3::Transform(yAxis, rotMtx);
		yAxis = Vector3(result.X, result.Y, result.Z);
		
		result = Vector3::Transform(zAxis, rotMtx);
		zAxis = Vector3(result.X, result.Y, result.Z);
	}
}

void TgcFpsCamera::updateVelocity( Vector3 direction, float elapsedTimeSec )
{
	if (direction.X != 0.0f)
	{
		// Camera is moving along the x axis.
		// Linearly accelerate up to the camera's max speed.
		
		currentVelocity.X += direction.X * acceleration.X * elapsedTimeSec;
		
		if (currentVelocity.X > velocity.X)
			currentVelocity.X = velocity.X;
		else if (currentVelocity.X < -velocity.X)
			currentVelocity.X = -velocity.X;
	}
	else
	{
		// Camera is no longer moving along the x axis.
		// Linearly decelerate back to stationary state.
		
		if (currentVelocity.X > 0.0f)
		{
			if ((currentVelocity.X -= acceleration.X * elapsedTimeSec) < 0.0f)
				currentVelocity.X = 0.0f;
		}
		else
		{
			if ((currentVelocity.X += acceleration.X * elapsedTimeSec) > 0.0f)
				currentVelocity.X = 0.0f;
		}
	}
	
	if (direction.Y != 0.0f)
	{
		// Camera is moving along the y axis.
		// Linearly accelerate up to the camera's max speed.
		
		currentVelocity.Y += direction.Y * acceleration.Y * elapsedTimeSec;
		
		if (currentVelocity.Y > velocity.Y)
			currentVelocity.Y = velocity.Y;
		else if (currentVelocity.Y < -velocity.Y)
			currentVelocity.Y = -velocity.Y;
	}
	else
	{
		// Camera is no longer moving along the y axis.
		// Linearly decelerate back to stationary state.
		
		if (currentVelocity.Y > 0.0f)
		{
			if ((currentVelocity.Y -= acceleration.Y * elapsedTimeSec) < 0.0f)
				currentVelocity.Y = 0.0f;
		}
		else
		{
			if ((currentVelocity.Y += acceleration.Y * elapsedTimeSec) > 0.0f)
				currentVelocity.Y = 0.0f;
		}
	}
	
	if (direction.Z != 0.0f)
	{
		// Camera is moving along the z axis.
		// Linearly accelerate up to the camera's max speed.
		
		currentVelocity.Z += direction.Z * acceleration.Z * elapsedTimeSec;
		
		if (currentVelocity.Z > velocity.Z)
			currentVelocity.Z = velocity.Z;
		else if (currentVelocity.Z < -velocity.Z)
			currentVelocity.Z = -velocity.Z;
	}
	else
	{
		// Camera is no longer moving along the z axis.
		// Linearly decelerate back to stationary state.
		
		if (currentVelocity.Z > 0.0f)
		{
			if ((currentVelocity.Z -= acceleration.Z * elapsedTimeSec) < 0.0f)
				currentVelocity.Z = 0.0f;
		}
		else
		{
			if ((currentVelocity.Z += acceleration.Z * elapsedTimeSec) > 0.0f)
				currentVelocity.Z = 0.0f;
		}
	}
}

void TgcFpsCamera::updateVelocityNoAcceleration( Vector3 direction )
{
	currentVelocity.X = velocity.X * direction.X;
	currentVelocity.Y = velocity.Y * direction.Y;
	currentVelocity.Z = velocity.Z * direction.Z;
}

void TgcFpsCamera::reconstructViewMatrix( bool orthogonalizeAxes )
{
	if (orthogonalizeAxes)
	{
		// Regenerate the camera's local axes to orthogonalize them.
		
		zAxis.Normalize();
		
		yAxis = Vector3::Cross(zAxis, xAxis);
		yAxis.Normalize();
		
		xAxis = Vector3::Cross(yAxis, zAxis);
		xAxis.Normalize();
		
		viewDir = zAxis;
		lookAt = eye + viewDir;
	}
	
	// Reconstruct the view matrix.
	
	viewMatrix.M11 = xAxis.X;
	viewMatrix.M21 = xAxis.Y;
	viewMatrix.M31 = xAxis.Z;
	viewMatrix.M41 = -Vector3::Dot(xAxis, eye);
	
	viewMatrix.M12 = yAxis.X;
	viewMatrix.M22 = yAxis.Y;
	viewMatrix.M32 = yAxis.Z;
	viewMatrix.M42 = -Vector3::Dot(yAxis, eye);
	
	viewMatrix.M13 = zAxis.X;
	viewMatrix.M23 = zAxis.Y;
	viewMatrix.M33 = zAxis.Z;
	viewMatrix.M43 = -Vector3::Dot(zAxis, eye);
	
	viewMatrix.M14 = 0.0f;
	viewMatrix.M24 = 0.0f;
	viewMatrix.M34 = 0.0f;
	viewMatrix.M44 = 1.0f;
}

void TgcFpsCamera::updateCamera()
{
	//Si la camara no está habilitada, no procesar el resto del input
	if (!enable)
	{
		return;
	}
	
	float elapsedTimeSec = GuiController::Instance.ElapsedTime;
	TgcD3dInput d3dInput = GuiController::Instance.D3dInput;
	
	//Imprimir por consola la posicion actual de la camara
	if ((d3dInput.keyDown(Key_LeftShift) || d3dInput.keyDown(Key_RightShift)) && d3dInput.keyPressed(Key_P))
	{
		GuiController::Instance.printCurrentPosition();
		return;
	}
	
	
	float heading = 0.0f;
	float pitch = 0.0f;
	
	//Obtener direccion segun entrada de teclado
	Vector3 direction = getMovementDirection(d3dInput);
	
	pitch = d3dInput.YposRelative * rotationSpeed;
	heading = d3dInput.XposRelative * rotationSpeed;
	
	//Solo rotar si se esta aprentando el boton del mouse configurado
	if (d3dInput.buttonDown(rotateMouseButton))
	{
		rotate(heading, pitch, 0.0f);
	}
	
	
	updatePosition(direction, elapsedTimeSec);
}

void TgcFpsCamera::updateViewMatrix( ::Device d3dDevice )
{
	if (!enable)
	{
		return;
	}
	
	d3dDevice.Transform.View = viewMatrix;
}

Vector3 TgcFpsCamera::getMovementDirection( TgcD3dInput d3dInput )
{
	Vector3 direction = Vector3(0.0f, 0.0f, 0.0f);
	
	//Forward
	if (d3dInput.keyDown(Key_W))
	{
		if (!moveForwardsPressed)
		{
			moveForwardsPressed = true;
			currentVelocity = Vector3(currentVelocity.X, currentVelocity.Y, 0.0f);
		}
		
		direction.Z += 1.0f;
	}
	else
	{
		moveForwardsPressed = false;
	}
	
	//Backward
	if (d3dInput.keyDown(Key_S))
	{
		if (!moveBackwardsPressed)
		{
			moveBackwardsPressed = true;
			currentVelocity = Vector3(currentVelocity.X, currentVelocity.Y, 0.0f);
		}
		
		direction.Z -= 1.0f;
	}
	else
	{
		moveBackwardsPressed = false;
	}
	
	//Strafe right
	if (d3dInput.keyDown(Key_D))
	{
		if (!moveRightPressed)
		{
			moveRightPressed = true;
			currentVelocity = Vector3(0.0f, currentVelocity.Y, currentVelocity.Z);
		}
		
		direction.X += 1.0f;
	}
	else
	{
		moveRightPressed = false;
	}
	
	//Strafe left
	if (d3dInput.keyDown(Key_A))
	{
		if (!moveLeftPressed)
		{
			moveLeftPressed = true;
			currentVelocity = Vector3(0.0f, currentVelocity.Y, currentVelocity.Z);
		}
		
		direction.X -= 1.0f;
	}
	else
	{
		moveLeftPressed = false;
	}
	
	//Jump
	if (d3dInput.keyDown(Key_Space))
	{
		if (!moveUpPressed)
		{
			moveUpPressed = true;
			currentVelocity = Vector3(currentVelocity.X, 0.0f, currentVelocity.Z);
		}
		
		direction.Y += 1.0f;
	}
	else
	{
		moveUpPressed = false;
	}
	
	//Crouch
	if (d3dInput.keyDown(Key_LeftControl))
	{
		if (!moveDownPressed)
		{
			moveDownPressed = true;
			currentVelocity = Vector3(currentVelocity.X, 0.0f, currentVelocity.Z);
		}
		
		direction.Y -= 1.0f;
	}
	else
	{
		moveDownPressed = false;
	}
	
	return direction;
}

std::string TgcFpsCamera::getPositionCode()
{
	//TODO ver de donde carajo sacar el LookAt de esta camara
	Vector3 lookAt = this->LookAt;
	
	//return "GuiController.Instance.setCamera(new Vector3(" +
	//	TgcParserUtils.printFloat(eye.X) + "f, " + TgcParserUtils.printFloat(eye.Y) + "f, " + TgcParserUtils.printFloat(eye.Z) + "f), new Vector3(" +
	//	TgcParserUtils.printFloat(lookAt.X) + "f, " + TgcParserUtils.printFloat(lookAt.Y) + "f, " + TgcParserUtils.printFloat(lookAt.Z) + "f));";
	return "";
}
