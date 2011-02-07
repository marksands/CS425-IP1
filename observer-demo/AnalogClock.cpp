#include "AnalogClock.hpp"

AnalogClock::AnalogClock(ClockTimer *subject)
{ 
  subject_ = subject;
  subject_->Attach(this);
}

AnalogClock::~AnalogClock()
{
  subject_->Detach(this);
}

void AnalogClock::Update (Subject *theChangedSubject)
{
  if( theChangedSubject == subject_ )
    Draw();
}

void AnalogClock::Draw()
{
  int hour = subject_->GetHour();
  int minute = subject_->GetMinute();
  int second = subject_->GetSecond();

  std::cout << "Analog Clock time is "
   << hour << ":" 
   << minute << ":" 
   << second << std::endl;
}