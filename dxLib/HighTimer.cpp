// HighTimer.cpp: implementation of the HighTimer class.
//
//////////////////////////////////////////////////////////////////////

#include "HighTimer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HighTimer::HighTimer()
{

}

HighTimer::~HighTimer()
{

}

void HighTimer::Reset()
{
	QueryPerformanceFrequency( &m_frequency );
    QueryPerformanceCounter( &m_start);
}

void HighTimer::Set()
{
	// Calc frame time.
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);
	m_elapsed = (double)(endTime.QuadPart - m_start.QuadPart) / (m_frequency.QuadPart);
	m_start = endTime;
	
	// Calc fps.
	m_frameCount++;
	m_frame_time_acum += m_elapsed;
	if (m_frame_time_acum >= 1.0F)
	{
		m_frame_time_acum = 0;
		m_fps = m_frameCount;
		m_frameCount = 0;
	}	
}
