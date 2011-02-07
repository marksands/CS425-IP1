#ifndef CLOCKTIMER_HPP
#define CLOCKTIMER_HPP

#include "Observer.hpp"

#include <sys/types.h> 
#include <sys/timeb.h> 
#include <cstdio>
#include <ctime>
#include <string>

class ClockTimer : public Subject
{
  public:
      // tmpbuf = current system time
    ClockTimer() {
      time_t rawtime;
      time ( &rawtime );
      strftime( tmpbuf, 128, "%H:%M:%S", localtime(&rawtime) );
    }

      // get hour (used by observer)
    int GetHour();
      // get minute (used by observer)
    int GetMinute();
      // get second (used by observer)
    int GetSecond();
      // obtian system time (change state)
    void Tick();

  private:
      // store system time
    char tmpbuf[128];
};

#endif