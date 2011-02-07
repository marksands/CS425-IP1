#ifndef ANALOGCLOCK_HPP
#define ANALOGCLOCK_HPP

#include "Observer.hpp" 
#include "ClockTimer.hpp"

class AnalogClock : public Observer
{
  public:
      // attach with subject
    AnalogClock(ClockTimer *subject);
      // detach with subject
    virtual ~AnalogClock();
      // update own time
    void Update(Subject *theChangedSubject);
      // print updated time
    void Draw();

  private:
      // reference to subject
    ClockTimer* subject_;
};

#endif