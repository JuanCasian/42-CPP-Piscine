NAME = ex03
FLAGS = -Wall -Werror -Wextra
SRCSDIR = .

SRCS = $(addprefix $(SRCSDIR)/,\
	   AForm.cpp Bureaucrat.cpp main.cpp ShrubberyCreationForm.cpp\
	   RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp)

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
	@rm -f *_shrubbery

re: fclean $(NAME)