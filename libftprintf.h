/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:41:29 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/22 13:17:51 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
//# include "libft/libft.h"

typedef struct	s_flags
{
	int a;
	int c;
	int p;
	int p_p;
}				t_flags;

typedef struct	s_ind
{
	int a;
	int b;
	int i;
	int j;
	int l;
}				t_ind;

/*
** side & parse functions
*/
void			ft_putnbr_base(int n, char *base, char *str);
int				ft_attribute(char str);
int				ft_champ(char *str, va_list *prms);
int				ft_precision(char *str, va_list *prms);
int				countdgt_d_i(int nb);
void			analyse_params(char *prmtrs, t_flags *flg, va_list *prms);
void			ft_case_percent(int a);
void			init_flg(t_flags *flg);
void			ft_itoa_custom(int n, char *arr);
static int		count_no_diggity(int n);
void			ft_itoa_custom_pos(int n, char *arr);
int				ft_putnbr_base_p(unsigned long long nbr, char *base);
int				countdgt_base(unsigned long long nbr, char *base);
void			ft_ulltoa_base(unsigned long long n, char *arr, char *base);
void			ft_putnbr_custom(int n, char *src);
void			ft_putnbr_custom_pos(int n, char *src);
void			write_ox(char *dsply);
void			write_stuff(char *dsply, int limit, char stuff);
void			init_ind(t_ind *ind);
/*
** d_i functions
*/
int				printf_d_i(va_list *prms, t_flags flg);
char			*dgt_upmst(char *dsply, int dgt, int nb, t_flags flg);
char			*prec_upmst(char *dsply, int dgt, int nb, t_flags flg);
char			*chmp_neg_prec_pos(char *dsply, int dgt, int nb, t_flags flg);
char			*chmp_nb_neg_prec_pos(char *dsply, int dgt, int nb,
										t_flags flg);
char			*chmp_upmst_dgt_pos(char *dsply, int dgt, int nb, t_flags flg);
char			*chmp_upmst_dgt_neg(char *dsply, int dgt, int nb, t_flags flg);
char			*chmp_upmst_prec_pos(char *dsply, int dgt, int nb, t_flags flg);
char			*chmp_upmst_prec_neg(char *dsply, int dgt, int nb, t_flags flg);
void			write_0_d_i(char *display, int ind, int limit);
char		*printf_d_i_2(int nb, int dgt, t_flags flg, char *display);
/*
** x functions
*/
int				printf_x(va_list *prms, t_flags flg);
char			*dgt_upmst_x(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*prec_upmst_x(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_x(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_x2(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_x3(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_prec_x(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
/*
** s functions
*/
int				printf_s(va_list *prms, t_flags flg);
char			*dgt_upmst_s(char *dsply, int dgt, char *src, t_flags flg);
char			*chmp_upmst_left(char *dsply, int dgt, char *src, t_flags flg);
char			*chmp_upmst_right(char *dsply, int dgt, char *src, t_flags flg);
char			*chmp_upmst_right2(char *dsply, int dgt, char *src,
									t_flags flg);
char			*chmp_upmst_prec(char *dsply, int dgt, char *src, t_flags flg);
char			*prec_upmst_s(char *dsply, int dgt, char *src, t_flags flg);
char			*chmp_neg_s(char *dsply, int dgt, char *src, t_flags flg);
char			*null(void);
int				printf_s_null(char *src, t_flags flg);
char	*printf_s_2(char *src, int dgt, t_flags flg, char *dsply);
/*
** c functions
*/
int				printf_c(va_list *prms, t_flags flg);
char			*chmp_pos(char *dsply, char chr, t_flags flg);
char			*chmp_neg(char *dsply, char chr, t_flags flg);
/*
** X functions
*/
int				printf_xx(va_list *prms, t_flags flg);
char			*dgt_upmst_xx(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*prec_upmst_xx(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_xx(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_xx2(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_xx3(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_prec_xx(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
/*
** p functions
*/
void			write_stuff(char *dsply, int limit, char stuff);
void			write_ox(char *dsply);
int				printf_p(va_list *prms, t_flags flg);
char			*put_p(char *dsply, unsigned long long ptr, int dgt,
						t_flags flg);
char			*put_p2(char *dsply, unsigned long long ptr, int dgt,
						t_flags flg);
char			*put_p_c_neg(char *dsply, unsigned long long ptr, int dgt,
								t_flags flg);
/*
** % functions
*/
int				printf_percent(va_list *prms, t_flags flg);
char			*dsply_upmst_perc(char *dsply, t_flags flg);
char			*chmp_upmst_perc(char *dsply, t_flags flg);
char			*chmp_att_neg_perc(char *dsply, t_flags flg);
char			*chmp_att_0(char *dsply, t_flags flg);
/*
** u functions
*/
int				printf_u(va_list *prms, t_flags flg);
char			*dgt_upmst_u(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*prec_upmst_u(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_u(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_u2(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
char			*chmp_upmst_dgt_u3(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
void			ft_itoa_custom_pos_u(unsigned int n, char *arr);
void			ft_itoa_custom_u(unsigned int n, char *arr);
char			*chmp_upmst_prec_u(char *dsply, int dgt, unsigned int nb,
								t_flags flg);
int				countdgt_u(unsigned int nb);
/*
** ft_printf.c
*/
int				ft_printf(const char *src, ...);
void			write_string(t_ind *ind, const char *src);
void			get_params(t_ind *ind, const char *src, t_flags *flg,
							va_list *prms);
void			ch0se_fnction(t_ind *ind, va_list *prms, t_flags *flg,
								const char *src);
char			*hardcode_tabindex(char *tabindex);
void			init_types(int (*tabfunction[9]) (va_list *, t_flags));

//ft_to_delete
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *str, size_t len);
int		ft_strlen(char *base);
int		ft_atoi(const char *str);

#endif
