#ifndef OBSERVER_H
#define OBSERVER_H

class Observer{
  public:
    virtual void notify() = 0;
    virtual ~Observer();
};

#endif // OBSERVER_H
