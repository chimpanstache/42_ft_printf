/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:41:29 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/11 21:58:43 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
//#include "libft.h"

typedef struct 	s_flags  
{
	int att;
	int chmp;
	int prec;
}				s_flags;

//side & parse functions
void	ft_putnbr_base(int n, char *base, char *str);
int		ft_strlen(char *base);
int		ft_atoi(const char *str);
char	*ft_strndup(const char *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);//*/
int		ft_attribute(char str);
int		ft_champ(char *str, va_list *prms);
int 	ft_precision(char *str, va_list *prms);
int	countdigit_d_i(int nb);
void analyse_params(char *prmtrs, s_flags *flags, va_list *prms);
void ft_case_percent(int a);
void init_flags(s_flags *flags);
void        ft_itoa_custom(int n, char *arr);
static int    count_no_diggity(int n);
void        ft_itoa_custom_pos(int n, char *arr);
int	ft_putnbr_base_p(unsigned long long nbr, char *base);
int	countdigit_base(unsigned long long nbr, char *base);
void        ft_ulltoa_base(unsigned long long n, char *arr, char *base);
void	ft_putnbr_custom(int n, char *src);
 void	ft_putnbr_custom_pos(int n, char *src);
//d_i functions
int	printf_d_i(va_list *prms, s_flags flags);
char	*digit_overall(char *display, int digit, int nb, s_flags flags);
char	*prec_overall(char *display, int digit, int nb, s_flags flags);
char	*chmp_overall_thn_dgt_pos(char *display, int digit, int nb, s_flags flags);
char	*chmp_overall_thn_dgt_neg(char *display, int digit, int nb, s_flags flags);
char	*chmp_overall_thn_prec(char *display, int digit, int nb, s_flags flags);
char	*chmp_neg_prec_pos(char *display, int digit, int nb, s_flags flags);
char	*chmp_neg_prec_pos_nb_neg(char *display, int digit, int nb, s_flags flags);
//x functions
int	printf_x(va_list *prms, s_flags flags);
char	*chmp_overall_thn_prec_pos_x(char *base, char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_dgt_x(char *base, char *display, int digit, unsigned int nb, s_flags flags);
char	*prec_overall_x(char *base, char *display, int digit, unsigned int nb, s_flags flags);
char	*digit_overall_x(char *base, char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_dgt_x_2(char *base, char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_dgt_x_3(char *display, int digit, unsigned int nb, s_flags flags);
//s functions
int	printf_s(va_list *prms, s_flags flags);
char	*chmp_over_erthing_left(char *display, int digit, char *src, s_flags flags);
char	*chmp_over_erthing_left_2(char *display, int digit, char *src, s_flags flags);
char	*chmp_over_erthing_right(char *display, int digit, char *src, s_flags flags);
char	*digit_overall_s(char *display, int digit, char *src, s_flags flags);
char	*chmp_thn_prec(char *display, int digit, char *src, s_flags flags);
char	*prec_overall_s(char *display, int digit, char *src, s_flags flags);
char	*chmp_neg_s(char *display, int digit, char *src, s_flags flags);
char	*chmp_over_erthing_right_2(char *display, int digit, char *src, s_flags flags);
char *null(void);
//c functions
int	printf_c(va_list *prms, s_flags flags);
char	*put_c(char *display, char chr, s_flags flags);
char	*put_c_neg(char *display, char chr, s_flags flags);
//X functions
int 	printf_X(va_list *prms, s_flags flags);
//p functions
int 	printf_p(va_list *prms, s_flags flags);
char	*put_p(char *display, unsigned long long ptr, char *base, int digit, s_flags flags);
//% functions
int	printf_percent(va_list *prms, s_flags flags);
char	*chmp_and_att_0(char *display, char chr, s_flags flags);
char	*chmp_and_att_neg(char *display, char chr, s_flags flags);
char	*chmp(char *display, char chr, s_flags flags);
char	*display_overall_perc(char *display, char chr, s_flags flags);
//u functions
int 	printf_u(va_list *prms, s_flags flags);
char	*digit_overall_u(char *display, int digit, unsigned int nb, s_flags flags);
char	*prec_overall_u(char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_dgt_u(char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_dgt_u_2(char *display, int digit, unsigned int nb, s_flags flags);
char	*chmp_overall_thn_prec_pos_u(char *display, int digit, unsigned int nb, s_flags flags);
void        ft_itoa_custom_pos_u(unsigned int n, char *arr);
void       ft_itoa_custom_u(unsigned int n, char *arr);
char	*chmp_overall_thn_dgt_u_3(char *display, int digit, unsigned int nb, s_flags flags);
int	countdigit_u(unsigned int nb);

#endif
