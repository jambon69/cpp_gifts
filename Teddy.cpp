#include <iostream>
#include "Toy.hh"
#include "Teddy.hh"

Teddy::Teddy(const std::string & name) :
  Toy(name)
{
}

  Teddy::Teddy(Teddy const & other) :
  Toy(other)
{
}

Teddy::~Teddy()
{
}

Teddy&		Teddy::operator=(Teddy const & other)
{
  this->_type = other._type;
  return (*this);
}

void		Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}

int		Teddy::getType() const
{
  return (this->_type);
}

std::string const	Teddy::getName() const
{
  return (this->_name);
}
