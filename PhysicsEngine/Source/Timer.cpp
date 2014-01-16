#include "Timer.h"
#include <Windows.h>

Timer::Timer(void)
: m_SecondsPerCount(0.0), m_DeltaTime(-1.0), m_BaseTime(0), 
  m_PausedTime(0), m_PrevTime(0), m_CurrTime(0), m_Stopped(false)
{
	// Get frequency off processor then calculate how long each processor cylce is
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	m_SecondsPerCount = 1.0 / (double)countsPerSec;
}

// Time since reset was last called not counting any stopped time
float Timer::TotalTime() const
{
	/* If stopped don't count time that passed since stopped. IF previously paused subtract
	  paused time from stop time for correct time */
	
	if( m_Stopped )
	{
		return (float)(((m_StopTime - m_PausedTime)-m_BaseTime)*m_SecondsPerCount);
	}

	// Subtract paused time from current time
	else
	{
		return (float)(((m_CurrTime-m_PausedTime)-m_BaseTime)*m_SecondsPerCount);
	}
}

float Timer::DeltaTime() const
{
	return (float)m_DeltaTime;
}

void Timer::Reset()
{
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	m_BaseTime = currTime;
	m_PrevTime = currTime;
	m_StopTime = 0;
	m_Stopped  = false;
}

void Timer::Start()
{
	__int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

	// Accumulate the time elapsed between stop and start pairs. 

	if( m_Stopped )
	{
		m_PausedTime += (startTime - m_StopTime);	

		m_PrevTime = startTime;
		m_StopTime = 0;
		m_Stopped  = false;
	}
}

void Timer::Stop()
{
	if( !m_Stopped )
	{
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		m_StopTime = currTime;
		m_Stopped  = true;
	}
}

void Timer::Tick()
{
	if( m_Stopped )
	{
		m_DeltaTime = 0.0;
		return;
	}

	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	m_CurrTime = currTime;

	// Time difference between this frame and the previous.
	m_DeltaTime = (m_CurrTime - m_PrevTime)*m_SecondsPerCount;

	// Prepare for next frame.
	m_PrevTime = m_CurrTime;

	// Force Non Negative if 
	if(m_DeltaTime < 0.0)
	{
		m_DeltaTime = 0.0;
	}
}
