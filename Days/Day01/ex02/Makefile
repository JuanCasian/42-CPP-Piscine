# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcasian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 16:42:47 by jcasian           #+#    #+#              #
#    Updated: 2019/01/21 19:53:57 by jcasian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#colors
RED = \033[0;31m
NC = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m

# program name
NAME = zombie_event

# Compilationn flags
FLAGS = -Wall -Werror -Wextra

# Directories
SRCSDIR = .

# Sources
SRCS = $(addprefix $(SRCSDIR)/,\
	   main.cpp Zombie.cpp ZombieEvent.cpp)

# Objects
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(OBJS): %.o: %.cpp
	@echo "${YELLOW}Preparing Objects... Please wait${NC}"
	@clang $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN}Program: ${NAME} is ready!${NC}"

clean:
	@echo "${YELLOW}Cleanning objects...${NC}"
	@rm -f $(OBJS)
	@echo "${GREEN}DONE!${NC}"

fclean: clean
	@echo "${YELLOW}Cleanning Program...${NC}"
	@rm -f $(NAME)
	@echo "${GREEN}DONE!${NC}"

re: fclean $(NAME)
