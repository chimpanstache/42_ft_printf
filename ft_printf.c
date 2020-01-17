/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:46:00 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/17 19:44:54 by ehafidi          ###   ########.fr       */
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

/*int main()  //tout fonctionne si nombre positif
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
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
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

/*int main()  //tout fonctionne si nombre positif
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

int main()  //tout fonctionne si nombre positif
{
	int age = 1234;
	int *p = &age;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10p:\n", age); //champ < digit
	ft_printf("0:%03.10p:\n", age); //champ < digit
	ft_printf("-:%-3.10p:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10p:\n", age); //champ > digit
	ft_printf("0:%06.10p:\n", age); //champ > digit
	ft_printf("-:%-6.10p:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3p:\n", age); //precision < digit
	ft_printf("0:%010.3p:\n", age); //precision < digit
	ft_printf("-:%-10.3p:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6p:\n", age); //precision > digit
	ft_printf("0:%010.6p:\n", age); //precision > digit
	ft_printf("-:%-10.6p:\n", age); //precision > digit
	return (0);
}

/*int main()  //tout fonctionne si nombre positif
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



	printf("%p\n", str); //champ < digit
	ft_printf("%p\n", str); //champ < digit
	printf("%p\n", p); //champ < digit
	ft_printf("%p\n", p); //champ < digit
	printf("%p\n", p1); //champ < digit
	ft_printf("%p\n", p1); //champ < digit
	printf("%p\n", p2); //champ < digit
	ft_printf("%p\n", p2); //champ < digit
	printf("%p\n", p3); //champ < digit
	ft_printf("%p\n", p3); //champ < digit
	printf("%p\n", p4); //champ < digit
	ft_printf("%p\n", p4); //champ < digit
	printf("%p\n", p5); //champ < digit
	ft_printf("%p\n", p5); //champ < digit
	
	return (0);
}*/

/*int main()  //tout fonctionne si nombre positif
{
	int age = -1234;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%d:\n", age); //champ < digit
	ft_printf("0:%d:\n", age); //champ < digit
	ft_printf("-:%d:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%d:\n", age); //champ > digit
	ft_printf("0:%d:\n", age); //champ > digit
	ft_printf("-:%d:\n", age); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%d:\n", age); //precision < digit
	ft_printf("0:%d:\n", age); //precision < digit
	ft_printf("-:%d:\n", age); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%d:\n", age); //precision > digit
	ft_printf("0:%d:\n", age); //precision > digit
	ft_printf("-:%d:\n", age); //precision > digit
	return (0);	
}*/

/*int main()
{
	int age = 1234;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%d:\n", age); //champ < digit
	ft_printf("0:%d:\n", age); //champ < digit
	ft_printf("-:%d:\n", age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%d:\n", age); //champ > digit
	ft_printf("0:%d:\n", age); //champ > digit
	ft_printf("-:%d:\n", age); //champ > digit
	return (0);	
}*/

/*int main()
{
	int age = -1234;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%*.*d:\n", chmp, prec2, age); //champ < digit
	printf("0:%0*.*d:\n", chmp, prec2, age); //champ < digit
	printf("-:%-*.*d:\n", chmp, prec2, age); //champ < digit
	printf("/////champ > digit\n");
	printf("-:%*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("-:%0*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("-:%-*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("-:%*.*d:\n", chmp2, prec, age); //champ < digit
	printf("-:%0*.*d:\n", chmp2, prec, age); //champ < digit
	printf("-:%-*.*d:\n", chmp2, prec, age); //champ < digit
	printf("/////precision > digit\n");
	printf("-:%*.*d:\n", chmp2, prec1, age); //champ < digit
	printf("-:%0*.*d:\n", chmp2, prec1, age); //champ < digit
	printf("-:%-10.*d:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main()
{
	int age = 1234;
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%x:\n", age); //champ < digit
	printf("0:%x:\n", age); //champ < digit
	printf("-:%x:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%x:\n", age); //champ > digit
	printf("0:%x:\n", age); //champ > digit
	printf("-:%x:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%x:\n", age); //precision < digit
	printf("0:%x:\n", age); //precision < digit
	printf("-:%x:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%x:\n", age); //precision > digit
	printf("0:%x:\n", age); //precision > digit 
	printf("-:%x:\n", age); //precision > digit
	return (0);	
}*/