NAME = push_swap
PUSH_SWAP = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

LIBFT_OBJ = ../libft/libft.a

UTILS_SRC =	utils/create_queue utils/create_stack utils/error_checkers \
			utils/stack_a_b_ops utils/stack_a_operations \
			utils/stack_a_b_ops utils/stack_utils utils/stack_b_operations

MAIN_SRC	= push_swap


UTILS = ./$(addsuffix .c, $(UTILS_SRC))
MAIN = ./$(addsuffix .c, $(MAIN_SRC))

UTILS_OBJS = ./$(addsuffix .o, $(UTILS_SRC))
MAIN_OBJ = ./$(addsuffix .o, $(MAIN_SRC))

$(NAME): $(PUSH_SWAP)
	$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT_OBJ) -o $(NAME)

.c.o: $(MAIN) $(UTILS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PUSH_SWAP):$(MAIN_OBJ) $(UTILS_OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(UTILS_OBJS) $(MAIN_OBJ) $(PUSH_SWAP)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean re libft all