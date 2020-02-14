/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:09:38 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:34 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*dgt_upmst_s(char *dsply, int dgt, char *src, s_flags flg)
{
	int y;
	int lngth;
	y = 0;
	lngth = dgt;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	ft_memcpy(dsply, src, dgt);
	return (dsply);
}

char	*chmp_upmst_left(char *dsply, int dgt, char *src, s_flags flg)
{
	int y;
	y = 0;
	int lngth;
	lngth = flg.c;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';	
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);	
	if (flg.p < dgt && flg.p >= 0)
		ft_memcpy(dsply, src, flg.p);
	if ((flg.p >= dgt && flg.p >= 0) || flg.p == -1)
		ft_memcpy(dsply, src, dgt);
	return (dsply);
}

char	*chmp_upmst_right(char *dsply, int dgt, char *src, s_flags flg)
{
	int i;
	int y;
	y = 0;
	i = 0;
	int lngth;
	lngth = flg.c;
	(flg.p >= dgt) ? (i = lngth - dgt) : (i = lngth - flg.p);
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.p == -1)
		ft_memcpy(dsply, src, dgt);
	else if (flg.p < dgt)
		ft_memcpy(&dsply[i], src, flg.p);
	else if (flg.p >= dgt)
		ft_memcpy(&dsply[i], src, dgt);
	return (dsply);
}

char	*chmp_upmst_right2(char *dsply, int dgt, char *src, s_flags flg)
{
	int i;
	int y;
	y = 0;
	i = 0;
	int lngth;
	lngth = flg.c;
	(flg.p >= 0) ? i = lngth - flg.p : (i = lngth - dgt);
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	if (flg.p == -1)
		ft_memcpy(&dsply[i], src, dgt);
	else if (flg.p > dgt)
		ft_memcpy(&dsply[lngth - dgt], src, dgt);
	else 
		ft_memcpy(&dsply[i], src, flg.p);		
	return (dsply);
}

char	*chmp_upmst_prec(char *dsply, int dgt, char *src, s_flags flg)
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

char	*prec_upmst_s(char *dsply, int dgt, char *src, s_flags flg)
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

char	*chmp_neg_s(char *dsply, int dgt, char *src, s_flags flg)
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
	if (*src == '\0' || !src || flg.p == 0)
		return (dsply);
	ft_memcpy(dsply, src, dgt);
	return (dsply);
}

char *null(void)
{
	char *null;
	if (!(null = malloc(sizeof(*null) * 7)))
		return (NULL);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	return (null);
}

int	printf_s(va_list *prms, s_flags flg)
{
	char *src = va_arg(*prms, char *);
   int dgt;
	char *dsply;
	char *src2;
	int p;

	if (src == NULL)
	{
		src2 = null();
		dgt = ft_strlen(src2);
	}
	else
		dgt = ft_strlen(src);
	if (flg.p < 0 && flg.c < dgt && flg.c >= 0)
		dsply = dgt_upmst_s(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c >= dgt && flg.a < 0)
		dsply = chmp_upmst_left(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c == dgt && flg.a == 0)
		dsply = chmp_upmst_right(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c > dgt && flg.a == 0)
		dsply = chmp_upmst_right2(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c < dgt && dgt <= flg.p)
	  dsply = dgt_upmst_s(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c < dgt && flg.p < dgt && flg.c >= flg.p && flg.p >= 0)
		dsply = chmp_upmst_prec(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c < 0 && dgt <= -flg.c)
		dsply = chmp_neg_s(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c < 0 && dgt >= -flg.c)
		dsply = dgt_upmst_s(dsply, dgt, src == NULL ? src2 : src, flg);
	else if (flg.c < dgt && flg.p < dgt && flg.c < flg.p && flg.p >= 0)
	  dsply = prec_upmst_s(dsply, dgt, src == NULL ? src2 : src, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	if (src == NULL)
		free(src2);
	return (p);
}
