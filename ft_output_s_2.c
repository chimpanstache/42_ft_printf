/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:26:27 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/19 14:42:16 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

char	*chmp_neg_s(char *dsply, int dgt, char *src, t_flags flg)
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

int		printf_s_null(char *src, t_flags flg)
{
	int		dgt;
	char	*dsply;
	int		p;

	src = null();
	dgt = ft_strlen(src);
	if ((flg.p < 0 && flg.c < dgt && flg.c >= 0) || (flg.c < 0 && dgt >= -flg.c)
			|| (flg.c < dgt && dgt <= flg.p))
		dsply = dgt_upmst_s(dsply, dgt, src, flg);
	else if (flg.c >= dgt && flg.a < 0)
		dsply = chmp_upmst_left(dsply, dgt, src, flg);
	else if (flg.c == dgt && flg.a == 0)
		dsply = chmp_upmst_right(dsply, dgt, src, flg);
	else if (flg.c > dgt && flg.a == 0)
		dsply = chmp_upmst_right2(dsply, dgt, src, flg);
	else if (flg.c < dgt && flg.p < dgt && flg.c >= flg.p && flg.p >= 0)
		dsply = chmp_upmst_prec(dsply, dgt, src, flg);
	else if (flg.c < 0 && dgt <= -flg.c)
		dsply = chmp_neg_s(dsply, dgt, src, flg);
	else if (flg.c < dgt && flg.p < dgt && flg.c < flg.p && flg.p >= 0)
		dsply = prec_upmst_s(dsply, dgt, src, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}

int		printf_s_2(char *src, int dgt, t_flags flg)
{
	int		p;
	char	*dsply;

	if (flg.c < dgt && flg.p < dgt && flg.c >= flg.p && flg.p >= 0)
		dsply = chmp_upmst_prec(dsply, dgt, src, flg);
	else if (flg.c < 0 && dgt <= -flg.c)
		dsply = chmp_neg_s(dsply, dgt, src, flg);
	else if (flg.c < dgt && flg.p < dgt && flg.c < flg.p && flg.p >= 0)
		dsply = prec_upmst_s(dsply, dgt, src, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}

int		printf_s(va_list *prms, t_flags flg)
{
	char	*src;
	int		dgt;
	char	*dsply;
	int		p;

	src = va_arg(*prms, char *);
	if (src == NULL)
		return (printf_s_null(src, flg));
	dgt = ft_strlen(src);
	if ((flg.p < 0 && flg.c < dgt && flg.c >= 0) || (flg.c < 0 && dgt >= -flg.c)
			|| (flg.c < dgt && dgt <= flg.p))
		dsply = dgt_upmst_s(dsply, dgt, src, flg);
	else if (flg.c >= dgt && flg.a < 0)
		dsply = chmp_upmst_left(dsply, dgt, src, flg);
	else if (flg.c == dgt && flg.a == 0)
		dsply = chmp_upmst_right(dsply, dgt, src, flg);
	else if (flg.c > dgt && flg.a == 0)
		dsply = chmp_upmst_right2(dsply, dgt, src, flg);
	else
		return (printf_s_2(src, dgt, flg));
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}
