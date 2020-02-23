/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:09:38 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/23 17:47:11 by ehafidi          ###   ########.fr       */
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

char	*special_case_s(char *dsply, int dgt, char *src, t_flags flg)
{
	int y;
	int lngth;

	y = 0;
	lngth = -flg.c;
	if (-flg.c <= flg.p)
		lngth = flg.p; 
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	ft_memcpy(dsply, src, flg.p);
	return (dsply);
}

char	*chmp_upmst_left(char *dsply, int dgt, char *src, t_flags flg)
{
	int y;
	int lngth;

	y = 0;
	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.p < dgt && flg.p >= 0)
		ft_memcpy(dsply, src, flg.p);
	if ((flg.p >= dgt && flg.p >= 0) || flg.p < 0)
		ft_memcpy(dsply, src, dgt);
	return (dsply);
}

char	*chmp_upmst_right(char *dsply, int dgt, char *src, t_flags flg)
{
	int i;
	int lngth;

	i = 0;
	lngth = flg.c;
	i = lngth - flg.p;
	if (flg.p >= dgt)
		i = lngth - dgt;

	//printf("%d%s\n", dgt, ": dgt"); ////////////////////	
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.p < 0)
		ft_memcpy(dsply, src, dgt);
	else if (flg.p < dgt)
		ft_memcpy(&dsply[i], src, flg.p);
	else if (flg.p >= dgt)
		ft_memcpy(&dsply[i], src, dgt);
	return (dsply);
}

char	*chmp_upmst_right2(char *dsply, int dgt, char *src, t_flags flg)
{
	int i;
	int y;
	int lngth;

	y = 0;
	i = 0;
	lngth = flg.c;
	i = lngth - dgt;
	if (flg.p >= 0)
		i = lngth - flg.p;
	//printf("%d\n", lngth); ///////////////////////////
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.p == -1)
	{
		//printf("hihi\n"); ///////////////////////////
		ft_memcpy(&dsply[i], src, dgt);
	}
	else if (flg.p > dgt || (flg.p < 0))
	{
		//printf("hihi1\n"); ///////////////////////////
		ft_memcpy(&dsply[lngth - dgt], src, dgt);
	}	
	else
	{
		//printf("hihi2\n"); ///////////////////////////
		//printf("%d%s\n", i, ": i"); ///////////////////////////
		ft_memcpy(&dsply[i], src, flg.p);
	}
	return (dsply);
}

char	*chmp_upmst_prec(char *dsply, int dgt, char *src, t_flags flg)
{
	int i;
	int y;
	int lngth;

	y = 0;
	lngth = flg.c;
	i = lngth - flg.p;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.a < 0)
		ft_memcpy(dsply, src, flg.p);
	if (flg.a == 0)
		ft_memcpy(&dsply[i], src, flg.p);
	return (dsply);
}
