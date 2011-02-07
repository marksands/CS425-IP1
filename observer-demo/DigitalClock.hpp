#ifndef DIGITALCLOCK_HPP
#define DIGITALCLOCK_HPP

#include "Observer.hpp"
#include "ClockTimer.hpp"

class DigitalClock : public Observer
{
  public:
      // attach with subject
    DigitalClock(ClockTimer *subject);
      // detach with subject
    virtual ~DigitalClock();
      // update own time
    void Update(Subject *theChangedSubject);
      // print updated time
    void Draw();

  private:
      // reference to subject
    ClockTimer* subject_;
};

#endif