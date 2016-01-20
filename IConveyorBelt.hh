#ifndef ICONVEYORBELT_HH_
# define ICONVEYORBELT_HH_

#include "Object.hh"

class IConveyorBelt
{
public:
  virtual ~IConveyorBelt() {}
  virtual void setObject(Object *) = 0;
  virtual Object *Look() const = 0;
  virtual void buttonOut() = 0;
  virtual Box *buttonInBox() = 0;
  virtual GiftPaper *buttonInPaper() = 0;
};

#endif /* !ICONVEYORBELT_HH_ */
