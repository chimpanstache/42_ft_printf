/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/11 15:44:37 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void 	printf_p(va_list *prms, s_flags flags) //print the address, faire process de prec, champ et att directement dans fonction.
{
	long long ptr = (long long)va_arg(*prms, void *);
	printf("%llu\n\n", ptr);
	char *base = "0123456789abcdef";
	ft_putnbr_base(ptr, base);
}

void 	printf_u(va_list *prms, s_flags flags)	//putnbr avec limites
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	ft_putnbr_base(nb, base);
}

void 	printf_x(va_list *prms, s_flags flags) //putnbrbase minuscule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789abcdef";
	ft_putnbr_base(nb, base);
}

void 	printf_X(va_list *prms, s_flags flags)	//putnbr majusule
{
	unsigned int nb = va_arg(*prms, unsigned int);
	char *base = "0123456789ABCDEF";
	ft_putnbr_base(nb, base);
}

void 	printf_s(va_list *prms, s_flags flags)
{
	char *src = va_arg(*prms, char *);

	write(1, src, ft_strlen(src));
}

void	printf_c(va_list *prms, s_flags flags)
{
	char *chr = va_arg(*prms, char *);
	write(1, &chr, 1);
}

char	*digit_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;

	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';

}

void 	printf_d_i(va_list *prms, s_flags flags) //separation de l'algo en fonction des situations
{
	int nb = va_arg(*prms, int);
	int digit;
	char *display;
	
	digit = countdigit_d_i_u(nb);
	if (digit > flags.chmp && digit > flags.prec)
		display = digit_overall(display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit)
		display = chmp_overall(display, digit, nb, flags);
	if (flags.prec > flags.chmp && flags.prec > digit && nb >= 0)
		display = prec_overall_pos(display, digit, nb, flags);
	if (flags.prec > flags.chmp && flags.prec > digit && nb < 0)
		display = prec_overall_neg(display, digit, nb, flags);
	ft_putstr(display);
	free(display);
}

void	printf_d_i_pos(va_list *prms, s_flags flags) //remplacer les champs
{
	int nb = va_arg(*prms, int);
	int digit;
	int lngth;
	int i;
	char *display;
	int a;

	a = 0;
	i = 0;
	digit = countdigit_d_i_u(nb);
	if (digit > flags.chmp && digit > flags.prec)
		lngth = digit;
	if (flags.chmp > flags.prec && flags.chmp > digit)
		lngth = flags.chmp;
	if (flags.prec > flags.chmp && flags.prec > digit)
		lngth = flags.prec;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (digit > flags.chmp && digit > flags.prec)
		ft_putnbr_custom(nb, display);
	if (flags.prec > flags.chmp && flags.prec > digit) 
	{
		i = flags.prec - digit;
		ft_putnbr_custom(nb, display[i]);
		while (i > -1)
			display[i--] = '0';
	}
	if (flags.chmp > flags.prec && flags.chmp > digit) 
	{
		if (flags.att == -1)
		{
			if (flags.prec < digit)
				ft_putnbr_custom(nb, display[i]);
			if (flags.prec > digit)
			{
				i = flags.prec - digit;
				ft_putnbr_custom(nb, display[i]);
				while (i > -1)
					display[i--] = '0';
			}
		}
		if (flags.att != -1)
		{
			i = flags.chmp - digit;
			ft_putnbr_custom(nb, display[i]);
			if (flags.prec < digit)
				while (i > -1)
					display[i--] = ' ';
			if (flags.prec > digit)
			{
				while ((flags.prec - digit) > 0)
				{
					display[i--] = '0';
					flags.prec--;
				}
				while (i > -1)
					display[i--] = ' ';
			}
		}
	}
	if (nb < 0)
	{
		free(display);
		display = printf_d_i_neg(nb, flags);///pas bon car flags modifies 
	}
	ft_putstr(display);
	free(display);
}

char	*printf_d_i_neg(int nb, s_flags flags)
{
	int digit;
	int lngth;
	int i;
	char *display;
	int a;

	a = 0;
	i = 0;
	digit = countdigit_d_i_u(nb);
	if (digit > flags.chmp && digit > flags.prec)
		lngth = digit + 1;
	if (flags.prec > flags.chmp && flags.prec > digit)
		lngth = flags.prec + 1;
	if (flags.chmp > flags.prec && flags.chmp > digit)
		lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (digit > flags.chmp && digit > flags.prec)
		ft_putnbr_custom_neg(nb, display);
	if (flags.prec > flags.chmp && flags.prec > digit)
	{
		i = flags.prec - digit + 1;
		ft_putnbr_custom(nb, display[i]);
		while (i > 0)
			display[i--] = '0';
		while (i > -1)
			display[i--] = '-';
	}
	if (flags.chmp > flags.prec && flags.chmp > digit)
	{
		if (flags.att == -1)
		{
			if (flags.prec < digit)
			{
				ft_putnbr_custom_neg(nb, display);
				while (*display)
				{
					display = ' ';
					display++;
				}
			}
			if (flags.prec > digit)
			{
				i = flags.prec - digit + 1;
				ft_putnbr_custom(nb, display[i]);
				while (i > 0)
					display[i--] = '0';
				while (i > -1)
					display[i--] = '-';
			}
		}
		if (flags.att != -1) /// >= 0
		{
			i = flags.chmp - digit;
			ft_putnbr_custom(nb, display[i]);
			if (flags.prec < digit)
			{
				display[i--] = '-';
				while (i > -1)
					display[i--] = ' ';
			}
			if (flags.prec > digit)
			{
				while ((flags.prec - digit) > 0)
				{
					display[i--] = '0';
					flags.prec--;
				}
				display[i--] = '-';
				while (i > -1)
					display[i--] = ' ';
			}
		}
	}
	return (display);
}

