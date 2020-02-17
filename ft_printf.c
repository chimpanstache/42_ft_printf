/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/17 19:15:16 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_string(s_ind *ind, const char *src)
{
	write(1, &src[ind->i++], 1);
	ind->a++;
}

char	*hardcode_a_string(char *tabindex)
{
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

void	ch0se_fnction(s_ind *ind, va_list *prms, s_flags *flg, const char *src)
{
	int (*tabfunction[9]) (va_list *, s_flags) = {printf_percent, printf_p,
	printf_u, printf_x,	printf_xx, printf_s, printf_c, printf_d_i, printf_d_i};
	char tabindex[10];

	*tabindex = harcode_a_string(tabindex);
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
