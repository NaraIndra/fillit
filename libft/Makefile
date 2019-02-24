NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRC1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
SRC2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC3 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 
SRC4 = ft_del.c ft_lstappend.c ft_islower.c ft_isupper.c ft_freearray.c ft_strrealloc.c ft_sortshell.c ft_swap.c ft_sortbubble.c ft_iswhitespace.c ft_bitsprint.c ft_bitsnbr.c ft_sortinsertion.c ft_sortquick.c ft_strreverse.c ft_itoaws.c ft_putcharn.c ft_digitsnbr.c ft_putstrw.c ft_max.c 
TREE = ft_tree_del.c ft_tree_delone.c ft_tree_new.c ft_tree_search.c ft_tree_find_parent.c
BST = ft_tree_bst_new.c ft_tree_bst_print.c ft_tree_bst_insert.c
AVL = ft_tree_avl_new.c ft_tree_avl_insert.c ft_tree_avl_print.c ft_tree_avl_getbalance.c ft_tree_avl_getheight.c ft_tree_avl_rotate_right.c ft_tree_avl_rotate_left.c ft_tree_avl_delone.c
GNL = ft_get_next_line.c

all: $(NAME)

$(NAME):
	@gcc $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(TREE) $(BST) $(AVL) $(GNL) -c $(FLAGS)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all