# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 11:06:06 by ehafidi           #+#    #+#              #
#    Updated: 2020/02/07 15:44:24 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_ROOT = ./libft

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L. -lftprintf
INCFLAGS = -I$(LIBFT_ROOT)

RM = rm -f
LIB = ar rcs
MAKE = make

NAME = libftprintf.a

SRC = ft_printf.c ft_output_c.c ft_output_d_i.c ft_output_p.c ft_output_s.c ft_output_%.c ft_output_u.c ft_output_x.c ft_output_XX.c ft_parse.c ft_side_functions.c 
	  
OBJ = $(SRC:.c=.o)
INCLUDE = header.h


all: libft_all $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_ROOT)/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

bonus: all

clean: libft_clean
	$(RM) $(OBJ)

fclean: libft_fclean clean
	$(RM) $(NAME)

re: fclean all

test: CCFLAGS += -g
test: all
	$(CC) $(CCFLAGS) $(LDFLAGS) -L./libft -lft $(INCFLAGS) -o test main.c


libft_all:
	$(MAKE) -C $(LIBFT_ROOT) all

libft_bonus:
	$(MAKE) -C $(LIBFT_ROOT) bonus

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_ROOT) fclean