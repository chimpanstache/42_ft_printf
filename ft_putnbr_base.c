/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/18 18:53:19 by ehafidi          ###   ########.fr       */
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

int		ft_attribute(char *str)
{
	int att;
	int i;

	i = 0;
	if (str[i] == '-')
		att = -1;
	else
		att = 1;
	return (att);
}

int		ft_champ(char *str, va_list *prms)
{
	int i;
	int champ;

	i = 0;
	if (str[i] == '*')
	{
		champ = va_arg(*prms, int);
		return (champ);
	}
	champ = ft_atoi(str);
	return (champ);
}

int 	ft_precision(char *str)
{
	int prec;

	prec  = ft_atoi(str);
	return (prec);
}

void 	ft_write(int attribute, int champ, int precision, va_list *prms)
{
	char tabIndex[9] = {'p', 'u', 'x', 'X', 's', 'c', 'd', 'i', 0};
	int j;
	int conv;

	if (precision > 

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
	else if (src[i] != '%')
		write(1, &src[i], 1);
}

int 	count_digit_p(va_list *prms) //print the address
{
	long long ptr = (long long)va_arg(*prms, void *);
	char *base = "0123456789abcdef";
	ft_putnbr_base(ptr, base);
}

int 	count_digit_X_x(va_list *prms)	//putnbr majusule
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789ABCDEF";
	int length;
	char *str;
	int i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (count_digit_d_i(nb) + 1))))
	{
		free(str);
		return (NULL);	
	}
	if (nb < 0)
	{
		nb = -nb;
		str[i++] = '-';
	}
	while (nb > 9)
	{
		nb /= 16;
		str[i++] = base[nb % ft_strlen(base)];
	}	
	free(str);
	return (i);
}

int 	strlen_s(va_list *prms)
{
	int length;
	char *src = va_arg(*prms, char *);
	length = ft_strlen(src);
	return(length);
}

int	countdigit_d_i_u(va_list *prms)
{
	int nb = va_arg(*prms, int);
	int digit = 0;
	if (nb < 0)
	{
		digit++;
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

//pas de countdigit_c car forcement 1 digit 

int 	findIndex(char *arr, char element)
{
	int i = 0;

	while (arr[i])
	{
		if (arr[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

/*int main()
{
	printf("%d", ft_atoi("-wef"));
	return (0);
}*/