//
// Box.hh for  in /home/louis/github_repo/cpp_gifts
//
// Made by louis giesen
// Login   <louis@epitech.net>
//
// Started on  Wed Jan 20 09:32:24 2016 louis giesen
// Last update Wed Jan 20 09:32:24 2016 louis giesen
//

#ifndef BOX_HH_
# define BOX_HH_

# include <string>
# include "Object.hh"
# include "Wrap.hh"

class	Box: public Wrap
{
public:
  Box(std::string name = "Box", int type = TYPE_BOX);
  Box(Box const &b);
  virtual ~Box() {}
  Box	&operator=(Box const &g);
  void			closeMe();
  virtual Object	*openMe();
  virtual const std::string	getName() const;
};

#endif /* BOX_HH_ */
