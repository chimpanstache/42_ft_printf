/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:43:42 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/17 13:43:46 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_custom_pos(int n, char *src)
{
	unsigned int	nb;
	static int		i = 0;
	int				y;

	y = 0;
	if (i != 0)
		i = y;
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_custom_pos(nb / 10, src);
	src[i++] = nb % 10 + '0';
}

void	ft_putnbr_custom(int n, char *src)
{
	unsigned int	nb;
	static int		i = 0;
	int				y;

	y = 0;
	if (i != 0)
		i = y;
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		src[i++] = '-';
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_custom(nb / 10, src);
	src[i++] = nb % 10 + '0';
}

int		ft_putnbr_base_p(unsigned long long nbr, char *base)
{
	int			a;
	static int	p = 1;

	a = ft_strlen(base);
	if (nbr > a)
	{
		++p;
		ft_putnbr_base_p((nbr / a), base);
	}
	write(1, &base[nbr % a], 1);
	return (p);
}

void	write_stuff(char *dsply, int limit, char stuff)
{
	int y;

	y = 0;
	while (y < limit)
		dsply[y++] = stuff;
}

void	write_0_d_i(char *display, int ind, int limit)
{
	int y;

	y = 0;
	while (y < limit)
	{
		display[--ind] = '0';
		y++;
	}
}
