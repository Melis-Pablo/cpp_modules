# General Setup
NAME = DiamondTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-Wshadow -Wno-shadow
RM = rm -rf

# Files
FILES = main ClapTrap ScavTrap FlagTrap DiamondTrap
HEADERS = ClapTrap.hpp ScavTrap.hpp FlagTrap.hpp DiamondTrap.hpp
SRCS = $(FILES:=.cpp)
OBJDIR = .objs
OBJS = $(addprefix $(OBJDIR)/, $(FILES:=.o))

# Colors
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
ORANGE		=	\e[33;5;202m
RED			=	\e[31;5;196m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN) $(NAME) $(RESET) has been created.\n"

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "$(YELLOW) Compiling: $(RESET) $< \n"

clean:
	@$(RM) $(OBJDIR)
	@printf "$(ORANGE) $(NAME) $(RESET) object files have been removed. \n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED) $(NAME) $(RESET) has been removed. \n"

re: fclean all

cleanly: all clean

.PHONY: all clean fclean re cleanly
