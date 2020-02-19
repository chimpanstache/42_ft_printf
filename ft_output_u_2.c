/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:26:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/19 14:42:53 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_upmst_dgt_u3(char *display, int dgt, unsigned int nb, t_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	write_stuff(display, lngth, ' ');
	if (flg.p > -1)
	{
		y = lngth - flg.p;
		while (y < lngth)
			display[y++] = '0';
	}
	else if (flg.p == -1)
		write_stuff(display, lngth, '0');
	return (display);
}

char	*chmp_upmst_prec_u(char *display, int dgt, unsigned int nb, t_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.c;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flg.p - dgt;
	if (flg.a >= 0)
		i = lngth - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.a < 0)
		ft_itoa_custom_pos_u(nb, &display[flg.p - dgt]);
	else
		ft_itoa_custom_pos_u(nb, &display[i]);
	y = 0;
	while (y < (flg.p - dgt))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}
