#include <iostream>
#include "Toy.hh"

Toy::Toy(const std::string & name) :
  _name(name)
{
  this->_type = TYPE_TOY;
}

Toy::Toy(Toy const & other) :
  _name(other._name)
{
  this->_type = other._type;
}

Toy::~Toy()
{
}

Toy&		Toy::operator=(Toy const & other)
{
  this->_type = other._type;
  return (*this);
}
