/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:21:54 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/11 21:50:18 by ehafidi          ###   ########.fr       */
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
	if (chr == '\0' || !chr)
	{	
		display[lngth - 1] = '\0';
		return (display);
	}
	if (flags.att < 0)
		display[0] = chr;
	else
		display[lngth - 1] = chr;
	return (display);
}

char	*put_c_neg(char *display, char chr, s_flags flags)
{
	int lngth;
	int y;

	y = 0;
	lngth = -flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (chr == '\0' || !chr)
		return (display);
	display[0] = chr;
	return (display);
}

int	printf_c(va_list *prms, s_flags flags)
{
	char chr = va_arg(*prms, int);
	int p;
	char *display;
	//printf("ici\n"); //////////////////////
	if (flags.chmp > 1)
	{
		//printf("ici\n"); ///////////////////////
		display = put_c(display, chr, flags);
	}
	else if (flags.chmp < -1)
		display = put_c_neg(display, chr, flags);
	else
	{
		//printf("ici\n"); //////////////////////
		write(1, &chr, 1);
		//free (display);
		return (1);
	}
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	//printf("%d%s\n", p, ": pppp"); ////////////////////// 
	return (p);
}
