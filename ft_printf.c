/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/23 15:24:16 by ehafidi          ###   ########.fr       */
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
	return (5);
}

/*int main() //petit x
{
	unsigned int age = 987654321;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10x:\n", age); //champ < digit
	ft_printf("0:%03.10x:\n", age); //champ < digit
	ft_printf("-:%-3.10x:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10x:\n", age); //champ > digit
	ft_printf("0:%06.10x:\n", age); //champ > digit
	ft_printf("-:%-6.10x:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3x:\n", age); //precision < digit
	ft_printf("0:%010.3x:\n", age); //precision < digit
	ft_printf("-:%-10.3x:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6x:\n", age); //precision > digit
	ft_printf("0:%010.6x:\n", age); //precision > digit 
	ft_printf("-:%-10.6x:\n", age); //precision > digit
	return (0);	
}*/

/*int main()  //grand X
{
	int age = 1234;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10X:\n", age); //champ < digit
	ft_printf("0:%03.10X:\n", age); //champ < digit
	ft_printf("-:%-3.10X:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10X:\n", age); //champ > digit
	ft_printf("0:%06.10X:\n", age); //champ > digit
	ft_printf("-:%-6.10X:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3X:\n", age); //precision < digit
	ft_printf("0:%010.3X:\n", age); //precision < digit
	ft_printf("-:%-10.3X:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6X:\n", age); //precision > digit
	ft_printf("0:%010.6X:\n", age); //precision > digit
	ft_printf("-:%-10.6X:\n", age); //precision > digit
	return (0);
}*/

/*int main() // c
{
	char age = 'h';
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	
	ft_printf("R:%10c:\n", age); //champ < digit
	ft_printf("-:%-10c:\n", age); //champ < digit
	ft_printf("-:%c:\n", age); //champ < digit
	ft_printf("-:%c:\n", age); //champ < digit
	return (0);	
}*/

/*int main()  // pointeur
{
	char *str;
	int i = 10;
	int *p = &i;
	unsigned int j = 10;
	unsigned int *p1 = &j;
	long k = 10;
	long *p2 = &k;
	unsigned long l = 10;
	unsigned long *p3 = &l;
	long long m = 10;
	long long *p4 = &m;
	unsigned long long n = 10;	
	unsigned long long *p5 = &n;
	int *zeb;
	int *zebi = NULL;


	ft_printf("R:%50p:\n", str); //champ < digit
	ft_printf("-:%-50p:\n", str); //champ < digit
	ft_printf(":%p:\n", p); //champ < digit
	ft_printf("%p\n", p); //champ < digit
	ft_printf("%p\n", p1); //champ < digit
	ft_printf("%p\n", p1); //champ < digit
	ft_printf("%p\n", p2); //champ < digit
	ft_printf("%p\n", p2); //champ < digit
	ft_printf("%p\n", p3); //champ < digit
	ft_printf("%p\n", p3); //champ < digit
	ft_printf("%p\n", p4); //champ < digit
	ft_printf("%p\n", p4); //champ < digit
	ft_printf("%p\n", p5); //champ < digit
	ft_printf("%p\n", p5); //champ < digit
	ft_printf("%p\n", zeb); //champ < digit
	ft_printf("%p\n", zeb); //champ < digit
	ft_printf("%p\n", zebi); //champ < digit
	return (0);
}*/

/*int main() // int avec *
{
	int age = 1234;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	//ft_printf("R:%d:\n", age); //champ < digit
	ft_printf("R:%*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("0:%0*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("-:%*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%0*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("-:%*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%0*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("/////precision > digit\n");
	ft_printf("-:%*.*d:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%0*.*d:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%-10.*d:\n", prec1, age); //champ < digit
	return (0);	
}*/


/*int main() //string
{
	char *age = "choc";
	int khey = 132;

	ft_printf("digit > champ\n");
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%4.3s:\n", age); //champ < digit
	ft_printf("-:%4.3s:\n", age); //champ < digit
	ft_printf("/////precision > digit\n"); ///////////part ici en couille
	ft_printf("R:%2.6s:\n", age); //champ < digit
	ft_printf("-:%-2.6s:\n", age); //champ < digit
	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10s:\n", age); //champ < digit
	ft_printf("-:%-3.10s:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10s:\n", age); //champ > digit
	ft_printf("-:%-6.10s:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3s:\n", age); //precision < digit
	ft_printf("-:%-10.3s:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6s:\n", age); //precision > digit
	ft_printf("-:%-10.6s:\n", age); //precision > digit
	ft_printf("/////precision == 0\n");
	ft_printf("R:%10.0s:\n", age); //precision > digit
	ft_printf("-:%-10.0s:\n", age); //precision > digit
	return (0);	
}*/

/*int main()  // int avec d
{
	int age = -1234;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10d:\n", age); //champ < digit
	ft_printf("0:%03.10d:\n", age); //champ < digit
	ft_printf("-:%-3.10d:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10d:\n", age); //champ > digit
	ft_printf("0:%06.10d:\n", age); //champ > digit
	ft_printf("-:%-6.10d:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3d:\n", age); //precision < digit
	ft_printf("0:%010.3d:\n", age); //precision < digit
	ft_printf("-:%-10.3d:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6d:\n", age); //precision > digit
	ft_printf("0:%010.6d:\n", age); //precision > digit
	ft_printf("-:%-10.6d:\n", age); //precision > digit
	return (0);
}*/

/*int main()  // int avec i
{
	int age = -1234;
	int *p = &age;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10i:\n", age); //champ < digit
	ft_printf("0:%03.10i:\n", age); //champ < digit
	ft_printf("-:%-3.10i:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10i:\n", age); //champ > digit
	ft_printf("0:%06.10i:\n", age); //champ > digit
	ft_printf("-:%-6.10i:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3i:\n", age); //precision < digit
	ft_printf("0:%010.3i:\n", age); //precision < digit
	ft_printf("-:%-10.3i:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6i:\n", age); //precision > digit
	ft_printf("0:%010.6i:\n", age); //precision > digit
	ft_printf("-:%-10.6i:\n", age); //precision > digit
	return (0);
}*/

int main()  // int avec u
{
	unsigned int age = 1234;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10u:\n", age); //champ < digit
	ft_printf("0:%03.10u:\n", age); //champ < digit
	ft_printf("-:%-3.10u:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10u:\n", age); //champ > digit
	ft_printf("0:%06.10u:\n", age); //champ > digit
	ft_printf("-:%-6.10u:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3u:\n", age); //precision < digit
	ft_printf("0:%010.3u:\n", age); //precision < digit
	ft_printf("-:%-10.3u:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6u:\n", age); //precision > digit
	ft_printf("0:%010.6u:\n", age); //precision > digit
	ft_printf("-:%-10.6u:\n", age); //precision > digit
	return (0);
}
