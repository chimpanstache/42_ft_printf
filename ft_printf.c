/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/07 13:37:15 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	findIndex(char *arr, char element)
{
	int i = 0;

	while (arr[i])
	{
		if (arr[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_printf(const char *src, ...)
{
	va_list prms;
	int i = 0;
	int attribute = 0;
	int champ = 0;
	int precision = 0;
	int conv;
	int j;
	j = 0;
	void (*tabFunction[8]) (va_list *, int, int, int) = {printf_p, printf_u, printf_x, printf_X, printf_s, printf_c, printf_d_i, printf_d_i};
	char tabIndex[9] = {'p', 'u', 'x', 'X', 's', 'c', 'd', 'i', 0};

	va_start(prms, src);
	while (src[i]) //la on check les flags entre % et indic de conversion
	{
		if (src[i] == '%')
		{
			i++;
			if (src[i] == '-' || src[i] == '0') //caractere dáttribut
			{	
				attribute = ft_attribute((char *)&src[i]); // uste gerer le 0 ou le -
				i++;
				if (src[i] == '-' && src[i - 1] == 0)
				{
					attribute = ft_attribute((char *)&src[i]);
					i++;
				}
				printf("%d%s\n", attribute, ": attribute");	//////////////////////
			}
			if ((src[i] >= '1' && src[i] <= '9') || src[i] == '*') //largeur de champ
			{
				champ = ft_champ((char *)&src[i], &prms);
				i++;
				while ('0' <= src[i] && src[i] <= '9')
					i++;
				printf("%d%s\n", champ, ": champ");  ///////////////////////
			}	
			if (src[i] == '.') //precision
			{
				i++;
				precision = ft_precision((char *)&src[i]);
				while ('0' <= src[i] && src[i] <= '9')
					i++;
				printf("%d%s\n", precision, ": precision"); ////////////
			}
		break ;	
		}
		if (src[i] != '%')
		{
			write(1, &src[i], 1);
			i++;
		}
	}
	/*while (tabIndex[j] != 0)
	{
		if (src[i] == tabIndex[j])
		{
			(*tabFunction[j]) (&prms, attribute, champ, precision);
			break ;
		}
		j++;	
	}	
	while (src[++i] != '\0')
	{
		write(1, &src[i], 1);
	}*/
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	return (5);
}

int main()
{
	int age = -1232;
	int khey = -3222;
	ft_printf("weieir%-10.5d:hahah\n", age);
	ft_printf("weieir%.10d:haha\n", khey);
	ft_printf("weieir%010d:haha\n", age);
	ft_printf("weieir%10.d:haha\n", khey);
	ft_printf("weieir%d:haha\n", age);
	ft_printf("weieir%010.5d:\n", khey);
	ft_printf("%-10d:\n", age);
	ft_printf("%-10.5d:\n", khey);
	ft_printf("%-10.3d:\n", age);
	ft_printf("%2d:\n", khey);
	ft_printf("%50d:\n", age);
	ft_printf("%*d:\n", khey, age);
	return (0);
}