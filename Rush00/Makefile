RED = \033[0;31m
NC = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m

NAME = ft_retro

SRCSDIR = srcs

INCLUDES = includes

FLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix $(SRCSDIR)/,\
			Bullet.cpp BulletList.cpp Enemy.cpp EnemyList.cpp Logic.cpp main.cpp \
			Player.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(OBJS): %.o: %.cpp
	@echo "${YELLOW}Preparing Objects... Please wait${NC}"
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) -I$(INCLUDES) -lncurses $(OBJS) -o $(NAME)
	@echo "${GREEN}Program:" $(NAME) "is ready!${NC}"

clean:
	@echo "${YELLOW}Cleanning objects...${NC}"
	@rm -f $(OBJS)
	@echo "${GREEN}DONE!${NC}"

fclean: clean
	@echo "${YELLOW}Cleanning Program...${NC}"
	@rm -f $(NAME)
	@echo "${GREEN}DONE!${NC}"

re: fclean all
