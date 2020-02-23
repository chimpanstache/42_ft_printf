/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:44:08 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/23 13:58:36 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_no_diggity(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void		ft_itoa_custom_pos(int n, char *arr)
{
	unsigned int	nb;
	int				len;

	
	len = count_no_diggity(n);
	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	//printf("entree de fonction() aveec arr = |%s| et len |%d|\n", arr, len);
	while (len-- > 0)
	{
		//printf("on essaye decrire dans arr[%d] ca : |%u|\n", len, nb % 10 + '0');
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}

	//printf("sorti de fonction()\n");
}

void		ft_ulltoa_base(unsigned long long n, char *arr, char *base)
{
	int		len;
	int		lenny;

	len = countdgt_base(n, base);
	lenny = ft_strlen(base);
	while (len-- > 0)
	{
		arr[len] = base[n % lenny];
		n = n / lenny;
	}
}

void		ft_itoa_custom(int n, char *arr)
{
	unsigned int		nb;
	int					sign;
	int					len;

	sign = 0;
	len = count_no_diggity(n);
	if (n < 0)
	{
		len++;
		sign = 1;
		nb = (unsigned int)(n * -1);
		*arr = '-';
	}
	else
		nb = (unsigned int)n;
	while (len-- > sign)
	{
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
}

char		*null(void)
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
