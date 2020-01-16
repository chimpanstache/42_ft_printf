/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/16 19:13:21 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *str, size_t len)
{
	unsigned int	i;
	char			*copy;

	if (!(copy = malloc(sizeof(*copy) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_putnbr_custom_pos(int n, char *src)
{
	unsigned int nb;
	static int i = 0;
	int y;

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

void	ft_putnbr_custom(int n, char *src) //fonctionne pas avec les negatifs
{
	unsigned int nb;
	static int i = 0;
	int y;

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

int		ft_strlen(char *base)
{
	int i = 0;

	while (base[i])
		i++;
	return (i);
}

void		ft_putnbr_base(int n, char *base)
{
	unsigned int nb;
	int a;

	a = ft_strlen(base);
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		write(0, "-", 1);
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_base((nb / a), base);
	write(0, &base[nb % a], 1);
}

int		ft_atoi(const char *str)
{
	long i;
	long nb;
	int j;

	i = 0;
	nb = 0;
	if (*str == '-')
	{
		i++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if (nb > LONG_MAX || nb < 0)
			return (i > 0) ? 0 : -1;
	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}

int	countdigit_d_i_u(int nb)
{
	int digit = 1;
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb <= 9)
		return(++digit); 		
	while (nb > 9)
	{
		nb /= 10;
		digit++;
	}	
	return(digit);
}
