// TgcFpsCamera.h: interface for the TgcFpsCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TGCFPSCAMERA_H__91200C13_D31D_428D_B2D5_C1ACB8634E0F__INCLUDED_)
#define AFX_TGCFPSCAMERA_H__91200C13_D31D_428D_B2D5_C1ACB8634E0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"
#include "TgcD3dInput.h"

class TgcFpsCamera  
{
public:
	virtual ~TgcFpsCamera();

	//Constantes de movimiento
    static const float DEFAULT_ROTATION_SPEED;
    static const float DEFAULT_MOVEMENT_SPEED;
    static const float DEFAULT_JUMP_SPEED;
    static const Vector3 CAMERA_VELOCITY;
    static const Vector3 CAMERA_POS;
    static const Vector3 CAMERA_ACCELERATION;

    //Ejes para ViewMatrix
    static const Vector3 WORLD_XAXIS;
    static const Vector3 WORLD_YAXIS;
    static const Vector3 WORLD_ZAXIS;
    static const Vector3 DEFAULT_UP_VECTOR;

    float accumPitchDegrees;
    Vector3 eye;
    Vector3 xAxis;
    Vector3 yAxis;
    Vector3 zAxis;
    Vector3 viewDir;
    Vector3 lookAt;

    //Banderas de Input
    bool moveForwardsPressed;
    bool moveBackwardsPressed;
    bool moveRightPressed;
    bool moveLeftPressed;
    bool moveUpPressed;
    bool moveDownPressed;


    bool enable;
    /// <summary>
    /// Habilita o no el uso de la camara
    /// </summary>
    PROPERTYSIMPLGETSET(bool,Enable,enable);
    //public bool Enable
    //{
    //    get { return enable; }
    //    set
    //    {
    //        enable = value;

            //Si se habilito la camara, cargar como la cámara actual
    //        if (value)
    //        {
                //GuiController.Instance.CurrentCamera = this;
    //        }
    //    }
    //}

    Vector3 acceleration;
    /// <summary>
    /// Aceleracion de la camara en cada uno de sus ejes
    /// </summary>
    PROPERTYSIMPLGETSET(Vector3,Acceleration,acceleration);

    bool accelerationEnable;
    /// <summary>
    /// Activa o desactiva el efecto de Aceleración/Desaceleración
    /// </summary>
    PROPERTYSIMPLGETSET(bool,AccelerationEnable,accelerationEnable);

    Vector3 currentVelocity;
    /// <summary>
    /// Velocidad de desplazamiento actual, teniendo en cuenta la aceleracion
    /// </summary>
    PROPERTYSIMPLGETSET(Vector3,CurrentVelocity,currentVelocity);

    Vector3 velocity;
    /// <summary>
    /// Velocidad de desplazamiento de la cámara en cada uno de sus ejes
    /// </summary>
    PROPERTYSIMPLGETSET(Vector3,Velocity,velocity);

    /// <summary>
    /// Velocidad de desplazamiento de los ejes XZ de la cámara
    /// </summary>
    PROPERTYGETSET(float,MovementSpeed);
	float GetMovementSpeed(){return velocity.X;}
	void SetMovementSpeed(float value){velocity.X = value; velocity.Z = value;}

    /// <summary>
    /// Velocidad de desplazamiento del eje Y de la cámara
    /// </summary>
    PROPERTYGETSET(float,JumpSpeed);
	float GetJumpSpeed(){return velocity.Y;}
	void SetJumpSpeed(float value){velocity.Y = value;}

    float rotationSpeed;
    /// <summary>
    /// Velocidad de rotacion de la cámara
    /// </summary>
    PROPERTYSIMPLGETSET(float,RotationSpeed,rotationSpeed);

    Matrix viewMatrix;
    /// <summary>
    /// View Matrix resultante
    /// </summary>
    PROPERTYSIMPLGET(Matrix,ViewMatrix,viewMatrix);

    /// <summary>
    /// Posicion actual de la camara
    /// </summary>
    PROPERTYSIMPLGET(Vector3,Position,eye);

