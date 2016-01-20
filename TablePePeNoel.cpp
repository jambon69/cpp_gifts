#include <cstdlib>
#include "TablePePeNoel.hh"

TablePePeNoel::TablePePeNoel()
{
  int i = 0;

  while (i < 11)
    {
      this->_slots[i] = NULL;
      i++;
    }
}

TablePePeNoel::TablePePeNoel(const TablePePeNoel &t)
{
  int i = 0;

  while (i < 10)
    {
      this->_slots[i] = t.getObject(i);
      i++;
    }
  this->_slots[i] = NULL;
}

TablePePeNoel &TablePePeNoel::operator=(const TablePePeNoel &t)
{
  int i = 0;

  if (this == &t)
    return (*this);
  while (i < 10)
    {
      if (this->_slots[i])
	delete this->_slots[i];
      this->_slots[i] = t.getObject(i);
      i++;
    }
  this->_slots[i] = NULL;
  return (*this);
}

TablePePeNoel::~TablePePeNoel()
{
}

std::string **TablePePeNoel::Look()
{
  int i = 0;
  int j = 0;
  std::string **tab = new std::string *[11];

  while (i < 10)
    {
      if (this->_slots[i] != NULL)
	{
	  tab[j] = new std::string (this->_slots[i]->getName());
	  j++;
	}
      i++;
    }
  tab[j] = NULL;
  return (tab);
}

bool TablePePeNoel::isEmpty() const
{
  int i = 0;

  while (i < 10)
    {
      if (this->_slots[i] != NULL)
	return false;
      i++;
    }
  return true;
}

void TablePePeNoel::addNewObject(Object *obj)
{
  int i = 0;

  while (this->_slots[i] != NULL && i < 11)
    i++;
  if (i >= 6)
    std::cout << "Be Carefull not to put too many objects on the table !!" << std::endl;;
  if (i == 11)
    {
      std::cout << "OH MY GOD, TABLE COLLAPSES BECAUSE OF JOHN CENA !!!" << std::endl;
      abort();
    }
  this->_slots[i] = obj;
}

Object *TablePePeNoel::getObject(int i) const
{
  if (i < 0 || i >= 10)
    return (NULL);
  return (this->_slots[i]);
}

int findIt(TablePePeNoel *table, int type)
{
  int i = 0;

  while (i < 10)
    {
      if (table->getObject(i) && table->getObject(i)->getType() == type)
	break ;
      i++;
    }
  if (table->getObject(i) == NULL)
    {
      std::cout << "pepe ya un schmolle dans le bignou" << std::endl;
      return (-1);
    }
  return (i);
}

Object *TablePePeNoel::takeObject()
{
  Object *tmp;
  int i = 0;

  if ((i = findIt(this, TYPE_PAPERGIFT)) == -1)
    return (NULL);
  this->_slots[i] = NULL;
  if ((i = findIt(this, TYPE_BOX)) == -1)
    return (NULL);
  this->_slots[i] = NULL;
  if ((i = findIt(this, TYPE_TOY)) == -1)
    return (NULL);
  tmp = this->_slots[i];
  this->_slots[i]->isTaken();
  this->_slots[i] = NULL;
  return (tmp);
}

std::ostream &operator<<(std::ostream &os, ITable *t)
{
  int i = 0;

  os << "TABLE:" << std::endl;
  while (i < 10)
    {
      if (t->getObject(i))
	std::cout << "\t[" << t->getObject(i)->getName() << "]" << std::endl;
      else
	std::cout << "\t[FREE]" << std::endl;
      i++;
    }
  return (os);
}
