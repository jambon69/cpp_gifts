#ifndef CONVEYORBELT_HH_
# define CONVEYORBELT_HH_

#include "Wrap.hh"
#include "IConveyorBelt.hh"
#include <iostream>

class ConveyorBelt : public IConveyorBelt
{
public:
  ConveyorBelt();
  virtual ~ConveyorBelt();
  ConveyorBelt(const ConveyorBelt &);
  ConveyorBelt &operator=(const ConveyorBelt &);
  virtual void setObject(Object *);
  virtual Object *Look() const;
  virtual Box *buttonInBox();
  virtual GiftPaper *buttonInPaper();
  virtual void buttonOut();

private:
  Object *_toy;
};

std::ostream &operator<<(std::ostream &, IConveyorBelt *);

#endif /* !CONVEYORBELT_HH_ */
