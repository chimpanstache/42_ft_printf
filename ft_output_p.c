/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:53 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/13 19:30:25 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*put_p(char *display, unsigned long long ptr, char *base, int digit, s_flags flags)
{
	int lngth;
	int y;
	int i;

	y = 0;
	i = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
	{	 
		//printf("ici\n"); ////////////////////////
		display[0] = '0';
		display[1] = 'x';
			ft_ulltoa_base(ptr, &display[2], base);
	}
	else
	{
		//printf("ici\n"); ////////////////////////
		if (!ptr && flags.prec == 0)
		{
			display[lngth - 2] = '0';
			display[lngth - 1] = 'x';
		}
		else
		{
			display[lngth - digit] = '0';
			display[lngth - digit + 1] = 'x';
			ft_ulltoa_base(ptr, &display[lngth - digit + 2], base);
		}
	}
	return (display);
}

char	*put_p2(char *display, unsigned long long ptr, char *base, int digit, s_flags flags)
{
	int lngth;
	int y;
	int i;

	y = 0;
	i = 0;
	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	display[0] = '0';
	display[1] = 'x';
	ft_ulltoa_base(ptr, &display[2], base);
	return (display);
}

int 	printf_p(va_list *prms, s_flags flags)
{
	int digit;
	unsigned long long ptr = va_arg(*prms, unsigned long long);
	char *base = "0123456789abcdef";
	char *display;
	int p;

	printf("%d%s\n", flags.prec, ": prec"); ///////////////////
	p = 0;
	digit = countdigit_base(ptr, base) + 2;
	if (flags.chmp > digit)
		display = put_p(display, ptr, base, digit, flags);
	else
		display = put_p2(display, ptr, base, digit, flags);
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	return (p);
}