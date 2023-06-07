NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

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
	@$(CC) $(CFLAGS) -c -o $@ $<

lib:
	@$(MAKE) -C ./includes/libft/

$(NAME): $(MAIN_OBJ) $(UTILS_OBJS) $(BONUS_OBJ)
	@cp ./includes/libft/libft.a ./
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(UTILS_OBJS) ./libft.a -o $(NAME)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(UTILS_OBJS) ./libft.a ./includes/gnl/get_next_line.c ./includes/gnl/get_next_line_utils.c -o bonus/$(BONUS_NAME)
	@printf "$(NAME) \033[1;32mCOMPILED\n"

clean:
	@make fclean -C ./includes/libft
	@$(RM) $(UTILS_OBJS) $(MAIN_OBJ) $(BONUS_OBJ)
	@printf "\033[1;33mCLEANED\e[0m\n"

fclean: clean
	@/bin/rm -f ./libft.a
	@$(RM) $(NAME) bonus/$(BONUS_NAME)
	@printf "\033[0;31mFULL CLEAN\e[0m\n"
bonus: all
	@printf "${BONUS_NAME} \033[1;32mBONUS COMPILED\n"

re: fclean all
	@echo REMAKING COMPLETED

.PHONY: clean fclean re libft all bonus
