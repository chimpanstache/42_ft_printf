/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:53 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 15:52:53 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*put_p(char *dsply, unsigned long long ptr, char *base, int dgt, s_flags flg)
{
	int lngth;
	int y;
	int i;

	y = 0;
	i = 0;
	lngth = flg.c;
	
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	if (flg.a < 0)
	{	 
		dsply[0] = '0';
		dsply[1] = 'x';
			ft_ulltoa_base(ptr, &dsply[2], base);
	}
	else
	{
		if (!ptr && flg.p == 0)
		{
			dsply[lngth - 2] = '0';
			dsply[lngth - 1] = 'x';
		}
		else
		{
			dsply[lngth - dgt] = '0';
			dsply[lngth - dgt + 1] = 'x';
			ft_ulltoa_base(ptr, &dsply[lngth - dgt + 2], base);
		}
	}
	return (dsply);
}

char	*put_p2(char *dsply, unsigned long long ptr, char *base, int dgt, s_flags flg)
{
	int lngth;
	int y;
	int i;

	y = 0;
	i = 0;
	lngth = dgt;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	while (y < lngth)
		dsply[y++] = ' ';
	dsply[0] = '0';
	dsply[1] = 'x';
	if (!ptr && flg.p_p == 1)
	{
		dsply[2] = '\0';
		return (dsply);
	}
	ft_ulltoa_base(ptr, &dsply[2], base);
	return (dsply);
}

int 	printf_p(va_list *prms, s_flags flg)
{
	int dgt;
	unsigned long long ptr = va_arg(*prms, unsigned long long);
	char *base = "0123456789abcdef";
	char *dsply;
	int p;

	p = 0;
	dgt = countdgt_base(ptr, base) + 2;
	if (flg.c > dgt)
		dsply = put_p(dsply, ptr, base, dgt, flg);
	else
		dsply = put_p2(dsply, ptr, base, dgt, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}