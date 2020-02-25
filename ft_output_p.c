/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:53 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 17:05:26 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_ox(char *dsply)
{
	dsply[0] = '0';
	dsply[1] = 'x';
}

char	*put_p(char *dsply, unsigned long long ptr, int dgt, t_flags flg)
{
	char	*base;

	base = "0123456789abcdef";
	if (!(dsply = malloc(sizeof(*dsply) * (flg.c + 1))))
		return (NULL);
	dsply[flg.c] = '\0';
	write_stuff(dsply, flg.c, ' ');
	if (flg.a < 0)
	{
		write_ox(dsply);
		ft_ulltoa_base(ptr, &dsply[2], base);
	}
	else
	{
		if (!ptr && flg.p == 0)
			write_ox(&dsply[flg.c - 2]);
		else
		{
			write_ox(&dsply[flg.c - dgt]);
			ft_ulltoa_base(ptr, &dsply[flg.c - dgt + 2], base);
		}
	}
	return (dsply);
}

char	*put_p_c_neg(char *dsply, unsigned long long ptr, int dgt, t_flags flg)
{
	char	*base;

	base = "0123456789abcdef";
	if (!(dsply = malloc(sizeof(*dsply) * (-flg.c + 1))))
		return (NULL);
	dsply[-flg.c] = '\0';
	write_stuff(dsply, -flg.c, ' ');
	if (flg.a < 0)
	{
		write_ox(dsply);
		ft_ulltoa_base(ptr, &dsply[2], base);
	}
	else if (!ptr && flg.p == 0)
		write_ox(&dsply[-flg.c - 2]);
	else if (flg.p == -1 && flg.a == 0)
	{
		write_ox(&dsply[0]);
		ft_ulltoa_base(ptr, &dsply[2], base);
	}
	else
	{
		write_ox(&dsply[-flg.c - dgt]);
		ft_ulltoa_base(ptr, &dsply[-flg.c - dgt + 2], base);
	}
	return (dsply);
}

char	*put_p2(char *dsply, unsigned long long ptr, int dgt, t_flags flg)
{
	int		lngth;
	char	*base;

	base = "0123456789abcdef";
	lngth = dgt;
	if (!(dsply = malloc(sizeof(*dsply) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	write_stuff(dsply, lngth, ' ');
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

int		printf_p(va_list *prms, t_flags flg)
{
	int					dgt;
	unsigned long long	ptr;
	char				*base;
	char				*dsply;
	int					p;

	ptr = va_arg(*prms, unsigned long long);
	base = "0123456789abcdef";
	p = 0;
	dgt = countdgt_base(ptr, base) + 2;
	if (flg.c > dgt)
		dsply = put_p(dsply, ptr, dgt, flg);
	else if (flg.c < 0 && -flg.c > dgt)
		dsply = put_p_c_neg(dsply, ptr, dgt, flg);
	else
		dsply = put_p2(dsply, ptr, dgt, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}
