/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:50:53 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/17 17:18:01 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	printf_p(va_list *prms, s_flags flags) //print the address, faire process de prec, champ et att directement dans fonction.
{
	long long ptr = (long long)va_arg(*prms, void *);
	char *base = "0123456789abcdef";
	write(1, "0x7fff", 6);
	ft_putnbr_base_p(ptr, base);
}

void 	printf_u(va_list *prms, s_flags flags)	//putnbr avec limites
{
	int nb = va_arg(*prms, int);
	char *base = "0123456789";
	//ft_putnbr_base(nb, base);
}

void 	printf_s(va_list *prms, s_flags flags)
{
	char *src = va_arg(*prms, char *);

	write(1, src, ft_strlen(src));
}

void	printf_c(va_list *prms, s_flags flags)
{
	char *chr = va_arg(*prms, char *);
	write(1, &chr, 1);
}