/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:09:38 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/20 16:27:57 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_over_chmp(char *display, int digit, char *src, s_flags flags)
{
	int i;

	i = 0;
	int lngth;
	(flags.prec < digit) ? (lngth = flags.prec) : (lngth = digit);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_memcpy(display, src, flags.prec);
	return (display);
}

char	*prec_overall_s(char *display, int digit, char *src, s_flags flags)
{
	int lngth;
	int i;
	int y;

    y = 0;
	(flags.chmp >= digit) ? (lngth = flags.chmp) : (lngth = digit);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
        ft_memcpy(display, src, digit); 
    else
        ft_memcpy(&display[lngth - digit], src, digit);
	return (display);
}

char	*chmp_overall_s_thn_prec(char *display, int digit, char *src, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;

	lngth = flags.chmp;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - flags.prec;
	while (y < lngth)
		display[y++] = ' ';
    if (flags.att < 0)
        ft_memcpy(display, src, flags.prec);
	else if (flags.prec <= digit)
        ft_memcpy(&display[i], src, flags.prec);
	return (display);
}

char	*chmp_overall_s_thn_digit(char *display, int digit, char *src, s_flags flags) //regler ca
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
	while (y < lngth)
		display[y++] = ' ';
    if (flags.att < 0)
        ft_memcpy(display, src, digit);
	else
	    ft_memcpy(&display[i], src, digit);
	return (display);
}

void 	printf_s(va_list *prms, s_flags flags)
{
	char *src = va_arg(*prms, char *);
    int digit;
	char *display;

	digit = ft_strlen(src);
	if (digit >= flags.chmp)
		display = digit_over_chmp(display, digit, src, flags);
    if (flags.prec >= flags.chmp && flags.prec >= digit)
        display = prec_overall_s(display, digit, src, flags);
    if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec >= digit)
		display = chmp_overall_s_thn_digit(display, digit, src, flags);
    if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec <= digit)
        display = chmp_overall_s_thn_prec(display, digit, src, flags);
	write(1, display, ft_strlen(display));
	//display[0] = '\0';
	free(display);
}