/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:10 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/10 20:03:13 by ehafidi          ###   ########.fr       */
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
	if (nb == 0 && flags.prec == 0)
	{
		if (flags.chmp == 1)
			display[0] = ' ';
		else 
			display[0] = '\0';
		return (display);
	}
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
	ft_putnbr_base(nb, base, &display[i]);
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
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec == 0 && nb == 0)
		return (display); 
	if (flags.att < 0)
		ft_putnbr_base(nb, base, display);
	else
		ft_putnbr_base(nb, base, &display[i]);
	return (display);
}

char	*chmp_overall_thn_dgt_x_2(char *base, char *display, int digit, unsigned int nb, s_flags flags) //regler ca
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
	if (flags.att == 1 && flags.prec == -1)
	{
		y = 0;
		while (y < i)
			display[y++] = '0';
	}
	if (flags.att == 1 && flags.prec == 0 && nb == 0)
		return (display);
	ft_putnbr_base(nb, base, &display[i]);
	return (display);
}

char	*chmp_overall_thn_dgt_x_3(char *display, int digit, unsigned int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	lngth = flags.chmp;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if(flags.prec > -1)
	{
		y = lngth - flags.prec;
		while (y < lngth)
			display[y++] = '0';
	}
	else if (flags.prec == -1)
	{
		y = 0;
		while (y < lngth)
			display[y++] = '0';
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
	display[lngth] = '\0';
	(flags.att >= 0) ? (i = lngth - digit) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_putnbr_base(nb, base, &display[flags.prec - digit]);
	else
		ft_putnbr_base(nb, base, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}

int 	printf_x(va_list *prms, s_flags flags)
{
	unsigned int nb = va_arg(*prms, unsigned int);
	int digit;
	char *display;
	char *base = "0123456789abcdef";
	int p;

	digit = countdigit_base(nb, base);
	if (digit >= flags.chmp && digit >= flags.prec)
	{
		//printf("ici\n"); //////////////////////
		display = digit_overall_x(base, display, digit, nb, flags);
	}
	else if (flags.prec >= flags.chmp && flags.prec >= digit)
	{
		//printf("ici1\n"); /////////////////
		display = prec_overall_x(base, display, digit, nb, flags);
	}
		else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.att == 1 && nb == 0)
	{
		//printf("ici333\n"); //////////////////////
		display = chmp_overall_thn_dgt_x_3(display, digit, nb, flags);
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.att == 1) 
	{
		//printf("ici2222\n");  ////////////////*******************
		display = chmp_overall_thn_dgt_x_2(base, display, digit, nb, flags); 
	}
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit) 
	{
		//printf("ici2\n");  ////////////////
		display = chmp_overall_thn_dgt_x(base, display, digit, nb, flags); 
	}
	else if ((flags.chmp >= flags.prec) && (flags.chmp >= digit) && (flags.prec > digit))
	{
		//printf("ici3\n");  ////////////////
		display = chmp_overall_thn_prec_pos_x(base, display, digit, nb, flags);
	}
	p = ft_strlen(display);
	write(1, display, ft_strlen(display));
	free(display);
	return (p);
}