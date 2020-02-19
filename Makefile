# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 15:41:44 by ehafidi           #+#    #+#              #
#    Updated: 2020/02/19 17:18:35 by ehafidi          ###   ########.fr        #
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
SRC = ft_output_c.c \
			ft_output_s_2.c \
			ft_output_xx_2.c \
			ft_side_functions_3.c \
			ft_output_d_i.c \
			ft_output_u.c \
			ft_parse.c \
			ft_output_d_i_2.c \
			ft_output_u_2.c \
			ft_printf.c \
			ft_output_p.c \
			ft_output_x.c \
			ft_side_functions_0.c \
			ft_output_percent.c \
			ft_output_x_2.c \
			ft_side_functions_1.c \
			ft_output_s.c \
			ft_output_xx.c \
			ft_side_functions_2.c

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