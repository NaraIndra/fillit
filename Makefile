NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRC = flt/tx_functions.c flt/cover_functions.c flt/utility_functions.c flt/print_functions.c flt/connection_functions.c flt/get_figure_functions.c flt/create_matrix_functions.c flt/enlarge_map_functions.c flt/extrapolate_functions.c flt/extrapolate_utility_functions.c flt/main.c flt/print_utility_functions.c
OBJ = tx_functions.o cover_functions.o utility_functions.o print_functions.o connection_functions.o get_figure_functions.o create_matrix_functions.o enlarge_map_functions.o extrapolate_functions.o extrapolate_utility_functions.o main.o print_utility_functions.o

all: $(NAME)

%.o : flt/%.c
	@gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	@make -C libft
	gcc -I flt -L./libft -lft $(SRC) -o $(NAME) $(FLAGS)

clean:
	@make clean -C libft
	/bin/rm -f *.o

fclean: clean
	@make fclean -C libft
	/bin/rm -f $(NAME)

re: clean all
	@make re -C libft
