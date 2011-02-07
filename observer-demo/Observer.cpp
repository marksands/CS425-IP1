#include "Observer.hpp"

void Subject::Attach(Observer* observer)
{
  observers_->push_back(observer);
}

void Subject::Detach(Observer* observer)
{
  observers_->remove(observer);
}

void Subject::Notify()
{
  std::list<Observer*>::iterator iter;

  for ( iter = observers_->begin(); iter != observers_->end(); iter++ )
    (*iter)->Update(this);
}