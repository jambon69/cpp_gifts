#ifndef OBJECT_HH_
# define OBJECT_HH_

#include <string>

enum Type
  {
    TYPE_TOY,
    TYPE_PAPERGIFT,
    TYPE_BOX,
    TYPE_WRAP
  };

class		Object
{
public:
  virtual ~Object() {}
  virtual std::string const	getName() const = 0;
  virtual int			getType() const = 0;
  virtual void			isTaken() const = 0;
};

#endif /* !OBJECT_HH_ */
