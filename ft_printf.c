/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/18 18:52:30 by ehafidi          ###   ########.fr       */
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
	va_list prms;
	int i = 0;
	int attribute = 0;
	int champ = 0;
	int precision = 0;
	int conv;

	va_start(prms, src);
	while (src[i]) //la on check les flags entre % et indic de conversion
	{
		if (src[i] == '%')
		{
			i++;
			if (src[i] == '-' || src[i] == '0') //caractere dáttribut
			{	
				attribute = ft_attribute((char *)&src[i]); // uste gerer le 0 ou le -
				i++;
				if (src[i] == '-' && src[i - 1] == 0)
				{
					attribute = ft_attribute((char *)&src[i]);
					i++;
				}
				printf("%d%s\n", attribute, ": attribute");	//////////////////////
			}
			if ((src[i] >= '1' && src[i] <= '9') || src[i] == '*') //largeur de champ
			{
				champ = ft_champ((char *)&src[i], &prms);
				i++;
				while ('0' <= src[i] && src[i] <= '9')
					i++;
				printf("%d%s\n", champ, ": champ");
			}	
			if (src[i] == '.') //precision
			{
				i++;
				precision = ft_precision((char *)&src[i]);
				while ('0' <= src[i] && src[i] <= '9')
					i++;
				printf("%d%s\n", precision, ": precision"); 
			}
		}
		i++;
	}
	ft_write()
	printf("%s\n", "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"); 
    return (5);
}

int main()
{
	int age = 12;
	int khey = 32;
	ft_printf("%-10.5d:\n", age);
	ft_printf("%.10d:\n", age);
	ft_printf("%010d:\n", age);
	ft_printf("%10.d:\n", age);
	ft_printf("%d:\n", age);
	ft_printf("%010.5d:\n", age);
	ft_printf("%-10d:\n", age);
	ft_printf("%-10.5d:\n", age);
	ft_printf("%-10.3d:\n", age);
	ft_printf("%2d:\n", age);
	ft_printf("%50d:\n", age);
	ft_printf("%*d:\n", khey, age);
	return (0);
}