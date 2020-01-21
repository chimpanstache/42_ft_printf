/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:09:38 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/21 13:10:30 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*chmp_over_erthing_left(char *display, int digit, char *src, s_flags flags)
{
	int y;

	y = 0;
	int lngth;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_memcpy(display, src, flags.prec);
	if (flags.prec >= digit)
		ft_memcpy(display, src, digit);
	return (display);
}

char	*chmp_over_erthing_right(char *display, int digit, char *src, s_flags flags)
{
	int i;
	int y;

	y = 0;
	i = 0;
	int lngth;
	lngth = flags.chmp;
	(flags.prec >= digit) ? (i = lngth - digit) : (i = lngth - flags.prec);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_memcpy(&display[i], src, flags.prec);
	if (flags.prec >= digit)
		ft_memcpy(&display[i], src, digit);
	return (display);
}

char	*digit_overall_s(char *display, int digit, char *src, s_flags flags)
{
	int y;
	int lngth;

	y = 0;
	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	ft_memcpy(display, src, digit);
	return (display);
}

char	*chmp_thn_prec(char *display, int digit, char *src, s_flags flags)
{
	int i;
	int y;
	int lngth;

	y = 0;
	i = lngth - flags.prec;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_memcpy(display, src, flags.prec);
	if (flags.prec == 0)
		ft_memcpy(&display[i], src, flags.prec);
	return (display);
}

char	*prec_overall_s(char *display, int digit, char *src, s_flags flags)
{
	int lngth;

	lngth = flags.prec;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_memcpy(display, src, flags.prec);
	return (display);
}

void 	printf_s(va_list *prms, s_flags flags)
{
	char *src = va_arg(*prms, char *);
    int digit;
	char *display;

	digit = ft_strlen(src);
	if (flags.chmp >= digit && flags.att < 0)
		display = chmp_over_erthing_left(display, digit, src, flags);
	if (flags.chmp >= digit && flags.att == 0)
		display = chmp_over_erthing_right(display, digit, src, flags);
    if (flags.chmp < digit && digit <= flags.prec)
        display = digit_overall_s(display, digit, src, flags);
    if (flags.chmp < digit && flags.prec < digit && flags.chmp >= flags.prec)
		display = chmp_thn_prec(display, digit, src, flags);
    if (flags.chmp < digit && flags.prec < digit && flags.chmp < flags.prec)
        display = prec_overall_s(display, digit, src, flags);
	write(1, display, ft_strlen(display));
	free(display);
}

