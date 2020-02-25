/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:27:06 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 17:28:54 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst_s(char *dsply, int dgt, char *src, t_flags flg)
{
	int y;
	int lngth;

	y = 0;
	lngth = dgt;
	if (-flg.c > dgt)
		lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	ft_memcpy(dsply, src, dgt);
	return (dsply);
}

char	*prec_upmst_s(char *dsply, int dgt, char *src, t_flags flg)
{
	int lngth;
	int y;

	y = 0;
	lngth = flg.p;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	ft_memcpy(dsply, src, flg.p);
	return (dsply);
}
