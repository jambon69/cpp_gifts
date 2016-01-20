#ifndef TABLEPERENOEL_HH_
# define TABLEPERENOEL_HH_

#include <iostream>
#include "ITable.hh"

class TablePePeNoel : public ITable
{
public:
  TablePePeNoel();
  TablePePeNoel(const TablePePeNoel &);
  TablePePeNoel &operator=(const TablePePeNoel &);
  virtual ~TablePePeNoel();
  virtual std::string **Look();
  virtual void addNewObject(Object *);
  virtual Object *getObject(int) const;
  virtual Object *takeObject();
  virtual bool isEmpty() const;

private:
  Object *_slots[11];
};

std::ostream &operator<<(std::ostream &, ITable *);

#endif /* !TABLEPERENOEL_HH_ */
