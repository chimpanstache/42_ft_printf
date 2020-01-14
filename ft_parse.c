/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:16:55 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/14 19:42:19 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void init_flags(s_flags *flags)
{
	flags->att = 0;
	flags->chmp = 0;
	flags->prec = 0;
}

void analyse_params(char *prmtrs, s_flags *flags, va_list *prms) //fonctionne en theorie
{
	int i = 0;
	int j = 0;

	//printf("%s%s\n", prmtrs, ": prmtrs");   //////////////////////////
	while (prmtrs[i] == '-' || prmtrs[i] == '0')
	{
		if (flags->att != -1)
			flags->att = ft_attribute(prmtrs[i]);
		i++;
	}
	while (('0' <= prmtrs[i] && prmtrs[i] <= '9') || prmtrs[i] == '*') //ne pas boucler zebi
	{
		if (flags->chmp == 0)
			flags->chmp = ft_champ(&prmtrs[i], prms);
		i++;
	}
	if (prmtrs[i] == '.') // attention peut aussi avoir * pour gerer prec
		flags->prec = ft_precision(&prmtrs[++i], prms);
}

int		ft_attribute(char str) //fonctionne normalement si 00000-0----0...
{
	int att;

	if (str == '-')
		att = -1;
	if (att == -1)
		return (att);
	if (str == '0')
		att = 1;
	else
		att = 0;
	return (att);
}

int		ft_champ(char *str, va_list *prms)
{
	int i;
	int champ;

	i = 0;
	if (str[i] == '*')
	{
		champ = va_arg(*prms, int);
		return (champ);
	}
	champ = ft_atoi(str);
	return (champ);
}

int 	ft_precision(char *str, va_list *prms)
{
	int i;
	int prec;

	i = 0;
	if (str[i] == '*')
	{
		prec = va_arg(*prms, int);
		return (prec);
	}
	prec  = ft_atoi(str);
	return (prec);
}
