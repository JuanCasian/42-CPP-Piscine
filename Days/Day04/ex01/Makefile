NAME = ex01
FLAGS = -Wall -Werror -Wextra
SRCSDIR = .

SRCS = $(addprefix $(SRCSDIR)/,\
		AWeapon.cpp Character.cpp Enemy.cpp PlasmaRifle.cpp PowerFist.cpp\
		RadScorpion.cpp SuperMutant.cpp main.cpp)

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