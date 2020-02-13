/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_%.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:48:33 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/13 16:11:08 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*display_overall_perc(char *display, s_flags flags)
{
    if (!(display = malloc(sizeof(*display) * (1 + 1))))
		return (NULL);
    display[0] = '%';
    display[1] = '\0';
    return (display);
}

char	*chmp(char *display, s_flags flags)
{
    int lngth;
    int y;

    lngth = flags.chmp;
    if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
    display[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	display[y++] = ' ';
    display[lngth - 1] = '%';
    return (display);
}

char	*chmp_and_att_neg(char *display, s_flags flags)
{
    int lngth;
    int y;

    lngth = flags.chmp;
    if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
    display[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	display[y++] = ' ';
    display[0] = '%';
    return (display);
}

char	*chmp_and_att_0(char *display, s_flags flags)
{
    int lngth;
    int y;

    lngth = flags.chmp;
    if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
    display[lngth] = '\0';
    y = 0;
    while (y < lngth)
    	display[y++] = '0';
    display[lngth - 1] = '%';
    return (display);
}

int	printf_percent(va_list *prms, s_flags flags)
{
	//char chr = va_arg(*prms, int);
  //printf("%d\n", chr);
	int p;
    char *display;
	//printf("ici\n"); ////////////////
	if (flags.chmp < 2)
    display = display_overall_perc(display, flags);
  if (flags.chmp > 1 && flags.att == 0)
		display = chmp(display, flags);
  if (flags.chmp > 1 && flags.att == -1)
		display = chmp_and_att_neg(display, flags);
  if (flags.chmp > 1 && flags.att == 1)
		display = chmp_and_att_0(display, flags);
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	//printf("%d%s\n", p, ": p"); ////////////////////
	return (p);
}