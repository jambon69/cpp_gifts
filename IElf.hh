#ifndef IELF_HH_
# define IELF_HH_

# include "Box.hh"
# include <string>

class IElf
{
public:
  virtual ~IElf() {}
  virtual void wrapsBox() = 0;
  virtual void wrapsPaperGift() = 0;
  virtual void pushButtonOut() = 0;
  virtual void pushButtonIn() = 0;
  virtual std::string const getName() const = 0;
  virtual ITable *getTable() const = 0;
  virtual IConveyorBelt *getBelt() const = 0;
  virtual ITable * createTable() = 0;
  virtual IConveyorBelt *createConveyorBelt() = 0;
  virtual bool putNewObjectOnBelt() = 0;
  virtual void closeMe() = 0;
  virtual Object *openMe() = 0;
  virtual ITable *createRandomTable() = 0;
  virtual void run() = 0;
};

#endif /* !IELF_HH_ */
