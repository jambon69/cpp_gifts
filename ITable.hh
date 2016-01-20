#ifndef ITABLE_HH_
# define ITABLE_HH_

#include "Object.hh"
#include <string>

class ITable
{
public:
  virtual ~ITable() {}
  virtual std::string **Look() = 0;
  virtual void addNewObject(Object *) = 0;
  virtual Object *getObject(int) const = 0;
  virtual Object *takeObject() = 0;
  virtual bool isEmpty() const = 0;
};

#endif /* !ITABLE_HH_ */
