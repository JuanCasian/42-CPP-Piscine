NAME = ft_retro
FLAGS = -Wall -Werror -Wextra
SRCSDIR = srcs
INCLUDES = includes

SRCS = $(addprefix $(SRCSDIR)/,\
		CanvasObj.cpp CanvasObjList.cpp EBullet.cpp Enemy.cpp FBullet.cpp\
		Logic.cpp Player.cpp Timer.cpp main.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(OBJS): %.o: %.cpp
	@clang++ $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) -I$(INCLUDES) -lncurses $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)