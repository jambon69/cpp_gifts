#ifndef ELFOFPEPENOEL_HH_
# define ELFOFPEPENOEL_HH_

# include "GiftPaper.hh"
# include "Box.hh"
# include "TablePePeNoel.hh"
# include "ConveyorBelt.hh"
# include "IElf.hh"

class ElfOfPePeNoel : public IElf
{
private:
  std::string const _name;
  TablePePeNoel *_table;
  ConveyorBelt *_conveyorBelt;
  Box *_box;
  GiftPaper *_gp;

public:
  ElfOfPePeNoel(std::string const & = "Jean Michel ParDefaut");
  ElfOfPePeNoel(ElfOfPePeNoel const &);
  virtual ~ElfOfPePeNoel();

  virtual void pushButtonIn();
  virtual std::string const getName() const;
  virtual void pushButtonOut();
  virtual void wrapsBox();
  virtual void wrapsPaperGift();
  virtual bool putNewObjectOnBelt();
  virtual ITable *getTable() const;
  virtual ITable *createRandomTable();
  virtual IConveyorBelt *getBelt() const;
  virtual ITable * createTable();
  virtual IConveyorBelt *createConveyorBelt();
  virtual void closeMe();
  virtual Object *openMe();
  virtual void run();
};

#endif /* !ELFOFPEPENOEL_HH_ */
