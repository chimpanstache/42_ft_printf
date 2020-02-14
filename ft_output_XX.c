/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_XX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:36:15 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:24 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	printf_X(va_list *prms, s_flags flg)
{
	unsigned long long nb = va_arg(*prms, unsigned long long);
	int dgt;
	char *dsply;
	char *base = "0123456789ABCDEF";
	int p;

	dgt = countdgt_base(nb, base);
	if (dgt >= flg.c && dgt >= flg.p)
		dsply = dgt_upmst_x(base, dsply, dgt, nb, flg);
	else if (flg.p >= flg.c && flg.p >= dgt)
		dsply = prec_upmst_x(base, dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0)
		dsply = chmp_upmst_dgt_x3(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1 && nb == 0)
		dsply = chmp_upmst_dgt_x3(dsply, dgt, nb, flg);
	else if (flg.c >= flg.p && flg.c >= dgt && flg.a == 1) 
		dsply = chmp_upmst_dgt_x2(base, dsply, dgt, nb, flg); 
	else if (flg.c >= flg.p && flg.c >= dgt && flg.p <= dgt) 
		dsply = chmp_upmst_dgt_x(base, dsply, dgt, nb, flg); 
	else if ((flg.c >= flg.p) && (flg.c >= dgt) && (flg.p > dgt))
		dsply = chmp_upmst_prec_x(base, dsply, dgt, nb, flg);
	p = ft_strlen(dsply);
	write(1, dsply, p);
	free(dsply);
	return (p);
}