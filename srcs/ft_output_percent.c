/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:48:33 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 17:28:20 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dsply_upmst_perc(char *dsply, t_flags flg)
{
	int lngth;

	lngth = 1;
	if (flg.c < -1)
		lngth = -flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	write_stuff(dsply, lngth, ' ');
	dsply[0] = '%';
	dsply[lngth] = '\0';
	return (dsply);
}

char	*chmp_upmst_perc(char *dsply, t_flags flg)
{
	int lngth;

	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	dsply[lngth - 1] = '%';
	return (dsply);
}

char	*chmp_att_neg_perc(char *dsply, t_flags flg)
{
	int lngth;

	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	dsply[0] = '%';
	return (dsply);
}

char	*chmp_att_0(char *dsply, t_flags flg)
{
	int lngth;
	int y;

	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, '0');
	dsply[lngth - 1] = '%';
	return (dsply);
}

int		printf_percent(va_list *prms, t_flags flg)
{
	int		p;
	char	*dsply;

	if (flg.c < 2)
		dsply = dsply_upmst_perc(dsply, flg);
	else if (flg.c > 1 && flg.a == 0)
		dsply = chmp_upmst_perc(dsply, flg);
	else if (flg.c > 1 && flg.a == -1)
		dsply = chmp_att_neg_perc(dsply, flg);
	else if (flg.c > 1 && flg.a == 1)
		dsply = chmp_att_0(dsply, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}
