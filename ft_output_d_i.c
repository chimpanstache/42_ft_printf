/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/16 19:08:20 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst(char *display, int dgt, int nb, s_flags flg)
{
	int i;
	int lngth;

	i = 0;
	lngth = dgt + 1;
	if (nb >= 0)
		lngth = dgt;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (nb == 0 && flg.p == 0)
	{
		if (flg.c == 1)
			display[0] = ' ';
		else
			display[0] = '\0';
		return (display);
	}
	ft_itoa_custom(nb, display);
	return (display);
}

char	*prec_upmst(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.p + 1;
	if (nb >= 0)
		lngth = flg.p;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		display[y++] = '0';
	ft_itoa_custom_pos(nb, &display[i]);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_neg_prec_pos(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = -flg.c + 1;
	if (-flg.c >= flg.p)
		lngth = -flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.p == 0 && nb == 0)
		return (display);
	if (flg.p < dgt)
		ft_itoa_custom_pos(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_nb_neg_prec_pos(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = -flg.c;
	if (-flg.c <= flg.p)
		lngth = flg.p + 1;
	if (dgt >= -flg.c && -flg.c > flg.p)
		lngth++;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt + 1;
	if (nb >= 0) 
		i = flg.p - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.p < dgt)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_upmst_dgt_pos(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		display[y++] = ' ';
	y = 0;
	if (flg.p < 0 && flg.a > 0)
		while (y < lngth)
			display[y++] = '0';
	if (flg.p == 0 && nb == 0)
		return (display);
	if (flg.a < 0)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_upmst_dgt_neg(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	++dgt;
	lngth = flg.c;
	if (nb < 0 && dgt == flg.c + 1)
		lngth = dgt;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		display[y++] = ' ';
	y = 0;
	if (flg.a > 0 && nb < 0 && flg.p < 0)
	{
		while (y < lngth)
			display[y++] = '0';
		display[0] = '-';
		ft_itoa_custom_pos(nb, &display[lngth - dgt + 1]);
	}
	else if (flg.a < 0)
		ft_itoa_custom(nb, display);
	else 
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_upmst_prec_pos(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	(flg.a >= 0) ? (i = lngth - dgt) : (i = flg.p - dgt);
	while (y < lngth)
		display[y++] = ' ';
	if (flg.a < 0)
		ft_itoa_custom(nb, &display[flg.p - dgt]);
	else
		ft_itoa_custom(nb, &display[i]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}

char	*chmp_upmst_prec_neg(char *display, int dgt, int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	(flg.a >= 0) ? (i = lngth - dgt - 1) : (i = flg.p - dgt);
	while (y < lngth)
		display[y++] = ' ';
	if (flg.a < 0)
		ft_itoa_custom_pos(nb, &display[flg.p - dgt + 1]);
	else
		ft_itoa_custom_pos(nb, &display[i + 1]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		display[i--] = '0';
		y++;
	}
	if (nb < 0)
		display[i--] = '-';
	return (display);
}

int	printf_d_i(va_list *prms, s_flags flg)
{
	int nb = va_arg(*prms, int);
	int dgt;
	char *display;
	int p;

	dgt = countdgt_d_i(nb);
	if (dgt >= flg.c && dgt >= flg.p && flg.c >= 0)
		display = dgt_upmst(display, dgt, nb, flg);
	else if (flg.c < 0 && nb >= 0) 
		display = chmp_neg_prec_pos(display, dgt, nb, flg);
	else if (flg.c < 0 && nb < 0) 
		display = chmp_nb_neg_prec_pos(display, dgt, nb, flg);
	else if (flg.p >= flg.c && flg.p >= dgt)
		display = prec_upmst(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt && nb >= 0) 
		display = chmp_upmst_dgt_pos(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt && nb < 0) 
		display = chmp_upmst_dgt_neg(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p > dgt && nb >= 0)
		display = chmp_upmst_prec_pos(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p > dgt && nb < 0)
		display = chmp_upmst_prec_neg(display, dgt, nb, flg);
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	return (p);
}
