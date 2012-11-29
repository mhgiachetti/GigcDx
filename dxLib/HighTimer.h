// HighTimer.h: interface for the HighTimer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGHIGHTIMER_H__97EEEEF7_9356_4483_9095_A86138B36F36__INCLUDED_)
#define AFX_MGHIGHTIMER_H__97EEEEF7_9356_4483_9095_A86138B36F36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>

class HighTimer  
{

	//atributos
public:
	int m_fps;
	double m_elapsed;
	LARGE_INTEGER m_start;
	int m_frameCount;
	double m_frame_time_acum;
	LARGE_INTEGER m_frequency;


public:
	HighTimer();
	virtual ~HighTimer();

	virtual void Reset();
	virtual void Set();


};

#endif // !defined(AFX_MGHIGHTIMER_H__97EEEEF7_9356_4483_9095_A86138B36F36__INCLUDED_)
