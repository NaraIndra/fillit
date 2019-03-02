NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRC = tx_functions.c cover_functions.c utility_functions.c print_functions.c connection_functions.c get_figure_functions.c create_matrix_functions.c enlarge_map_functions.c extrapolate_functions.c extrapolate_utility_functions.c main.c print_utility_functions.c almost_useless_func.c sq_root_func.c
OBJ = tx_functions.o cover_functions.o utility_functions.o print_functions.o connection_functions.o get_figure_functions.o create_matrix_functions.o enlarge_map_functions.o extrapolate_functions.o extrapolate_utility_functions.o main.o print_utility_functions.o almost_useless_func.o sq_root_func.o
LIB = libft.a
all: $(NAME)

$(NAME): $(LIB) $(OBJ) 
	gcc -L ../libft -lft $(OBJ) -o $(NAME) $(FLAGS)

$(LIB):
	make -C ../libft

%.o : %.c
	gcc -c -o $@ $< $(FLAGS) -g

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: clean all
	@make re -C libft