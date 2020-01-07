/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/07 15:25:57 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void 	printf_p(va_list *prms, int attribute, int champ, int precision) //print the address, faire process de prec, champ et att directement dans fonction.
{
	long long ptr = (long long)va_arg(*prms, void *);
	printf("%llu\n\n", ptr);
	char *base = "0123456789abcdef";
	ft_putnbr_base(ptr, base);
}

void 	printf_u(va_list *prms, int attribute, int champ, int precision)	//putnbr avec limites
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	ft_putnbr_base(nb, base);
}

void 	printf_x(va_list *prms, int attribute, int champ, int precision) //putnbrbase minuscule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789abcdef";
	ft_putnbr_base(nb, base);
}

void 	printf_X(va_list *prms, int attribute, int champ, int precision)	//putnbr majusule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789ABCDEF";
	ft_putnbr_base(nb, base);
}

void 	printf_s(va_list *prms, int attribute, int champ, int precision)
{
	char *src = va_arg(*prms, char *);

	write(1, src, ft_strlen(src));
}

void	printf_c(va_list *prms, int attribute, int champ, int precision)
{
	char *chr = va_arg(*prms, char *);
	write(1, &chr, 1);
}

void	printf_d_i(va_list *prms, int attribute, int champ, int precision)
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	int digit;
	int lngth;
	int i;
	char *display;

	i = 0;
	digit = countdigit_d_i_u(nb);
	if (digit > champ && digit > precision)
		lngth = digit;
	if (champ > precision && champ > digit)
		lngth = champ;	
	if (precision > champ && precision > digit)
		lngth = precision;
	if (precision > champ && nb < 0)
		lngth++; 
	if (!(display = malloc(sizeof(display) * (lngth + 1))))
		return (NULL);
	/*if (attribute == -1)
		write left;
	if (attribute == 0)
		write right;
	if (attribute == 1)
		write 0;*/	
	if (precision > digit)
	{	
		i = precision - digit;
		while 
	}	

}