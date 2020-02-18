/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/18 14:55:14 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_string(s_ind *ind, const char *src)
{
	write(1, &src[ind->i++], 1);
	ind->a++;
}

char	*hardcode_tabindex(char *tabindex)
{
	if (!(tabindex = malloc(sizeof(*tabindex) * (10))))
		return (0);
	tabindex[0] = '%';
	tabindex[1] = 'p';
	tabindex[2] = 'u';
	tabindex[3] = 'x';
	tabindex[4] = 'X';
	tabindex[5] = 's';
	tabindex[6] = 'c';
	tabindex[7] = 'd';
	tabindex[8] = 'i';
	tabindex[9] = 0;
	return (tabindex);
}

int	*hardcode_tabfunction(int (*tabfunction) (va_list *, s_flags))
{
	if (!(tabfunction = malloc(sizeof(*tabfunction) * (9))))
		return (0);
	tabfunction[0] = printf_percent;
	tabfunction[1] = printf_p;
	tabfunction[2] = printf_u;
	tabfunction[3] = printf_x;
	tabfunction[4] = printf_xx;
	tabfunction[5] = printf_s;
	tabfunction[6] = printf_c;
	tabfunction[7] = printf_d_i;
	tabfunction[8] = printf_d_i;
	return (tabfunction);
}

void	ch0se_fnction(s_ind *ind, va_list *prms, s_flags *flg, const char *src)
{
	int (*tabfunction[9]) (va_list *, s_flags) = {printf_percent, printf_p,
	printf_u, printf_x, printf_xx, printf_s, printf_c, printf_d_i, printf_d_i};
	//int (*tabfunction) (va_list *, s_flags);
	char *tabindex;

	tabindex = hardcode_a_string(tabindex);
	// tabfunction = hardcode_tabfunction(tabfunction);
	while (tabindex[ind->j] != 0)
	{
		if (src[ind->i] == tabindex[ind->j])
		{
			ind->b = ind->b + (*tabfunction[ind->j])(prms, *flg);
			ind->j = 0;
			break ;
		}
		ind->j++;
	}
}

void	get_params(s_ind *ind, const char *src, s_flags *flg, va_list *prms)
{
	char	*prmtrs;
	int		i;

	i = ind->i - ind->l;
	prmtrs = ft_strndup(&src[ind->l], i);
	analyse_params(prmtrs, flg, prms);
	free(prmtrs);
}

int		ft_printf(const char *src, ...)
{
	va_list prms;
	s_flags flg;
	s_ind	ind;

	init_ind(&ind);
	va_start(prms, src);
	while (src[ind.i])
	{
		if (src[ind.i] != '%')
			write_string(&ind, src);
		else if (src[ind.i++] == '%')
		{
			init_flg(&flg);
			ind.l = ind.i;
			while (('0' <= src[ind.i] && src[ind.i] <= '9') || src[ind.i] == '-'
			|| src[ind.i] == '.' || src[ind.i] == '*')
				ind.i++;
			get_params(&ind, src, &flg, &prms);
			ch0se_fnction(&ind, &prms, &flg, src);
			ind.i++;
		}
	}
	va_end(prms);
	return (ind.a + ind.b);
}
