/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/23 13:58:45 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst(char *display, int dgt, int nb, t_flags flg)
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

char	*prec_upmst(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

	lngth = flg.p + 1;
	if (nb >= 0)
		lngth = flg.p;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(display, lngth, '0');
	ft_itoa_custom_pos(nb, &display[i]);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_neg_prec_pos(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

	lngth = -flg.c;
	if (-flg.c <= flg.p)
		lngth = flg.p;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.p == 0 && nb == 0)
		return (display);
	//printf("on appel itoacustompos avec une taille de %d, %d,%d, i = %d\n", lngth, flg.p, dgt, i);
	if (flg.p < dgt)
		ft_itoa_custom_pos(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	write_0_d_i(display, i, flg.p - dgt);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_nb_neg_prec_pos(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

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
	write_0_d_i(display, i, flg.p - dgt);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_upmst_dgt_pos(char *display, int dgt, int nb, t_flags flg)
{
	int lngth;
	int i;

	lngth = flg.c;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.p < 0 && flg.a > 0)
		write_stuff(display, lngth, '0');
	if (flg.p == 0 && nb == 0)
		return (display);
	if (flg.a < 0)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom(nb, &display[i]);
	return (display);
}