    /// <summary>
    /// Punto hacia donde mira la cámara
    /// </summary>
    PROPERTYSIMPLGET(Vector3,LookAt,lookAt);

    MouseButtons rotateMouseButton;
    /// <summary>
    /// Boton del mouse que debe ser presionado para rotar la camara.
    /// Por default es boton izquierdo.
    /// </summary>
    PROPERTYSIMPLGETSET(MouseButtons,RotateMouseButton,rotateMouseButton);

    /// <summary>
    /// Crea la cámara con valores iniciales.
    /// Aceleración desactivada por Default
    /// </summary>
    TgcFpsCamera();

    /// <summary>
    /// Carga los valores default de la camara
    /// </summary>
    void resetValues();


    /// <summary>
    /// Configura la posicion de la cámara
    /// </summary>
    void setCamera(Vector3 eye, Vector3 target, Vector3 up);

    /// <summary>
    /// Configura la posicion de la cámara
    /// </summary>
    void setCamera(Vector3 pos, Vector3 lookAt);

    /// <summary>
    /// Moves the camera by dx world units to the left or right; dy
    /// world units upwards or downwards; and dz world units forwards
    /// or backwards.
    /// </summary>
    void move(float dx, float dy, float dz);

    /// <summary>
    /// Moves the camera by the specified amount of world units in the specified
    /// direction in world space. 
    /// </summary>
    void move(Vector3 direction, Vector3 amount);

    /// <summary>
    /// Rotates the camera based on its current behavior.
    /// Note that not all behaviors support rolling.
    ///
    /// This Camera class follows the left-hand rotation rule.
    /// Angles are measured clockwise when looking along the rotation
    /// axis toward the origin. Since the Z axis is pointing into the
    /// screen we need to negate rolls.
    /// </summary>
    void rotate(float headingDegrees, float pitchDegrees, float rollDegrees);

    /// <summary>
    /// This method applies a scaling factor to the rotation angles prior to
    /// using these rotation angles to rotate the camera. This method is usually
    /// called when the camera is being rotated using an input device (such as a
    /// mouse or a joystick).
    /// </summary>
    void rotateSmoothly(float headingDegrees, float pitchDegrees, float rollDegrees);

    /// <summary>
    /// Moves the camera using Newton's second law of motion. Unit mass is
    /// assumed here to somewhat simplify the calculations. The direction vector
    /// is in the range [-1,1].
    /// </summary>
    void updatePosition(Vector3 direction, float elapsedTimeSec);

    void setPosition(Vector3 pos);

    void rotateFirstPerson(float headingDegrees, float pitchDegrees);


    /// <summary>
    /// Updates the camera's velocity based on the supplied movement direction
    /// and the elapsed time (since this method was last called). The movement
    /// direction is the in the range [-1,1].
    /// </summary>
    void updateVelocity(Vector3 direction, float elapsedTimeSec);

    /// <summary>
    /// Actualizar currentVelocity sin aplicar aceleracion
    /// </summary>
    void updateVelocityNoAcceleration(Vector3 direction);

    /// <summary>
    /// Reconstruct the view matrix.
    /// </summary>
    void reconstructViewMatrix(bool orthogonalizeAxes);

    /// <summary>
    /// Actualiza los valores de la camara
    /// </summary>
    void updateCamera();

    /// <summary>
    /// Actualiza la ViewMatrix, si es que la camara esta activada
    /// </summary>
    void updateViewMatrix(::Device d3dDevice);

    /// <summary>
    /// Obtiene la direccion a moverse por la camara en base a la entrada de teclado
    /// </summary>
    Vector3 getMovementDirection(TgcD3dInput d3dInput);

    Vector3 getPosition()
    {
        return eye;
    }

    Vector3 getLookAt()
    {
        return lookAt;
    }

    /// <summary>
    /// String de codigo para setear la camara desde GuiController, con la posicion actual y direccion de la camara
    /// </summary>
    string getPositionCode();



};

#endif // !defined(AFX_TGCFPSCAMERA_H__91200C13_D31D_428D_B2D5_C1ACB8634E0F__INCLUDED_)
