#include <string>
#include "Object.hh"
#include "Teddy.hh"
#include "LittlePony.hh"
#include "Wrap.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include <iostream>

Object		**MyUnitTests()
{
  Object	**tab = new Object*[2];

  tab[0] = new Teddy("Ctionnaire");
  tab[1] = new LittlePony("Po");
  return (tab);
}

Object		*MyUnitTests(Object **tab)
{
  dynamic_cast<Box*>(tab[1])->wrapMeThat(1, tab[0], NULL);
  dynamic_cast<GiftPaper*>(tab[2])->wrapMeThat(0, NULL, dynamic_cast<Box*>(tab[1]));
  return (tab[2]);
}

int		main()
{
  std::string	expected_str;
  std::string	output_str;
  int		expected_type;
  int		output_type;
  std::cout << std::endl << "===Test tab start===" << std::endl << std::endl;
  Object	**tabe;
  tabe = MyUnitTests();
  for (int i = 0; i < 2; ++i)
    std::cout << tabe[i]->getName() << std::endl;
  for (int i = 0; i < 2; ++i)
    delete (tabe[i]);
  delete [] (tabe);
  std::cout << std::endl << "===Test tab end===" << std::endl << std::endl;
  std::cout << std::endl << "===Test creation of a gift===" << std::endl << std::endl;
  Object        **tab = new Object*[4];

  tab[3] = NULL;
  tab[0] = new Teddy("Ota");
  expected_type = tab[0]->getType();
  expected_str = tab[0]->getName();
  std::cout << "Name of the toy (and output expected) : " << std::endl
	    << "Type : " << ((expected_type == TYPE_TOY) ? "Toy" : "Unknown")
	    << " Name : " << expected_str << std::endl;
  tab[1] = new Box();
  tab[2] = new GiftPaper();
  Object	*gift;
  gift = MyUnitTests(tab);
  Box		*b;
  b = dynamic_cast<GiftPaper*>(gift)->openMe();
  Object	*toy;
  toy = b->openMe();
  output_type = toy->getType();
  output_str = toy->getName();
  std::cout << "The gift contain : " << std::endl
	    << "Type : " << ((output_type == TYPE_TOY) ? "Toy" : "Unknown")
	    << " Name : " << output_str << std::endl;
  if (expected_str == output_str && expected_type == output_type)
    std::cout << "OMG ! It's the same !!! We've got a "
	      << ((output_type == TYPE_TOY) ? "Toy" : "Unknown")
	      << expected_str << " !!!" << std::endl;
  else
    std::cout << "WTF ! How it's possible ! Explain me that sh*t !"
	      << " Are you John Cena ?!" << std::endl;
  std::cout << std::endl << "===End of the creation gift test===" << std::endl;
}
