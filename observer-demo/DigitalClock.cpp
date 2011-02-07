#include "DigitalClock.hpp"

DigitalClock::DigitalClock(ClockTimer* subject)
{ 
  subject_ = subject;
  subject_->Attach(this);
}

DigitalClock::~DigitalClock()
{ 
  subject_->Detach(this);
}

void DigitalClock::Update(Subject *theChangedSubject)
{
  if( theChangedSubject == subject_ )
    Draw();
}

void DigitalClock::Draw()
{ 
  int hour = subject_->GetHour();
  int minute = subject_->GetMinute();
  int second = subject_->GetSecond();

  std::cout << "Digital Clock time is "
   << hour << ":" 
   << minute << ":" 
   << second << std::endl;
}

