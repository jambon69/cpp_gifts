#include <string>
#include "LittlePony.hh"
#include "Teddy.hh"
#include <cstdlib>
#include <time.h>
#include "ElfOfPePeNoel.hh"

ElfOfPePeNoel::ElfOfPePeNoel(std::string const & name)
  : _name(name)
{
  this->_table = NULL;
  this->_conveyorBelt = NULL;
  this->_box = NULL;
  this->_gp = NULL;
}

ElfOfPePeNoel::ElfOfPePeNoel(ElfOfPePeNoel const &e)
  : _name(e._name)
{
}

ElfOfPePeNoel::~ElfOfPePeNoel()
{
  delete this->_table;
  delete this->_conveyorBelt;
  delete this->_box;
  delete this->_gp;
}

std::string const ElfOfPePeNoel::getName() const
{
  return (this->_name);
}

void ElfOfPePeNoel::closeMe()
{
  if (this->_box)
    this->_box->closeMe();
}

Object *ElfOfPePeNoel::openMe()
{
  Object *tmp;

  if (this->_gp)
    {
      tmp = this->_gp->openMe();
      delete this->_gp;
      this->_gp = NULL;
    }
  else if (this->_box)
    {
      tmp = this->_box->openMe();
      delete this->_box;
      this->_box = NULL;
    }
  return (tmp);
}

void ElfOfPePeNoel::wrapsBox()
{
  if (this->_conveyorBelt->Look() && this->_box)
    {
      std::cout << "tuuuut tuuut tuut" << std::endl;
      this->_box->wrapMeThat(true, this->_conveyorBelt->Look(), this->_box);
    }
  else
    {
      if (!this->_conveyorBelt->Look())
	std::cerr << "Missing toy on the convoyer belt" << std::endl;
      else
	std::cerr << "Missing Box, please push button in" << std::endl;
    }
}

void ElfOfPePeNoel::wrapsPaperGift()
{
  if (this->_conveyorBelt->Look() && this->_gp && this->_box)
    {
      std::cout << "tuuuut tuuut tuut" << std::endl;
      this->_gp->wrapMeThat(false, this->_conveyorBelt->Look(), this->_box);
    }
  else
    {
      if (!this->_conveyorBelt->Look())
	std::cerr << "Missing toy on the convoyer belt" << std::endl;
      else if (!this->_box)
	std::cerr << "Missing Box, please push button in" << std::endl;
      else
	std::cerr << "Missing Paper Gift, please push button in" << std::endl;
    }
}

void ElfOfPePeNoel::pushButtonIn()
{
  this->_box = this->_conveyorBelt->buttonInBox();
  this->_box->isTaken();
  this->_gp = this->_conveyorBelt->buttonInPaper();
}

void ElfOfPePeNoel::pushButtonOut()
{
  this->_conveyorBelt->buttonOut();
  delete this->_box;
  delete this->_gp;
  this->_box = NULL;
  this->_gp = NULL;
}

bool ElfOfPePeNoel::putNewObjectOnBelt()
{
  Object *tmp;

  if ((tmp = this->_table->takeObject()) == NULL)
    return (false);
  this->_conveyorBelt->setObject(tmp);
  return (true);
}

ITable *ElfOfPePeNoel::getTable() const
{
  return this->_table;
}

IConveyorBelt *ElfOfPePeNoel::getBelt() const
{
  return this->_conveyorBelt;
}

ITable *ElfOfPePeNoel::createTable()
{
  delete this->_table;
  this->_table = new TablePePeNoel();
  return (this->_table);
}

ITable *ElfOfPePeNoel::createRandomTable()
{
  int i = 0;
  int rands;
  int rands2;
  std::string randTab[30] = {"Carbon", "Eucalyptus", "Viagra", "SexToy",
			   "Mere Noel", "Calvin Klein", "Jon Cena",
			   "Grenouille", "Action Man", "ConstPilateur",
			   "PaperGift", "PaperGift", "PaperGift", "PaperGift",
			   "PaperGift", "PaperGift", "PaperGift", "PaperGift",
			   "PaperGift", "PaperGift", "Box", "Box", "Box", "Box",
			     "Box", "Box", "Box", "Box", "Box", "Box"};

  srand(time(NULL));
  this->_table = new TablePePeNoel();
  while (i < 10)
    {
      rands = rand() % 29;
      rands2 = rand() % 2;
      if (randTab[rands] == "Box")
	this->_table->addNewObject(new Box());
      else if (randTab[rands] == "PaperGift")
	this->_table->addNewObject(new GiftPaper());
      else if (rands2 == 0)
	this->_table->addNewObject(new LittlePony(randTab[rands]));
      else if (rands2 == 1)
	this->_table->addNewObject(new Teddy(randTab[rands]));
      i++;
    }
  return (this->_table);
}

IConveyorBelt *ElfOfPePeNoel::createConveyorBelt()
{
  delete this->_conveyorBelt;
  this->_conveyorBelt = new ConveyorBelt();
  return (this->_conveyorBelt);
}

void ElfOfPePeNoel::run()
{
  this->createRandomTable();
  this->createConveyorBelt();
  std::cout << "-----------TABLE----------" << std::endl;
  std::cout << this->getTable() << std::endl;
  std::cout << "--------------------------" << std::endl;
  while (this->putNewObjectOnBelt())
    {
      std::cout << this->getTable();
      std::cout << this->getBelt();
      this->pushButtonIn();
      this->wrapsBox();
      this->wrapsPaperGift();
      this->pushButtonOut();
      std::cout << "--------------------------" << std::endl;
    }
}
