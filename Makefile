##
## Makefile for djkfh in /home/louis/rendu/piscine_cpp/cpp_santa
## 
## Made by louis giesen
## Login   <louis@epitech.net>
## 
## Started on  Sat Jan 16 19:51:47 2016 louis giesen
## Last update Sun Jan 17 00:35:24 2016 louis giesen
##

SRCS_TEST =	Box.cpp			\
		ConveyorBelt.cpp	\
		ElfOfPePeNoel.cpp	\
		GiftPaper.cpp		\
		LittlePony.cpp		\
		Test.cpp		\
		TablePePeNoel.cpp	\
		Teddy.cpp		\
		Toy.cpp			\
		Wrap.cpp	

SRCS_SWAG =	Box.cpp			\
		ConveyorBelt.cpp	\
		ElfOfPePeNoel.cpp	\
		GiftPaper.cpp		\
		LittlePony.cpp		\
		swag_main.cpp		\
		TablePePeNoel.cpp	\
		Teddy.cpp		\
		Toy.cpp			\
		Wrap.cpp		\

SRCS =	Box.cpp			\
	ConveyorBelt.cpp	\
	ElfOfPePeNoel.cpp	\
	GiftPaper.cpp		\
	LittlePony.cpp		\
	super_main.cpp		\
	TablePePeNoel.cpp	\
	Teddy.cpp		\
	Toy.cpp			\
	Wrap.cpp		\

OBJS =	$(SRCS:.cpp=.o)

OBJS_TEST = $(SRCS_TEST:.cpp=.o)

OBJS_SWAG = $(SRCS_SWAG:.cpp=.o)

NAME =	jeanmichel

NAME_TEST = jeanmicheltest

NAME_SWAG = jeanmichelswag

CPPFLAGS = -W -Wall -Wextra -Werror
CPPFLAGS += -I./

CC = g++

RM = rm -rf

all: $(NAME)

test: $(NAME_TEST)

swag: $(NAME_SWAG)

$(NAME_SWAG): $(OBJS_SWAG)
	$(CC) -o $(NAME_SWAG) $(OBJS_SWAG)

$(NAME_TEST): $(OBJS_TEST)
	$(CC) -o $(NAME_TEST) $(OBJS_TEST)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	$(RM) $(OBJS) && $(RM) $(OBJS_TEST) $(OBJS_SWAG)

fclean: clean
	$(RM) $(NAME) $(NAME_TEST) $(NAME_SWAG)

re: fclean all

coffee	:
		@echo "             (((("
		@echo "            (((("
		@echo "             ))))"
		@echo "          _ .---."
		@echo "         ( |\`---'|"
		@echo "          \| SWAG|"
		@echo "          : .___, :"
		@echo "           \`-----'"

.PHONY: all clean fclean re
