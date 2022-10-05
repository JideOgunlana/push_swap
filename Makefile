NAME = push_swap
PUSH_SWAP = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

# LIBFT_OBJ = ./includes/libft/libft.a

UTILS_SRC =	utils/create_queue utils/create_stack utils/error_checkers \
			utils/stack_a_b_ops utils/stack_a_operations \
			utils/stack_utils utils/stack_b_operations \
			utils/sort_moves_to_a utils/sort_moves_to_b utils/sort_random_num \
			utils/sort_push_algo utils/chunk_algo utils/sort_to_a_helper

MAIN_SRC	= push_swap


UTILS = ./$(addsuffix .c, $(UTILS_SRC))
MAIN = ./$(addsuffix .c, $(MAIN_SRC))

UTILS_OBJS = ./$(addsuffix .o, $(UTILS_SRC))
MAIN_OBJ = ./$(addsuffix .o, $(MAIN_SRC))

all: lib $(NAME)

.c.o: $(MAIN) $(UTILS)
	$(CC) $(CFLAGS) -c -o $@ $<

lib:
	@$(MAKE) bonus -C ./includes/libft/

$(NAME): $(MAIN_OBJ) $(UTILS_OBJS) lib 
	@cp ./includes/libft/libft.a ./utils/
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(UTILS_OBJS) ./utils/libft.a -o $(NAME)

clean:
	@make fclean -C ./includes/libft
	$(RM) $(UTILS_OBJS) $(MAIN_OBJ) $(PUSH_SWAP)

fclean: clean
	@/bin/rm -f ./utils/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re libft all