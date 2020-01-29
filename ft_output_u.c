/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:57:03 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/29 15:59:37 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall_u(char *display, int digit, unsigned int nb, s_flags flags)
{
	int i;
	//printf("ici1\n"); ////////////////////////
	i = 0;
	int lngth;
	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_itoa_custom_u(nb, display);
	return (display);
}

char	*prec_overall_u(char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;
	//printf("ici2\n"); ////////////////////////
	y = 0;
	lngth = flags.prec;
	//printf("%d%s\n", flags.prec, ": prec"); ////////////////////////
	//printf("%d%s\n", lngth, ": lngth"); ////////////////////////
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = '0';
	ft_itoa_custom_pos_u(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_dgt_u(char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;
	//printf("ici3\n"); ////////////////////////
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
		ft_itoa_custom_u(nb, display);
	}
	else
	{
		while (y < lngth)
			display[y++] = ' ';
		ft_itoa_custom_u(nb, &display[i]);
	}
	return (display);
}

char	*chmp_overall_thn_prec_pos_u(char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;
	//printf("ici4\n"); ////////////////////////
	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; ///////
	(flags.att >= 0) ? (i = lngth - digit) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_itoa_custom_pos_u(nb, &display[flags.prec - digit]);
	else
		ft_itoa_custom_pos_u(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}


void 	printf_u(va_list *prms, s_flags flags)	//putnbr avec limites
{
	unsigned int nb = va_arg(*prms, unsigned int);
	int digit;
	char *display;
	//printf("ici\n"); ////////////////////////
	digit = countdigit_u(nb);
	//printf("%d%s\n", digit, ": digit"); ////////////////////////
	if (digit >= flags.chmp && digit >= flags.prec)
		display = digit_overall_u(display, digit, nb, flags);
	if (flags.prec >= flags.chmp && flags.prec >= digit)
		display = prec_overall_u(display, digit, nb, flags);
	if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit) 
		display = chmp_overall_thn_dgt_u(display, digit, nb, flags); //fonctionne pas si nb negatif
	if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit)
		display = chmp_overall_thn_prec_pos_u(display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	//display[0] = '\0';
	free(display);
}