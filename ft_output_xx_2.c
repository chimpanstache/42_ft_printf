/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_xx_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:58:22 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/21 14:00:45 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst_xx(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		i;
	char	*base;
	int		lngth;

	base = "0123456789ABCDEF";
	i = 0;
	lngth = dgt;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	if (nb == 0 && flg.p == 0)
	{
		if (flg.c == 1)
			dsply[0] = ' ';
		else
			dsply[0] = '\0';
		return (dsply);
	}
	ft_putnbr_base(nb, base, dsply);
	return (dsply);
}

char	*prec_upmst_xx(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	y = 0;
	lngth = flg.p;
	if (-flg.c > flg.p)
		lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	i = flg.p - dgt;
	write_stuff(dsply, flg.p - dgt, '0');
	ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}
