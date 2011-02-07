#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <list>
#include <iostream>

class Subject;

class Observer {
  public:
    Observer() {};
    virtual ~Observer() {};
    virtual void Update(Subject* theChangeSubject) = 0;
};

class Subject
{
  public:
    virtual ~Subject() {
      delete observers_;
    };

    void Attach(Observer* observer);
    void Detach(Observer* observer);
    void Notify();

  protected:
    Subject() {
      observers_ = new std::list<Observer*>();
    };

  private:
    std::list<Observer*>* observers_;
};

#endif