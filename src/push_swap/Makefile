NAME = ../../push_swap

SRC = \
		push_swap.c \
		ft_sort.c \
		../ft_stack.c \
		../ft_comm.c \
		../ft_is_arg_valid.c \
		../ft_pair_stack.c \
		../ft_is_sorted.c \
		../ft_comm_go.c \
		../ft_comm2.c \
		../ft_stack2.c \
		ft_sort_helper2.c \
		sort_helper.c \
		ft_sort_helper3.c
OBJ = $(SRC:.c=.o)
INC1 = ../../inc
INC2 = ../../libft
CC = gcc
FLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) -I $(INC2) -L ../../libft/ -lft $(OBJ) ../../ft_printf/libftprintf.a

%.o: src/%.c
	@$(CC) $(FLAGS) -I $(INC1) -o $@ -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
