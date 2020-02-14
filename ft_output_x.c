/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:52 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst_x(char *base, char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int i;

	i = 0;
	int lngth;
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

char	*prec_upmst_x(char *base, char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.p;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		dsply[y++] = '0';
	ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}

char	*chmp_upmst_dgt_x(char *base, char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

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

char	*chmp_upmst_dgt_x2(char *base, char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		dsply[y++] = ' ';
	if (flg.a == 1 && flg.p == -1)
	{
		y = 0;
		while (y < i)
			dsply[y++] = '0';
	}
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
	{
		y = 0;
		while (y < lngth)
			dsply[y++] = '0';
	}
	return (dsply);
}

char	*chmp_upmst_prec_x(char *base, char *dsply, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	(flg.a >= 0) ? (i = lngth - dgt) : (i = flg.p - dgt);
	while (y < lngth)
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

int 	printf_x(va_list *prms, s_flags flg)
{
	unsigned long long nb = va_arg(*prms, unsigned long long);
	int dgt;
	char *dsply;
	char *base = "0123456789abcdef";
	int p;

	dgt = countdgt_base(nb, base);
	if (dgt >= flg.c && dgt >= flg.p)
		dsply = dgt_upmst_x(base, dsply, dgt, nb, flg);
	else if (flg.p >= flg.c && flg.p >= dgt)
		dsply = prec_upmst_x(base, dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0)
		dsply = chmp_upmst_dgt_x3(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0)
		dsply = chmp_upmst_dgt_x3(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1) 
		dsply = chmp_upmst_dgt_x2(base, dsply, dgt, nb, flg); 
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt) 
		dsply = chmp_upmst_dgt_x(base, dsply, dgt, nb, flg); 
	else if ((flg.c >= flg.p) && (flg.c >= dgt) && (flg.p > dgt))
		dsply = chmp_upmst_prec_x(base, dsply, dgt, nb, flg);
	p = ft_strlen(dsply);
	write(1, dsply, ft_strlen(dsply));
	free(dsply);
	return (p);
}