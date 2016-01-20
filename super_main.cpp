//
// super_main.cpp for sdkjfh in /home/louis/rendu/piscine_cpp/cpp_santa
//
// Made by louis giesen
// Login   <louis@epitech.net>
//
// Started on  Sat Jan 16 19:33:34 2016 louis giesen
// Last update Sun Jan 17 00:19:04 2016 louis giesen
//

#include <cstdlib>
#include <limits>
#include "ElfOfPePeNoel.hh"
#include <iostream>
#include "Teddy.hh"
#include "LittlePony.hh"
#include "TablePePeNoel.hh"
#include "Box.hh"
#include "Test.hh"
#include "GiftPaper.hh"

int main()
{
  std::string response;
  int i = 0;
  std::string ignoreLine;
  ElfOfPePeNoel jeanMichel("Jean Michel");

  std::cout << "Vous êtes Jean Michel, elfe de John Santa (tutudutuuuuuu)" << std::endl;
  std::cout << "Voulez-vous une table aléatoire ? O/N" << std::endl;
  std::cin >> response;
  std::cin.clear();
  std::getline(std::cin, ignoreLine);
  if (response == "O")
    {
      jeanMichel.createRandomTable();
      jeanMichel.createConveyorBelt();
      i = 10;
    }
  else
    {
      std::cout << "La table derrière vous est vide pour le moment. Nous allons la remplir ensemble !" << std::endl;
      jeanMichel.createTable();
      jeanMichel.createConveyorBelt();
    }
  while (i++ < 7)
    {
      std::cout << "Voulez vous y ajouter un Poney ? O/N" << std::endl;
      std::cin >> response;
      std::cin.clear();
      std::getline(std::cin, ignoreLine);
      if (response == "O")
	{
	  std::cout << "Choisissez son nom: ";
	  std::cin >> response;
	  std::cin.clear();
	  std::getline(std::cin, ignoreLine);
	  jeanMichel.getTable()->addNewObject(new LittlePony(response));
	  jeanMichel.getTable()->addNewObject(new GiftPaper());
	  jeanMichel.getTable()->addNewObject(new Box());
	  i++;
	}
      if (i == 3)
	break ;
      std::cout << "Voulez vous y ajouter un Teddy Bear ? O/N" << std::endl;
      std::cin >> response;
      std::cin.clear();
      std::getline(std::cin, ignoreLine);
      if (response == "O")
	{
	  std::cout << "Choisissez son nom: ";
	  std::cin >> response;
	  std::cin.clear();
	  std::getline(std::cin, ignoreLine);
	  jeanMichel.getTable()->addNewObject(new Teddy(response));
	  jeanMichel.getTable()->addNewObject(new GiftPaper());
	  jeanMichel.getTable()->addNewObject(new Box());
	  i++;
	}
      std::cout << "Voulez vous continuer à ajouter des éléments sur la table ? O/N" << std::endl;
      std::cin >> response;
      std::cin.clear();
      std::getline(std::cin, ignoreLine);
      if (response == "N")
	break ;
    }
  std::cout << "Voici votre table : " << std::endl;
  std::cout << jeanMichel.getTable();
  std::cout << "----------------------" << std::endl;
  while (jeanMichel.putNewObjectOnBelt())
    {
      std::cout << jeanMichel.getTable();
      std::cout << jeanMichel.getBelt();
      std::cout << "OH Un gros bouton avec écrit in, j'appuye dessus !" << std::endl;
      jeanMichel.pushButtonIn();
      jeanMichel.wrapsBox();
      jeanMichel.wrapsPaperGift();
      jeanMichel.pushButtonOut();
      std::cout << "----------------------" << std::endl;
      std::cout << "Voulez-vous continuer à travailler ? O/N" << std::endl;
      std::cin >> response;
      std::cin.clear();
      std::getline(std::cin, ignoreLine);
      if (response == "N")
	{
	  std::cout << "Un peu fatigué aujourd'hui ?" << std::endl;
	  break;
	}
    }
  std::cout << "C'est la fin de la journée, vous pouvez rentrer chez vous !" << std::endl;
  return (0);
}
