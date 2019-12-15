/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/15 17:43:16 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	unsigned char c1;

	c1 = (unsigned char)c;
	write(0, &c1, 1);
}

int		ft_strlen(char *base)
{
	int i = 0;

	while (base[i])
		i++;
	return (i);
}

void			ft_putnbr_base(int n, char *base)
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

	if (str[j] == '-' && str[j + 1] != '0')
		return (NULL);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
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

int		ft_attribute(char *str)
{
	int nb;

	nb = ft_atoi(*str);
	return (nb);	
}


void 	ft_write(int attribute, int champ, int precision, int conv, char *src)
{
	char tabIndex[9] = {'p', 'u', 'x', 'X', 's', 'c', 'd', 'i', 0};
	int j;

	if (attribute > 0)	
		while(attribute != 0)	
			write(0, '0', 1);
		
	while (tabIndex[j] != 0)
		{
			if (src[i + 1] == tabIndex[j])
			{
				index = findIndex(tabIndex, src[i]);
				if (index != -1)
					(*tabFunction[index]) (&prms);
			}
			j++;			
		}
	}
	else if (src[i] != '%')
		write(1, &src[i], 1);
}

int main()
{
	printf("%d", ft_atoi("-wef"));
	return (0);
}