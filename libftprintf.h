/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:41:29 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/14 19:33:51 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/*#define MINUS (1 << 0)
#define ZERO (1 << 1)
#define RANGE (1 << 2)
#define CHAMP (1 << 3)*/

typedef struct 	s_flags  ////////////tjs free la struc a la fin!!!!!!!!!!!!!!!!!!!!
{
	int att;
	int chmp;
	int prec;
}				s_flags;

//side functions
void	ft_putnbr_custom_pos(int n, char *src);
void	ft_putnbr_custom(int n, char *src);
void	ft_putchar(char c);
void	ft_putnbr_base(int n, char *base);
int		ft_strlen(char *base);
int		ft_atoi(const char *str);
int		ft_attribute(char str);
int		ft_champ(char *str, va_list *prms);
int 	ft_precision(char *str, va_list *prms);
int	countdigit_d_i_u(int nb);
void analyse_params(char *prmtrs, s_flags *flags, va_list *prms);
char	*ft_strndup(const char *str, size_t len);
void init_flags(s_flags *flags);
//d_i functions
void	printf_d_i(va_list *prms, s_flags flags);
char	*digit_overall(char *display, int digit, int nb, s_flags flags);
char	*prec_overall(char *display, int digit, int nb, s_flags flags);
char	*chmp_overall_thn_dgt(char *display, int digit, int nb, s_flags flags);
char	*chmp_overall_thn_prec(char *display, int digit, int nb, s_flags flags);

void 	printf_p(va_list *prms, s_flags flags);
void 	printf_u(va_list *prms, s_flags flags);
void 	printf_x(va_list *prms, s_flags flags);
void 	printf_X(va_list *prms, s_flags flags);
void 	printf_s(va_list *prms, s_flags flags);
void	printf_c(va_list *prms, s_flags flags);
void ft_write_char(char *src);
#endif
