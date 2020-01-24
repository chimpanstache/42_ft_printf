/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_XX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:15 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/24 15:20:06 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	printf_X(va_list *prms, s_flags flags)
{
	unsigned int nb = va_arg(*prms, unsigned int);
	int digit;
	char *display;
	char *base = "0123456789ABCDEF";

	digit = countdigit_base(nb, base);
	if (digit >= flags.chmp && digit >= flags.prec)
		display = digit_overall_x(base, display, digit, nb, flags);
	if (flags.prec >= flags.chmp && flags.prec >= digit)
		display = prec_overall_x(base, display, digit, nb, flags);
	if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit) 
		display = chmp_overall_thn_dgt_x(base, display, digit, nb, flags); 
	if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit)
		display = chmp_overall_thn_prec_pos_x(base, display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	free(display);
}