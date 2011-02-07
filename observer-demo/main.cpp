#include "Observer.hpp"

#include "ClockTimer.hpp"
#include "DigitalClock.hpp"
#include "AnalogClock.hpp"

int main(int argc, char* argv[])
{
  ClockTimer timer;

  DigitalClock digitalClock(&timer);
  AnalogClock analogClock(&timer);

  timer.Tick();

  return 0;
}