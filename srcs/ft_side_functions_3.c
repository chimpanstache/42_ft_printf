/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:58:08 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/25 18:03:44 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_itoa_custom_pos_u(unsigned int n, char *arr)
{
	unsigned int	nb;
	int				len;

	len = countdgt_u(n);
	nb = (unsigned int)n;
	while (len-- > 0)
	{
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
}

void	init_ind(t_ind *ind)
{
	ind->a = 0;
	ind->b = 0;
	ind->i = 0;
	ind->j = 0;
	ind->l = 0;
}

void	write_string(t_ind *ind, const char *src)
{
	write(1, &src[ind->i++], 1);
	ind->a++;
}

char	*chmp_upmst_dgt_xx(char *dsply, int dgt, unsigned int nb, t_flags flg)
{
	int		lngth;
	int		i;
	int		y;
	char	*base;

	base = "0123456789ABCDEF";
	lngth = flg.c;
	y = 0;
	if (!(dsply = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	dsply[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		dsply[y++] = ' ';
	if (flg.p == 0 && nb == 0)
		return (dsply);
	if (flg.a < 0)
		ft_putnbr_base(nb, base, dsply);
	else
		ft_putnbr_base(nb, base, &dsply[i]);
	return (dsply);
}
