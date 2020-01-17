/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/17 16:33:26 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall_x(char *base, char *display, int digit, unsigned int nb, s_flags flags)
{
	int i;

	i = 0;
	int lngth;
	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_putnbr_base(nb, base, display);
	return (display);
}

char	*prec_overall_x(char *base, char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flags.prec;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = '0';
	ft_putnbr_base(nb, base, &display[i + 1]);
	return (display);
}

char	*chmp_overall_thn_dgt_x(char *base, char *display, int digit, unsigned int nb, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;

	lngth = flags.chmp;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	if (flags.att < 0)
	{
		while (y < lngth)
			display[y++] = ' ';
		ft_putnbr_base(nb, base, display);
	}
	else
	{
		while (y < lngth)
			display[y++] = ' ';
		ft_putnbr_base(nb, base, &display[i + 1]);
	}
	return (display);
}

char	*chmp_overall_thn_prec_pos_x(char *base, char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; ///////
	(flags.att >= 0) ? (i = lngth - digit) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_putnbr_base(nb, base, &display[flags.prec - digit + 1]);
	else
		ft_putnbr_base(nb, base, &display[i + 1]);
	y = 0;
	while (y <= (flags.prec - digit))
	{
		display[i--] = '0';
		y++;
	}
	return (display);
}

char	*chmp_overall_thn_prec_neg_x(char *base, char *display, int digit, unsigned int nb, s_flags flags)
{
/*	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; 
	(flags.att >= 0) ? (i = lngth - digit - 1) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_putnbr_base(nb, base, &display[flags.prec - digit + 1]);
	else
		ft_putnbr_base(nb, base, &display[i + 1]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[i--] = '0';
		y++;
	}
	if (nb < 0)
		display[i--] = '-';
	*/return (display);
}

void 	printf_x(va_list *prms, s_flags flags)
{
	int nb = va_arg(*prms, int);
	int digit;
	char *display;
	char *base = "0123456789abcdef";

	digit = countdigit_d_i_u(nb);
	if (digit > flags.chmp && digit > flags.prec)
		display = digit_overall_x(base, display, digit, nb, flags);
	if (flags.prec > flags.chmp && flags.prec > digit)
		display = prec_overall_x(base, display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec < digit) 
		display = chmp_overall_thn_dgt_x(base, display, digit, nb, flags); 
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec > digit && nb >= 0)
		display = chmp_overall_thn_prec_pos_x(base, display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec > digit && nb < 0)
		display = chmp_overall_thn_prec_neg_x(base, display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	free(display);
}