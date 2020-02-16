/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:21:54 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/16 17:32:49 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_pos(char *dsply, char chr, s_flags flg)
{
	int lngth;
	int y;

	y = 0;
	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (chr == '\0' || !chr)
	{
		dsply[lngth - 1] = '\0';
		return (dsply);
	}
	if (flg.a < 0)
		dsply[0] = chr;
	else
		dsply[lngth - 1] = chr;
	return (dsply);
}

char	*chmp_neg(char *dsply, char chr, s_flags flg)
{
	int lngth;
	int y;

	y = 0;
	lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (chr == '\0' || !chr)
		return (dsply);
	dsply[0] = chr;
	return (dsply);
}

int		printf_c(va_list *prms, s_flags flg)
{
	char	chr;
	int		p;
	char	*dsply;

	chr = va_arg(*prms, int);
	if (flg.c > 1)
	{
		dsply = chmp_pos(dsply, chr, flg);
	}
	else if (flg.c < -1)
		dsply = chmp_neg(dsply, chr, flg);
	else
	{
		write(1, &chr, 1);
		return (1);
	}
	p = ft_strlen(dsply);
	write(1, dsply, p);
	if (chr == '\0')
		p++;
	free(dsply);
	return (p);
}
