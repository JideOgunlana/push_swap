# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:42:02 by ssergiu           #+#    #+#              #
#    Updated: 2023/06/07 05:41:04 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

MANDATORY_FILES = 	ft_strlen \
					ft_atoi \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_memchr \
					ft_memcmp \
					ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strlcpy \
					ft_strlcat \
					ft_strnstr \
					ft_strncmp \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_itoa \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_strmapi \
					ft_striteri \
					ft_split \
					ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(MANDATORY_FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MANDATORY_FILES)))

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $@ $^

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
