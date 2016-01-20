#ifndef LITTLEPONY_HH_
# define LITTLEPONY_HH_

#include "Toy.hh"

class			LittlePony : public Toy
{
public:
  LittlePony(std::string const &name);
  LittlePony(LittlePony const & other);
  virtual ~LittlePony();
  LittlePony&		operator=(LittlePony const & other);
  virtual void			isTaken() const;
  virtual int			getType() const;
  virtual std::string const	getName() const;
};

#endif /* !LITTLEPONY_HH_ */
