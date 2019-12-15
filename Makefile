# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 11:06:06 by ehafidi           #+#    #+#              #
#    Updated: 2019/12/10 15:40:45 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -c
LIBFT_PATH = ./libft
LDFLAGS = -L. -lftprintf
INCFLAGS = -I$(LIBFT_ROOT)

SRCS = ft_printf.c \

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