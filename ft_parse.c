/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:16:55 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/17 17:41:07 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flg(s_flags *flg)
{
	flg->a = 0;
	flg->c = 0;
	flg->p = -1;
	flg->p_p = 0;
}

void	analyse_params(char *prmtrs, s_flags *flg, va_list *prms)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (prmtrs[i] == '-' || prmtrs[i] == '0')
	{
		if (flg->a != -1)
			flg->a = ft_attribute(prmtrs[i]);
		i++;
	}
	while (('0' <= prmtrs[i] && prmtrs[i] <= '9') || prmtrs[i] == '*')
	{
		if (flg->c == 0)
			flg->c = ft_champ(&prmtrs[i], prms);
		i++;
	}
	if (prmtrs[i] == '.')
	{
		flg->p = ft_precision(&prmtrs[++i], prms);
		if (prmtrs[i] == '\0')
			flg->p_p = 1;
	}
}

int		ft_attribute(char str)
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

int		ft_precision(char *str, va_list *prms)
{
	int i;
	int prec;

	i = 0;
	if (str[i] == '*')
	{
		prec = va_arg(*prms, int);
		return (prec);
	}
	prec = ft_atoi(str);
	return (prec);
}
