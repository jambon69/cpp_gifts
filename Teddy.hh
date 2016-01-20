#ifndef TEDDY_HH_
# define TEDDY_HH_

#include "Toy.hh"

class			Teddy : public Toy
{
public:
  Teddy(const std::string & name);
  Teddy(Teddy const & other);
  virtual ~Teddy();
  Teddy&		operator=(Teddy const & other);
  virtual void		isTaken() const;
  virtual int		getType() const;
  virtual std::string const getName() const;
};

#endif /* !TEDDY_HH_ */
