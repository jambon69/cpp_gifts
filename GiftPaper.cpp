#include <string>
#include "Object.hh"
#include "GiftPaper.hh"
#include "Box.hh"

GiftPaper::GiftPaper(std::string name, Type type):
  Wrap(name, type)
{
}

GiftPaper::GiftPaper(GiftPaper const &g):
  Wrap(g.getName(), g.getType())
{
}

const std::string GiftPaper::getName() const
{
  return (this->_name);
}

GiftPaper	&GiftPaper::operator=(GiftPaper const &w)
{
  if (this == &w)
    return (*this);
  this->_type = w.getType();
  this->_toy = w.getToy();
  this->_box = w.getBox();
  this->_isOpen = w.getIsOpen();
  return (*this);
}

Box		*GiftPaper::openMe()
{
  return (this->_box);
}
