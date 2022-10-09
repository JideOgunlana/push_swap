NAME = push_swap
BONUS_NAME = checker
PUSH_SWAP = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

# LIBFT_OBJ = ./includes/libft/libft.a

UTILS_SRC =	utils/chunk_algo utils/chunks_to_a_helper utils/chunks_to_a utils/chunks_to_b_helper utils/chunks_to_b \
			utils/create_queue utils/create_stack utils/error_checkers utils/move_to_a_helper utils/move_to_a \
			utils/move_to_b_helper1 utils/move_to_b_helper2 utils/move_to_b utils/parse_args_for_a utils/parse_total_chunks_a \
			utils/sort_check utils/sort_insertion_algo utils/sort_random_num utils/stack_utils \
			utils/stack_a_b_ops utils/stack_a_ops utils/stack_b_ops utils/push_swap

MAIN_SRC	= main

BONUS_SRC	= bonus/checker bonus/checker_utils


UTILS = ./$(addsuffix .c, $(UTILS_SRC))
MAIN = ./$(addsuffix .c, $(MAIN_SRC))
BONUS = ./$(addsuffix .c, $(BONUS_SRC))


UTILS_OBJS = ./$(addsuffix .o, $(UTILS_SRC))
MAIN_OBJ = ./$(addsuffix .o, $(MAIN_SRC))
BONUS_OBJ = ./$(addsuffix .o, $(BONUS_SRC))

all: lib $(NAME)

.c.o: $(MAIN) $(UTILS)
	$(CC) $(CFLAGS) -c -o $@ $<

lib:
	@$(MAKE) bonus -C ./includes/libft/


$(NAME): $(MAIN_OBJ) $(UTILS_OBJS) lib bonus
	@cp ./includes/libft/libft.a ./utils/
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(UTILS_OBJS) ./utils/libft.a -o $(NAME)

clean:
	@make fclean -C ./includes/libft
	$(RM) $(UTILS_OBJS) $(MAIN_OBJ) $(BONUS_OBJ) $(PUSH_SWAP)

fclean: clean
	@/bin/rm -f ./utils/libft.a
	$(RM) $(NAME) bonus/$(BONUS_NAME)

bonus: lib $(BONUS_OBJ) $(UTILS_OBJS)
	@cp ./includes/libft/libft.a ./utils/
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(UTILS_OBJS) ./utils/libft.a ./includes/gnl/get_next_line.c ./includes/gnl/get_next_line_utils.c -o bonus/$(BONUS_NAME)

re: fclean all

.PHONY: clean fclean re libft all bonus