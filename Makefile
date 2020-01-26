# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 11:06:06 by ehafidi           #+#    #+#              #
#    Updated: 2020/01/23 15:32:43 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -c
LIBFT_PATH = ./libft
LDFLAGS = -L. -lftprintf
INCFLAGS = -I$(LIBFT_ROOT)

SRCS = ft_printf.c ft_output_c.c ft_output_d_i.c ft_output_p.c ft_output_s.c \
ft_output_u.c ft_output_x.c ft_output_XX.c ft_parse.c ft_side_functions.c \

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: libft_all $(NAME)

$(NAME):	$(OBJS)
	cp $(LIBFT_PATH)/libft.a $(NAME) 
	ar rc $(NAME) $(OBJS)

%.o: %.c header.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

clean:	libft_clean
		$(RM) $(OBJS) 

fclean: libft_fclean clean
		$(RM) $(NAME) 

re: fclean all	

libft_all: make -C $(LIBFT_PATH) all 

libft_clean: make -C $(LIBFT_PATH) clean 

libft_fclean: make -C $(LIBFT_PATH) fclean 

.PHONY: all clean fclean re libft_all libft_clean libft_fclean 