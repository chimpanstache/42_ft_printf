/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:44:20 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/19 14:41:06 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_upmst_dgt_neg(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

	++dgt;
	lngth = flg.c;
	if (nb < 0 && dgt == flg.c + 1)
		lngth = dgt;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.a > 0 && nb < 0 && flg.p < 0)
	{
		write_stuff(display, lngth, '0');
		display[0] = '-';
		ft_itoa_custom_pos(nb, &display[lngth - dgt + 1]);
	}
	else if (flg.a < 0)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_upmst_prec_pos(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

	lngth = flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt;
	if (flg.a >= 0)
		i = lngth - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.a < 0)
		ft_itoa_custom(nb, &display[flg.p - dgt]);
	else
		ft_itoa_custom(nb, &display[i]);
	write_0_d_i(display, i, flg.p - dgt);
	return (display);
}

char	*chmp_upmst_prec_neg(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt;
	if (flg.a >= 0)
		i = lngth - dgt - 1;
	write_stuff(display, lngth, ' ');
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

int		printf_d_i_2(int nb, int dgt, t_flags flg)
{
	int		p;
	char	*display;

	if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt && nb < 0)
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

int		printf_d_i(va_list *prms, t_flags flg)
{
	int		nb;
	int		dgt;
	char	*display;
	int		p;

	nb = va_arg(*prms, int);
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
	else
		return (printf_d_i_2(nb, dgt, flg));
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	return (p);
}
