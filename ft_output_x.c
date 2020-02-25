/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 17:48:54 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst_x(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		i;
	char	*base;
	int		lngth;

	base = "0123456789abcdef";
	i = 0;
	lngth = dgt;
	if (-flg.c > dgt)
		lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
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

char	*prec_upmst_x(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789abcdef";
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

char	*chmp_upmst_dgt_x(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789abcdef";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		dsply[y++] = ' ';
	if (flg.p == 0 && nb == 0)
		return (dsply);
	if (flg.a < 0)
		ft_putnbr_base(nb, base, dsply);
	else
		ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}

char	*chmp_upmst_dgt_x2(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789abcdef";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(dsply, lngth, ' ');
	if (flg.a == 1 && flg.p < 0)
		write_stuff(dsply, i, '0');
	if (flg.a == 1 && flg.p == 0 && nb == 0)
		return (dsply);
	if (flg.p > dgt)
	{
		y = flg.c - flg.p;
		while (y <= flg.c - dgt)
			dsply[y++] = '0';
	}
	ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}

int		printf_x(va_list *prms, t_flags flg)
{
	unsigned long long	nb;
	int					dgt;
	char				*dsply;
	int					p;

	nb = va_arg(*prms, unsigned long long);
	dgt = countdgt_base(nb, "0123456789abcdef");
	if (dgt >= flg.c && dgt >= flg.p)
		dsply = dgt_upmst_x(dsply, dgt, nb, flg);
	else if (flg.p >= flg.c && flg.p >= dgt)
		dsply = prec_upmst_x(dsply, dgt, nb, flg);
	else if ((flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0) ||
				(flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0))
		dsply = chmp_upmst_dgt_x3(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1)
		dsply = chmp_upmst_dgt_x2(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt)
		dsply = chmp_upmst_dgt_x(dsply, dgt, nb, flg);
	else if ((flg.c >= flg.p) && (flg.c >= dgt) && (flg.p > dgt))
		dsply = chmp_upmst_prec_x(dsply, dgt, nb, flg);
	p = ft_strlen(dsply);
	write(1, dsply, ft_strlen(dsply));
	free(dsply);
	return (p);
}
