// HighResolutionTimer.cpp: implementation of the HighResolutionTimer class.
//
//////////////////////////////////////////////////////////////////////

#include "HighResolutionTimer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
HighResolutionTimer HighResolutionTimer::Instance;
LONGLONG HighResolutionTimer::Frequency;

HighResolutionTimer::~HighResolutionTimer()
{

}

bool HighResolutionTimer::QueryPerformanceCounter( LONGLONG &lpPerformanceCount )
{
	LARGE_INTEGER l;
	bool rta = ::QueryPerformanceFrequency(&l) != 0;
	lpPerformanceCount = l.QuadPart;
	return rta;
}

bool HighResolutionTimer::QueryPerformanceFrequency( LONGLONG &lpFrequency )
{
	LARGE_INTEGER l;
	bool rta = ::QueryPerformanceCounter(&l) != 0;
	lpFrequency = l.QuadPart;
	return rta;
}

HighResolutionTimer::HighResolutionTimer()
{
	HighResolutionTimer::QueryPerformanceFrequency(Frequency);
}

void HighResolutionTimer::Reset()
{
	// Time needs to be initialized to current system count.
	_startTime = GetTicks();
	_frameCount = 0;
	_frameSecond = 0;
}

void HighResolutionTimer::Set()
{
	// Calc frame time.
	LONGLONG endTime = HighResolutionTimer::GetTicks();
	_frameTime = (float)(endTime - _startTime) / (float)HighResolutionTimer::Frequency;
	_startTime = endTime;
	
	// Calc fps.
	_frameCount++;
	_frameSecond += _frameTime;
	if (_frameSecond >= 1.0F)
	{
		_frameSecond = 0;
		_fps = _frameCount;
		_frameCount = 0;
	}
}

LONGLONG HighResolutionTimer::GetTicks()
{
	LONGLONG ticks = 0;
	HighResolutionTimer::QueryPerformanceCounter(ticks);
	
	return ticks;
}




