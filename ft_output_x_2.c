/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:05:05 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/16 18:05:41 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_upmst_dgt_x3(char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (flg.p > -1)
	{
		y = lngth - flg.p;
		while (y < lngth)
			dsply[y++] = '0';
	}
	else if (flg.p == -1)
		write_stuff(dsply, lngth, '0');
	return (dsply);
}

char	*chmp_upmst_prec_x(char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int		i;
	int		y;
	char	*base;

	base = "0123456789abcdef";
	y = 0;
	if (!(dsply = malloc(sizeof(*dsply) * (flg.c + 1))))
		return (NULL);
	dsply[flg.c] = '\0';
	i = flg.p - dgt;
	if (flg.a >= 0)
		i = flg.c - dgt;
	while (y < flg.c)
		dsply[y++] = ' ';
	if (flg.a < 0)
		ft_putnbr_base(nb, base, &dsply[flg.p - dgt]);
	else
		ft_putnbr_base(nb, base, &dsply[i]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		dsply[--i] = '0';
		y++;
	}
	return (dsply);
}
