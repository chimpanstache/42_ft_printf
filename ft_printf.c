/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/15 17:43:12 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	printf_p(va_list *prms) //print the address
{
	long long ptr = (long long)va_arg(*prms, void *);
	printf("%llu\n\n", ptr);
	char *base = "0123456789abcdef";
	ft_putnbr_base(ptr, base);
}

void 	printf_u(va_list *prms)	//putnbr avec limites
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	ft_putnbr_base(nb, base);
}

void 	printf_x(va_list *prms) //putnbrbase minuscule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789abcdef";
	ft_putnbr_base(nb, base);
}

void 	printf_X(va_list *prms)	//putnbr majusule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789ABCDEF";
	ft_putnbr_base(nb, base);
}

void 	printf_s(va_list *prms)
{
	char *src = va_arg(*prms, char *);

	write(1, src, ft_strlen(src));
}

void	printf_c(va_list *prms)
{
	char *chr = va_arg(*prms, char *);
	write(1, &chr, 1);
}

void	printf_d_i(va_list *prms)
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	ft_putnbr_base(nb, base);
}

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

int		ft_printf(const char *src, ...)
{
	void (*tabFunction[8]) (va_list *) = {printf_p, printf_u, printf_x, 
	printf_X, printf_s, printf_c, printf_d_i, printf_d_i};
	va_list prms;
	int i = 0;
	int index;
	int width;
	int attribute;
	int champ;
	int precision;

	va_start(prms, src);
	while (src[i]) //la on check les flags entre % et indic de conversion
	{
		if (src[i] == '%')
		{
			i++;
			if (src[i] == '-' || src[i] == '0') //caractere dáttribut
			{
				attribute = ft_attribute(src[i]);
				i++;
			}
			if ((src[i] <= '1' && src[i] <= '9') || src[i] == '*') //largeur de champ
			{
				champ = ft_champ(src[i]);
				while ('1'<= src[i] && src[i] <= '9')
					i++;
			}	
			if (src[i] == '.') //precision
			{
				i++;
				precision = ft_precision(src[i]);
				while ('1'<= src[i] && src[i] <= '9')
				i++;
			}
			ft_write(attribute, champ, precision, conv);
		i++;
	}
    return (5);
}

int main()
{
	int i = 12;
	int j = 34;
	ft_printf("rtrtt%d\n", i);
	ft_printf("%d\n%d\n", i, j);
	return (0);
}