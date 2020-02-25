/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:21:54 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 16:47:11 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_pos(char *dsply, char chr, t_flags flg)
{
	int lngth;

	lngth = flg.c;
	if (flg.c < -1)
		lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (chr == '\0' || !chr)
	{
		dsply[lngth - 1] = '\0';
		return (dsply);
	}
	if (flg.c < -1 || flg.a < 0)
		dsply[0] = chr;
	else
		dsply[lngth - 1] = chr;
	return (dsply);
}

int		printf_c(va_list *prms, t_flags flg)
{
	char	chr;
	int		p;
	char	*dsply;

	chr = va_arg(*prms, int);
	if (flg.c > 1 || flg.c < -1)
		dsply = chmp_pos(dsply, chr, flg);
	else
	{
		write(1, &chr, 1);
		return (1);
	}
	p = ft_strlen(dsply);
	if (chr != '\0')
		write(1, dsply, p);
	else if (chr == '\0')
	{
		if (flg.a == -1)
			write(1, "\0", 1);
		write(1, dsply, p);
		if (flg.a == 0)
			write(1, "\0", 1);
	}
	free(dsply);
	return (chr != '\0' ? p : ++p);
}
