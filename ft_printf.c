/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/16 17:26:24 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	findIndex(char *arr, char element)
{
	int i = 0;

	while (arr[i])
	{
		if (arr[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_printf(const char *src, ...)
{
	va_list prms;
	s_flags flg;
	int i = 0;
	int j = 0;
	int l = 0;
	int a;
	int b;
	int (*tabFunction[9]) (va_list *, s_flags) = {printf_percent, printf_p,
													printf_u, printf_x, 
													printf_xx, printf_s, 
													printf_c, printf_d_i, 
													printf_d_i};
	char tabIndex[10] = {'%', 'p', 'u', 'x', 'X', 's', 'c', 'd', 'i', 0};
	char *prmtrs;

	a = 0;
	b = 0;
	va_start(prms, src);
	while (src[i])
	{
		if (src[i] != '%')
		{
			write(1, &src[i++], 1);
			a++;
		}
		else if (src[i] == '%')
		{
			i++;
			init_flg(&flg);
			l = i;
			while (('0' <= src[i] && src[i] <= '9') || src[i] == '-' ||
						src[i] == '.' || src[i] == '*')
				i++;
			prmtrs = ft_strndup(&src[l], (i - l));
			analyse_params(prmtrs, &flg, &prms);
			free(prmtrs);
			while (tabIndex[j] != 0)
			{
				if (src[i] == tabIndex[j])
				{
					b = b + (*tabFunction[j]) (&prms, flg);
					j = 0;
					break ;
				}
				j++;
			}
			i++;
		}
	}
	return (a + b);
}

