#ifndef TOY_HH_
# define TOY_HH_

#include "Object.hh"

class			Toy : public Object
{
protected:
  const std::string	_name;
  int		 	_type;
public:
  Toy(const std::string & name);
  Toy(Toy const & other);
  virtual ~Toy();
  Toy&				operator=(const Toy & other);
  virtual void			isTaken() const = 0;
  virtual int			getType() const = 0;
  virtual std::string const	getName() const = 0;
};

#endif /* !TOY_HH_ */
