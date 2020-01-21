/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:21:54 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/21 15:52:02 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*put_c(char *display, char *chr, s_flags flags)
{
	int lngth;
	int y;

	y = 0;
	lngth = flags.chmp;
	printf("%d\n", flags.chmp);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	
	while (y < lngth)
		display[y++] = ' ';
	
	if (flags.att < 0)
	{
		//printf("ici\n");
		ft_memcpy(display, chr, 1);
		
	}
	else
	{
		//printf("ici\n");	
		ft_memcpy(&display[lngth - 1], chr, 1);
		printf("ici\n");
	}
	return (display);
}

void	printf_c(va_list *prms, s_flags flags)
{
	char *chr = va_arg(*prms, char *);
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