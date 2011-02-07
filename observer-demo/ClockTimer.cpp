#include "ClockTimer.hpp"

void ClockTimer::Tick()
{
  time_t rawtime;
  time ( &rawtime );
  strftime( tmpbuf, 128, "%H:%M:%S", localtime(&rawtime) );
  Notify();
}

int ClockTimer::GetHour()
{ 
  char timebuf[128];
  strncpy(timebuf, tmpbuf, 2);
  timebuf[2] = NULL;

  return atoi(timebuf);
}

int ClockTimer::GetMinute()
{ 
  char timebuf[128];
  strncpy(timebuf, tmpbuf+3, 2);
  timebuf[2] = NULL;

  return atoi(timebuf);
}

int ClockTimer::GetSecond()
{ 
  char timebuf[128];
  strncpy(timebuf, tmpbuf+6, 2);
  timebuf[2] = NULL;

  return atoi(timebuf);
}