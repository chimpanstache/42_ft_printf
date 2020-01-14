/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/14 19:36:59 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;

	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_putnbr_custom(nb, display);
	return (display);
}

char	*prec_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;

	nb >= 0 ? (lngth = flags.prec) : (lngth = flags.prec + 1);
	//printf("%d%s\n", lngth, ": size lngth"); //////////////
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	//printf("%d%s\n", lngth, ": size lngth"); //////////////	
	display[lngth] = '\0';
	i = lngth - digit;
	ft_putnbr_custom_pos(nb, &display[i]);
	while (i > -1)
			display[--i] = '0';
	if (nb < 0) 
		display[0] = '-';
		//printf("%d%s\n", ft_strlen(display), ": size display"); //////////////////////////////////
	return (display);
}

char	*chmp_overall_thn_dgt(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;

	lngth = flags.chmp;
	nb >= 0 ? (digit = digit) : digit++;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit; 
	if (flags.att < 0)
		ft_putnbr_custom(nb, display);
	else	
		ft_putnbr_custom(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_prec(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;

	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; ///////
	i = lngth - digit;
	if (flags.att < 0)
	{
		if (nb >= 0)
			ft_putnbr_custom(nb, &display[flags.prec - digit]);
		else if (nb < 0)
			ft_putnbr_custom(nb, &display[flags.prec - digit + 1]);
	}
	else
		ft_putnbr_custom(nb, &display[i]);
	while ((flags.prec - digit) > 0)
	{
		display[i--] = '0';
		digit--;
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
		display = chmp_overall_thn_dgt(display, digit, nb, flags);
	if (flags.chmp > flags.prec && flags.chmp > digit && flags.prec > digit)
		display = chmp_overall_thn_prec(display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	display[0] = '\0';
	free(display);
}
