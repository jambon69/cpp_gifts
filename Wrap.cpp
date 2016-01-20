#include <iostream>
#include <string>
#include "Object.hh"
#include "Wrap.hh"

Wrap::Wrap(std::string const name, int type): _name(name), _type(type),
					 _toy(NULL), _box(NULL), _isOpen(true)
{
}

Wrap::Wrap(Wrap const &w): _name(w.getName()), _type(w.getType()),
			   _toy(w.getToy()), _box(w.getBox()), _isOpen(w.getIsOpen())
{
}

Wrap&    Wrap::operator=(Wrap const &w)
{
  if (this == &w)
    return (*this);
  this->_type = w.getType();
  this->_toy = w.getToy();
  this->_box = w.getBox();
  this->_isOpen = w.getIsOpen();
  return (*this);
}

bool            Wrap::wrapMeThat(bool isToy, Object *toy, Box *box)
{
  if (isToy)
    {
      if (this->_toy == NULL && this->_isOpen)
	{
	  this->_toy = toy;
	  return (true);
	}
      return (false);
    }
  if (this->_toy == NULL)
    {
      this->_box = box;
      return (true);
    }
  return (false);
}

std::string	const Wrap::getName() const
{
  return (this->_name);
}

int		Wrap::getType() const
{
  return (this->_type);
}

void		Wrap::isTaken() const
{
  std::cout << "whistles while working" << std::endl;
}

Object		*Wrap::getToy() const
{
  return (this->_toy);
}

Box		*Wrap::getBox() const
{
  return (this->_box);
}

bool		Wrap::getIsOpen() const
{
  return (this->_isOpen);
}
