#include <iostream>
#include "Toy.hh"
#include "LittlePony.hh"

LittlePony::LittlePony(std::string const &name) :
  Toy(name)
{
}

LittlePony::LittlePony(LittlePony const &other) :
  Toy(other)
{
}

LittlePony::~LittlePony()
{
}

LittlePony&		LittlePony::operator=(LittlePony const & other)
{
  this->_type = other._type;
  return (*this);
}

void			LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}

int			LittlePony::getType() const
{
  return (this->_type);
}

std::string const	LittlePony::getName() const
{
  return (this->_name);
}
