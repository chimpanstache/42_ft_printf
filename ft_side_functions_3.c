/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:58:08 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/19 20:34:03 by ehafidi          ###   ########.fr       */
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
	//printf("ici\n"); ///////////////////////////

	write(1, &src[ind->i++], 1);
	ind->a++;
}
