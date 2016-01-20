#ifndef WRAP_HH_
# define WRAP_HH_

# include <string>
# include "Object.hh"
// # include "Box.hh"

enum {BOX, PAPERGIFT};

class Box;

class		Wrap: public Object
{
protected :
  std::string const	_name;
  int			_type;
  Object		*_toy;
  Box			*_box;
  bool			_isOpen;
public:
  Wrap(std::string const name = "Wrap", int type = TYPE_WRAP);
  Wrap(const Wrap &);
  virtual ~Wrap() {}
  Wrap&				operator=(Wrap const &w);
  virtual bool			wrapMeThat(bool, Object *, Box *);
  virtual std::string const	getName() const = 0;
  virtual int			getType() const;
  virtual void			isTaken() const;
  virtual Object		*getToy() const;
  virtual Box			*getBox() const;
  virtual bool			getIsOpen() const;
};

#endif /* !WRAP_HH_ */
