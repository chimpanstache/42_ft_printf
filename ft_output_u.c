/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:57:03 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/16 18:26:31 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_upmst_u(char *display, int dgt, unsigned int nb, s_flags flg)
{
	int i;
	int lngth;

	i = 0;
	lngth = dgt;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	if (nb == 0 && flg.p == 0)
	{
		if (flg.c == 1)
			display[0] = ' ';
		else
			display[0] = '\0';
		return (display);
	}
	ft_itoa_custom_u(nb, display);
	return (display);
}

char	*prec_upmst_u(char *display, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flg.p;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		display[y++] = '0';
	ft_itoa_custom_pos_u(nb, &display[i]);
	return (display);
}

char	*chmp_upmst_dgt_u(char *display, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	while (y < lngth)
		display[y++] = ' ';
	if (flg.p == 0 && nb == 0)
		return (display);
	if (flg.a < 0)
		ft_itoa_custom_u(nb, display);
	else
		ft_itoa_custom_u(nb, &display[i]);
	return (display);
}

char	*chmp_upmst_dgt_u2(char *display, int dgt, unsigned int nb, s_flags flg)
{
	int lngth;
	int i;
	int y;

	lngth = flg.c;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - dgt;
	write_stuff(display, lngth, ' ');
	if (flg.a == 1 && flg.p == -1)
		write_stuff(display, i, '0');
	if (flg.p > dgt)
	{
		y = flg.c - flg.p;
		while (y <= flg.c - dgt)
			display[y++] = '0';
	}
	if (flg.a == 1 && flg.p == 0 && nb == 0)
		return (display);
	ft_itoa_custom_u(nb, &display[i]);
	return (display);
}

int		printf_u(va_list *prms, s_flags flg)
{
	unsigned int	nb;
	int				dgt;
	char			*display;
	int				p;

	nb = va_arg(*prms, unsigned int);
	dgt = countdgt_u(nb);
	if (dgt >= flg.c && dgt >= flg.p)
		display = digit_upmst_u(display, dgt, nb, flg);
	else if (flg.p >= flg.c && flg.p >= dgt)
		display = prec_upmst_u(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0)
		display = chmp_upmst_dgt_u3(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1)
		display = chmp_upmst_dgt_u2(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt)
		display = chmp_upmst_dgt_u(display, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p > dgt)
		display = chmp_upmst_prec_u(display, dgt, nb, flg);
	p = ft_strlen(display);
	write(1, display, p);
	free(display);
	return (p);
}
