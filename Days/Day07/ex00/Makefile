NAME = ex00
FLAGS = -Wall -Werror -Wextra
SRCSDIR = .

SRCS = $(addprefix $(SRCSDIR)/,\
	   whatever.cpp)

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