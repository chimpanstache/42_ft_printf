/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_%.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:48:33 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 15:48:47 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dsply_upmst_perc(char *dsply, s_flags flg)
{
    if (!(dsply = malloc(sizeof(*dsply) * (1 + 1))))
		return (NULL);
    dsply[0] = '%';
    dsply[1] = '\0';
    return (dsply);
}

char	*chmp_upmst_perc(char *dsply, s_flags flg)
{
    int lngth;
    int y;

    lngth = flg.c;
    if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
    dsply[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	dsply[y++] = ' ';
    dsply[lngth - 1] = '%';
    return (dsply);
}

char	*chmp_att_neg_perc(char *dsply, s_flags flg)
{
    int lngth;
    int y;

    lngth = flg.c;
    if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
    dsply[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	dsply[y++] = ' ';
    dsply[0] = '%';
    return (dsply);
}

char	*chmp_att_0(char *dsply, s_flags flg)
{
    int lngth;
    int y;

    lngth = flg.c;
    if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
    dsply[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	dsply[y++] = '0';
    dsply[lngth - 1] = '%';
    return (dsply);
}

int	printf_percent(va_list *prms, s_flags flg)
{
	int p;
    char *dsply;
	if (flg.c < 2)
    dsply = dsply_upmst_perc(dsply, flg);
  if (flg.c > 1 && flg.a == 0)
		dsply = chmp_upmst_perc(dsply, flg);
  if (flg.c > 1 && flg.a == -1)
		dsply = chmp_att_neg_perc(dsply, flg);
  if (flg.c > 1 && flg.a == 1)
		dsply = chmp_att_0(dsply, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}