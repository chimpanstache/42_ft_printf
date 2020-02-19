# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 15:41:44 by ehafidi           #+#    #+#              #
#    Updated: 2020/02/19 16:59:33 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = temporary

SOURCES = ft_output_c.c \
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

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAG) -o $@  -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all