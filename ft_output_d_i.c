/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/10 16:42:54 by ehafidi          ###   ########.fr       */
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
	if (nb == 0 && flags.prec == 0)
	{
		if (flags.chmp == 1)
			display[0] = ' ';
		else 
			display[0] = '\0';
		return (display);
	}
	ft_itoa_custom(nb, display);
	return (display);
}

char	*prec_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	(nb >= 0) ? (lngth = flags.prec) : (lngth = flags.prec + 1);
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

char	*chmp_neg_prec_pos(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	-flags.chmp >= flags.prec ? lngth = -flags.chmp : (lngth = -flags.chmp + 1);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flags.prec - digit;
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_itoa_custom_pos(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_neg_prec_pos_nb_neg(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	(-flags.chmp <= flags.prec) ? (lngth = flags.prec + 1): (lngth = -flags.chmp);
	if (digit >= -flags.chmp && -flags.chmp > flags.prec)
		lngth++;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	(nb >= 0) ? (i = flags.prec - digit) : (i = flags.prec - digit + 1);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_overall_thn_dgt_pos(char *display, int digit, int nb, s_flags flags) //regler ca
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
	y = 0;
	if (flags.prec < 0 && flags.att > 0)
		while (y < lngth)
			display[y++] = '0';
	if (flags.prec == 0 && nb == 0)
		return (display); 
	if (flags.att < 0)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_dgt_neg(char *display, int digit, int nb, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;

	++digit;
	lngth = flags.chmp;
	if (nb < 0 && digit == flags.chmp + 1)
		lngth = digit;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = ' ';
	y = 0;	
	if (flags.att > 0 && nb < 0 && flags.prec < 0)
	{
		while (y < lngth)
			display[y++] = '0';
		display[0] = '-';	
		ft_itoa_custom_pos(nb, &display[lngth - digit + 1]);
	}
	else if (flags.att < 0)
		ft_itoa_custom(nb, display);
	else 
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_prec_pos(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	//printf("ici5\n"); ////////////////
	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; ///////
	(flags.att >= 0) ? (i = lngth - digit) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_itoa_custom(nb, &display[flags.prec - digit]);
	else
		ft_itoa_custom(nb, &display[i]);
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
		ft_itoa_custom_pos(nb, &display[flags.prec - digit + 1]);
	else
		ft_itoa_custom_pos(nb, &display[i + 1]);
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

int	printf_d_i(va_list *prms, s_flags flags) 
{
	int nb = va_arg(*prms, int);
	int digit;
	char *display;
	int p;

	digit = countdigit_d_i(nb);
	if (digit >= flags.chmp && digit >= flags.prec && flags.chmp >= 0)
	{
		//printf("icicoucou\n");  ///////////////////////////******************
		display = digit_overall(display, digit, nb, flags);
	}
	else if (flags.chmp < 0 && nb >= 0) 
	{
		//printf("ici\n");  ///////////////////////////
		display = chmp_neg_prec_pos(display, digit, nb, flags);
	}
	else if (flags.chmp < 0 && nb < 0) 
	{
		//printf("ici1\n"); //////////////////////////
		display = chmp_neg_prec_pos_nb_neg(display, digit, nb, flags);
	}
	else if (flags.prec >= flags.chmp && flags.prec >= digit)
	{
		//printf("ici2\n");  /////////////////////////////
		display = prec_overall(display, digit, nb, flags);
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit && nb >= 0) 
	{
		//printf("ici3\n");  //////////////////////////////
		display = chmp_overall_thn_dgt_pos(display, digit, nb, flags);
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit && nb < 0) 
	{
		//printf("ici4\n");  //////////////////////////
		display = chmp_overall_thn_dgt_neg(display, digit, nb, flags);
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit && nb >= 0)
	{
		//printf("ici5\n");	////////////////////////////
		display = chmp_overall_thn_prec_pos(display, digit, nb, flags);
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit && nb < 0)
	{
		//printf("ici6\n");  ////////////////////////////
		display = chmp_overall_thn_prec_neg(display, digit, nb, flags);
	}
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	return (p);
}
