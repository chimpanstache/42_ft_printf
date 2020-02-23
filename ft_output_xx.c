/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:15 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/23 14:37:15 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_upmst_dgt_xx(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
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

char	*chmp_upmst_dgt_xx2(char *dsply, int dgt, unsigned int nb, t_flags flg)  ///////////////////////
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(dsply, lngth, ' ');
	if (flg.a == 1 && flg.p < 0)
		write_stuff(dsply, i, '0');
	else if (flg.a == 1 && flg.p == 0 && nb == 0)
		return (dsply);
	else if (flg.p > dgt)
	{
		y = flg.c - flg.p;
		while (y <= flg.c - dgt)
			dsply[y++] = '0';
	}
	ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}

char	*chmp_upmst_dgt_xx4(char *dsply, int dgt, unsigned int nb, t_flags flg)  ///////////////////////
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(dsply, lngth, ' ');
	write_stuff(dsply, i, '0');
	ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}


char	*chmp_upmst_dgt_xx3(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
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

char	*chmp_upmst_prec_xx(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	y = 0;
	if (!(dsply = malloc(sizeof(*dsply) * (flg.c + 1))))
		return (NULL);
	dsply[flg.c] = '\0';
	i = flg.p - dgt;
	if (flg.a >= 0)
		i = flg.c - dgt;
	write_stuff(dsply, flg.c, ' ');
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

int		printf_xx(va_list *prms, t_flags flg)
{
	unsigned long long	nb;
	int					dgt;
	char				*dsply;
	int					p;

	nb = va_arg(*prms, unsigned long long);
	dgt = countdgt_base(nb, "0123456789ABCDEF");
	if (dgt >= flg.c && dgt >= flg.p)
	{
	//printf("ici1\n"); ////////////////////////
		dsply = dgt_upmst_xx(dsply, dgt, nb, flg);
	}
	else if (flg.p >= flg.c && flg.p >= dgt)
	{
	//printf("ici2\n"); ////////////////////////
		dsply = prec_upmst_xx(dsply, dgt, nb, flg);
	}
	else if ((flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0) ||
				(flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0))
	{
	//printf("ici3\n"); ////////////////////////
		dsply = chmp_upmst_dgt_xx3(dsply, dgt, nb, flg);
	}
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1)
	{
	//printf("ici4\n"); ////////////////////////
		dsply = chmp_upmst_dgt_xx2(dsply, dgt, nb, flg);
	}
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt)
	{
	//printf("ici5\n"); ////////////////////////
		dsply = chmp_upmst_dgt_xx(dsply, dgt, nb, flg);
	}
	else if ((flg.c >= flg.p) && (flg.c >= dgt) && (flg.p > dgt))
	{
	//printf("ici6\n"); ////////////////////////
		dsply = chmp_upmst_prec_xx(dsply, dgt, nb, flg);
	}
	p = ft_strlen(dsply);
	write(1, dsply, p);
	//free(dsply);
	return (p);
}
