/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/14 19:44:59 by ehafidi          ###   ########.fr       */
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
	s_flags flags;
	int i = 0;
	int j = 0;
	int l = 0;
	void (*tabFunction[8]) (va_list *, s_flags) = {printf_p, printf_u, printf_x, printf_X, printf_s, printf_c, printf_d_i, printf_d_i};
	char tabIndex[9] = {'p', 'u', 'x', 'X', 's', 'c', 'd', 'i', 0};
	char *prmtrs;

	va_start(prms, src);
	while (src[i]) //la on check les flags entre % et indic de conversion
	{
		if (src[i] != '%')
			write(1, &src[i++], 1);
		else if (src[i] == '%')
		{
			i++;
			init_flags(&flags);
			l = i;
			while (('0' <= src[i] && src[i] <= '9') || src[i] == '-' || src[i] == '.' || src[i] == '*') ///attention peut aussi avoir *
				i++;
			prmtrs = ft_strndup(&src[l], (i - l));
			analyse_params(prmtrs, &flags, &prms);
			free(prmtrs);
			while (tabIndex[j] != 0)
			{
				if (src[i] == tabIndex[j])
				{
					(*tabFunction[j]) (&prms, flags);
					break ;
				}
				j++;
			}
			i++;
		}
	}
		//printf("%d%s\n", flags.att, ": att");   /////////////////////
		//printf("%d%s\n", flags.chmp, ": champ"); /////////////////////////
		//printf("%d%s\n", flags.prec, ": prec");  /////////////////////*/
	return (5);
}


int main()
{
	int age = 1234;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10d:\n", age); //champ < digit
	ft_printf("0:%03.10d:\n", age); //champ < digit
	ft_printf("-:%-3.10d:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10d:\n", age); //champ > digit
	ft_printf("0:%06.10d:\n", age); //champ > digit
	ft_printf("-:%-6.10d:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3d:\n", age); //precision < digit
	ft_printf("0:%010.3d:\n", age); //precision < digit
	ft_printf("-:%-10.3d:\n", age); //precision < digit*/
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6d:\n", age); //precision > digit
	ft_printf("0:%010.6d:\n", age); //precision > digit
	ft_printf("-:%-10.6d:\n", age); //precision > digit*/
	return (0);	
}

/*int main()
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
}*/