/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/20 13:14:31 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall(char *display, int digit, int nb, s_flags flags)
{
	int i;

	i = 0;
	int lngth;
	nb >= 0 ? (lngth = digit) : (lngth = digit + 1);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_itoa_custom(nb, display);
	return (display);
}

char	*prec_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	nb >= 0 ? (lngth = flags.prec) : (lngth = flags.prec + 1);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = '0';
	ft_itoa_custom_pos(nb, &display[i]);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_overall_thn_dgt(char *display, int digit, int nb, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;

	lngth = flags.chmp;
	y = 0;
	nb >= 0 ? (digit = digit) : (digit = digit + 1);
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	if (flags.att < 0)
	{
		while (y < lngth)
			display[y++] = ' ';
		ft_itoa_custom(nb, display);
	}
	else
	{
		while (y < lngth)
			display[y++] = ' ';
		ft_itoa_custom(nb, &display[i]);
	}
	return (display);
}

char	*chmp_overall_thn_prec_pos(char *display, int digit, int nb, s_flags flags)
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
		ft_itoa_custom_pos(nb, &display[flags.prec - digit]);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}

char	*chmp_overall_thn_prec_neg(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
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
		ft_itoa_custom_pos(nb, &display[flags.prec - digit]);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[i--] = '0';
		y++;
	}
	if (nb < 0)
		display[i--] = '-';
	return (display);
}

void 	printf_d_i(va_list *prms, s_flags flags) //separation de l'algo en fonction des situations
{
	int nb = va_arg(*prms, int);
	int digit;
	char *display;

	digit = countdigit_d_i_u(nb);
	if (digit > flags.chmp && digit > flags.prec)
		display = digit_overall(display, digit, nb, flags);
	if (flags.prec > flags.chmp && flags.prec > digit)
		display = prec_overall(display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec < digit) 
		display = chmp_overall_thn_dgt(display, digit, nb, flags); //fonctionne pas si nb negatif
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec > digit && nb >= 0)
		display = chmp_overall_thn_prec_pos(display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec > digit && nb < 0)
		display = chmp_overall_thn_prec_neg(display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	//display[0] = '\0';
	free(display);
}
