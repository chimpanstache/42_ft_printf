/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:09:38 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/13 19:29:58 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall_s(char *display, int digit, char *src, s_flags flags)
{
	int y;
	int lngth;
	y = 0;
	lngth = digit;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);
	ft_memcpy(display, src, digit);
	return (display);
}

char	*chmp_over_erthing_left(char *display, int digit, char *src, s_flags flags)
{
	int y;
	y = 0;
	int lngth;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';	
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);	
	if (flags.prec < digit && flags.prec >= 0)
	{
		//printf("here\n");////////////////////	
		ft_memcpy(display, src, flags.prec);
	}
	if ((flags.prec >= digit && flags.prec >= 0) || flags.prec == -1)
	{
		//printf("hereitis\n");////////////////////
		ft_memcpy(display, src, digit);
	}
	return (display);
}

char	*chmp_over_erthing_left_2(char *display, int digit, char *src, s_flags flags)
{
	int y;
	y = 0;
	int lngth;
	lngth = -flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';	
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);	
	ft_memcpy(display, src, digit);
	return (display);
}

char	*chmp_over_erthing_right(char *display, int digit, char *src, s_flags flags)
{
	int i;
	int y;
	y = 0;
	i = 0;
	int lngth;
	lngth = flags.chmp;
	(flags.prec >= digit) ? (i = lngth - digit) : (i = lngth - flags.prec);
	//printf("%d\n", i); ////////////
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);
	if (flags.prec == -1)
	{
		ft_memcpy(display, src, digit);
		//printf("icihihi\n"); ////////////
	}
	else if (flags.prec < digit)
		ft_memcpy(&display[i], src, flags.prec);
	else if (flags.prec >= digit)
		ft_memcpy(&display[i], src, digit);
	return (display);
}
char	*chmp_over_erthing_right_2(char *display, int digit, char *src, s_flags flags)
{
	int i;
	int y;
	y = 0;
	i = 0;
	int lngth;
	lngth = flags.chmp;
	(flags.prec >= 0) ? i = lngth - flags.prec : (i = lngth - digit);
	//printf("%d\n", i); ////////////
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);
	if (flags.prec == -1)
		ft_memcpy(&display[i], src, digit);
	else if (flags.prec > digit)
		ft_memcpy(&display[lngth - digit], src, digit);
	else 
		ft_memcpy(&display[i], src, flags.prec);		
	return (display);
}

char	*chmp_thn_prec(char *display, int digit, char *src, s_flags flags)
{
	int i;
	int y;
	int lngth;
	y = 0;
	lngth = flags.chmp;
	i = lngth - flags.prec;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);
	if (flags.att < 0)
		ft_memcpy(display, src, flags.prec);
	if (flags.att == 0)
		ft_memcpy(&display[i], src, flags.prec);
	return (display);
}

char	*prec_overall_s(char *display, int digit, char *src, s_flags flags)
{
	int lngth;
	int y;

	y = 0;
	lngth = flags.prec;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	while (y < lngth)
		display[y++] = ' ';
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);
	ft_memcpy(display, src, flags.prec);
	return (display);
}

char	*chmp_neg_s(char *display, int digit, char *src, s_flags flags)
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
	if (*src == '\0' || !src || flags.prec == 0)
		return (display);	
	ft_memcpy(display, src, digit);
	return (display);
}

char *null(void)
{
	char *null;
	if (!(null = malloc(sizeof(*null) * 7)))
		return (NULL);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	return (null);
}

int	printf_s(va_list *prms, s_flags flags)
{
	char *src = va_arg(*prms, char *);
   int digit;
	char *display;
	char *src2;
	int p;

	//printf("%d%s\n", flags.prec, ": prec"); ///////////////////
	if (src == NULL)
	{
		src2 = null();
		digit = ft_strlen(src2);
	}
	else
		digit = ft_strlen(src);
	if (flags.prec < 0 && flags.chmp < digit && flags.chmp >= 0)
	{
		//printf("ici\n"); /////////////
		display = digit_overall_s(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp >= digit && flags.att < 0)
	{
		//printf("ici1\n"); /////////////
		display = chmp_over_erthing_left(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp == digit && flags.att == 0)
	{
		//printf("ici2\n"); /////////////
		display = chmp_over_erthing_right(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp > digit && flags.att == 0)
	{
		//printf("icikiwi\n"); /////////////
		display = chmp_over_erthing_right_2(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp < digit && digit <= flags.prec)
    {
		//printf("ici3\n"); /////////////
	  display = digit_overall_s(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp < digit && flags.prec < digit && flags.chmp >= flags.prec && flags.prec >= 0)
	{
		//printf("ici4\n"); /////////////
		display = chmp_thn_prec(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp < 0 && digit <= -flags.chmp)
	{
		//printf("ici6\n"); /////////////
		display = chmp_neg_s(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp < 0 && digit >= -flags.chmp)
	{
		//printf("ici6\n"); /////////////
		display = digit_overall_s(display, digit, src == NULL ? src2 : src, flags);
	}
	else if (flags.chmp < digit && flags.prec < digit && flags.chmp < flags.prec && flags.prec >= 0)
	{
		//printf("ici5\n"); /////////////
	  display = prec_overall_s(display, digit, src == NULL ? src2 : src, flags);
	}

	p = ft_strlen(display);
	//printf("%d%s\n", p, ": p"); ///////////////////
	write(1, display, p);
	free(display);
	if (src == NULL)
		free(src2);
	return (p);
}
