#ifndef GIFTPAPER_HH_
# define GIFTPAPER_HH_

#include <string>
#include "Wrap.hh"

class	GiftPaper: public Wrap
{
public:
  GiftPaper(std::string name = "GiftPaper", Type type = TYPE_PAPERGIFT);
  GiftPaper(GiftPaper const &g);
  virtual ~GiftPaper() {}
  GiftPaper		&operator=(GiftPaper const &g);
  virtual Box		*openMe();
  virtual const std::string getName() const;
};

#endif /* !GIFTPAPER_HH_ */
