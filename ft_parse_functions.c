/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/10 20:09:15 by ehafidi          ###   ########.fr       */
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

void	printf_d_i(va_list *prms, int attribute, int champ, int precision) //si nb est positif
{
/*	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	int digit;
	int lngth;
	int i;
	char *display;
	int a;

	a = 0;
	i = 0;
	digit = countdigit_d_i_u(nb);
	if (digit > champ && digit > precision)
		lngth = digit;
	if (champ > precision && champ > digit)
		lngth = champ;
	if (precision > champ && precision > digit)
		nb >= 0 ? lngth = precision : lngth = precision + 1;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (digit > champ && digit > precision)
		ft_putnbr_custom(nb, display);
	if (precision > champ && precision > digit)
	{
		if (nb > 0)
		{
			i = precision - digit;
			ft_putnbr_custom(nb, display[i]);
			while (i > -1)
				display[i--] = '0';
		}
		if (nb < 0)
		{
			i = precision - digit + 1;
			ft_putnbr_custom(nb, display[i]);
			while (i > 0)
				display[i--] = '0';
			while (i > -1)
				display[i--] = '-';	
		}
	}
	if (champ > precision && champ > digit) 
	{
		if (attribute == -1)
		{
			if (precision < digit)
				ft_putnbr_custom(nb, display[i]);
			if (precision > digit)
			{
				i = precision - digit;
				ft_putnbr_custom(nb, display[i]);
				while (i > -1)
					display[i--] = '0';
			}
		}*/
		//tout ce qui est en commentaire est cense etre fini, il n'y a plus qu'a gerer qund nb est negatif et precision > digit
		if (attribute != -1)
		{
			i = champ - digit;
			ft_putnbr_custom(nb, display[i]);
			if (precision < digit)
			{
				if (nb < 0)
					display[--i] = '-';
				while (i > -1)
					display[i--] = ' ';
			}
			if (precision > digit)
			{
				while ((precision - digit) > 0)
				{
					display[i--] = '0';
					precision--;
				}
				while (i > -1)
					display[i--] = ' ';
			}
		}
	}
	ft_putstr(display);
	free(display);
}

void	printf_d_i(va_list *prms, int attribute, int champ, int precision) //si nb est negatif
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	int digit;
	int lngth;
	int i;
	char *display;
	int a;

	a = 0;
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
	if (nb < 0 && precision > champ && precision > digit)
		if (!(display = malloc(sizeof(*display) * (lngth + 2))))
			return (NULL);
	else if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (digit > champ && digit > precision)
		ft_putnbr_custom(nb, display);
	if (precision > champ && precision > digit) //to be continued
	{
		i = precision - digit;
		ft_putnbr_custom(nb, display[i]);
		while (i > -1)
			display[i--] = '0';
	}
	if (champ > precision && champ > digit) //to be continued
	{
		if (attribute == -1)
		{
			if (precision < digit)
				ft_putnbr_custom(nb, display[i]);
			if (precision > digit)
			{
				i = precision - digit;
				ft_putnbr_custom(nb, display[i]);
				while (i > -1)
					display[i--] = '0';
			}
		}
		if (attribute != -1)
		{
			i = champ - digit;
			ft_putnbr_custom(nb, display[i]);
			if (precision < digit)
				while (i > -1)
					display[i--] = ' ';
			if (precision > digit)
			{
				while ((precision - digit) > 0)
				{
					display[i--] = '0';
					precision--;
				}
				while (i > -1)
					display[i--] = ' ';
			}
		}
	}
	ft_putstr(display);
}