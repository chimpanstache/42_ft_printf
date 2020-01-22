/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:53 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/22 20:01:01 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	printf_p(va_list *prms, s_flags flags) //print the address, faire process de prec, champ et att directement dans fonction.
{
	int digit;
	unsigned long long ptr = (long long)va_arg(*prms, unsigned long long);
	char *base = "0123456789abcdef";

	//write(1, "0x", 2);
	digit = countdigit_p(ptr, base) + 2;
	//printf("%d%s\n", digit, ": digit");
	if (flags.chmp > digit)
	{
		char *display;

		display = put_p(display, ptr, base, digit, flags);
		write(1, display, ft_strlen(display));
		free(display);
	}
	else
	{
		write(1, "0x", 2);
		ft_putnbr_base_p(ptr, base);
	}
}

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
		display[0] = '0';
		display[1] = 'x';
		ft_ulltoa_base(ptr, &display[2], base);
	}
	else
	{
		display[lngth - digit] = '0';
		display[lngth - digit + 1] = 'x';
		ft_ulltoa_base(ptr, &display[lngth - digit + 2], base);
	}
	return (display);
}
						