NAME = ex02
FLAGS = -Wall -Werror -Wextra
SRCSDIR = .

SRCS = $(addprefix $(SRCSDIR)/,\
		AssaultTerminator.cpp Squad.cpp TacticalMarine.cpp main.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(OBJS): %.o: %.cpp
	@clang++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)