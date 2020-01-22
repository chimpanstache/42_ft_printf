/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:21:54 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/22 12:36:48 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*put_c(char *display, char chr, s_flags flags)
{
	int lngth;
	int y;

	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		display[0] = chr;
	else
		display[lngth - 1] = chr;
	return (display);
}

void	printf_c(va_list *prms, s_flags flags)
{
	char chr = va_arg(*prms, int);

	if (flags.chmp > 1)
	{
		char *display;

		display = put_c(display, chr, flags);
		write(1, display, ft_strlen(display));
		free(display);
	}
	else
		write(1, &chr, 1);
}