// HighResolutionTimer.h: interface for the HighResolutionTimer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HIGHRESOLUTIONTIMER_H__95183278_B06A_4811_A70C_903947D958CE__INCLUDED_)
#define AFX_HIGHRESOLUTIONTIMER_H__95183278_B06A_4811_A70C_903947D958CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../dxLib/dxLib.h"
class HighResolutionTimer  
{
public:
	virtual ~HighResolutionTimer();

protected:
	/// <summary>
    /// The current system ticks (count).
    /// </summary>
    /// <param name="lpPerformanceCount">Current performance count of the system.</param>
    /// <returns>False on failure.</returns>
    static bool QueryPerformanceCounter(LONGLONG &lpPerformanceCount);

    /// <summary>
    /// Ticks per second (frequency) that the high performance counter performs.
    /// </summary>
    /// <param name="lpFrequency">Frequency the higher performance counter performs.</param>
    /// <returns>False if the high performance counter is not supported.</returns>
    static bool QueryPerformanceFrequency(LONGLONG &lpFrequency);

    // Members
    LONGLONG _startTime;
    float _frameTime;

    int _fps;
    int _frameCount;
    float _frameSecond;

    // Constructor
    /// <summary>
    /// Cannot instantiate the timer directly.
    /// </summary>
    HighResolutionTimer();

    
public:
	// Timer Methods
    /// <summary>
    /// Resets the timer for a new game.
    /// </summary>
    void Reset();

    /// <summary>
    /// Calculates frame time since last call to Set.
    /// </summary>
    void Set();

    // Static Properties
    /// <summary>
    /// Gets the timer instance.
    /// </summary>
    static HighResolutionTimer Instance;

    /// <summary>
    /// Gets the frequency that all timers performs at.
    /// </summary>
    static LONGLONG Frequency;

    /// <summary>
    /// Gets the current system ticks.
    /// </summary>
    static LONGLONG GetTicks();

    // Properties

    /// <summary>
    /// Gets the time recorded between frames.
    /// </summary>
    float FrameTime;

    /// <summary>
    /// Gets the frames per second based on the time between frames.
    /// </summary>
    float FramesPerSecond;

};

#endif // !defined(AFX_HIGHRESOLUTIONTIMER_H__95183278_B06A_4811_A70C_903947D958CE__INCLUDED_)
