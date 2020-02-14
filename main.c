/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/14 16:12:07 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libftprintf.h"

/*int main()
{
	int age = 122;
	int khey = 132;

	printf("2:%.00010d:\n", age);
	printf("3:%010d:\n", age);
	printf("4:%10.d:\n", age);
	printf("4:%.d:\n", age);
	return (0);
}*/

/*int main() //petit x okkk
{
	unsigned int age = 4294967295;
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%x:\n", age); //champ < digit
	printf("R:%3.10x:\n", age); //champ < digit
	printf("0:%03.10x:\n", age); //champ < digit
	printf("-:%-3.10x:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10x:\n", age); //champ > digit
	printf("0:%06.10x:\n", age); //champ > digit
	printf("-:%-6.10x:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%10.3x:\n", age); //precision < digit
	printf("0:%010.3x:\n", age); //precision < digit
	printf("-:%-10.3x:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6x:\n", age); //precision > digit
	printf("0:%010.6x:\n", age); //precision > digit 
	printf("-:%-10.6x:\n", age); //precision > digit
	return (0);	
}*/

/*int main()  //grand X okkk
{
	unsigned int age = 4294967295;
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%X:\n", age); //champ < digit
	printf("R:%3.10X:\n", age); //champ < digit
	printf("0:%03.10X:\n", age); //champ < digit
	printf("-:%-3.10X:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10X:\n", age); //champ > digit
	printf("0:%06.10X:\n", age); //champ > digit
	printf("-:%-6.10X:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3X:\n", age); //precision < digit
	printf("0:%010.3X:\n", age); //precision < digit
	printf("-:%-10.3X:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6X:\n", age); //precision > digit
	printf("0:%010.6X:\n", age); //precision > digit
	printf("-:%-10.6X:\n", age); //precision > digit
	return (0);
}*/

/*int main() //unsigned int avec * okkk
{
	unsigned int age = 0;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%*.*X:\n", chmp, prec2, age); //champ < digit
	printf("0:%0*.*X:\n", chmp, prec2, age); //champ < digit
	printf("-:%-*.*X:\n", chmp, prec2, age); //champ < digit
	printf("/////champ > digit\n");
	printf("-:%*.*X:\n", chmp1, prec2, age); //champ < digit
	printf("-:%0*.*X:\n", chmp1, prec2, age); //champ < digit
	printf("-:%-*.*X:\n", chmp1, prec2, age); //champ < digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("-:%*.*X:\n", chmp2, prec, age); //champ < digit
	printf("-:%0*.*X:\n", chmp2, prec, age); //champ < digit
	printf("-:%-*.*X:\n", chmp2, prec, age); //champ < digit
	printf("/////precision > digit\n");
	printf("-:%*.*X:\n", chmp2, prec1, age); //champ < digit
	printf("-:%0*.*X:\n", chmp2, prec1, age); //champ < digit
	printf("-:%-10.*X:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() //unsigned int avec * okkk
{
	unsigned int age = 0;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%*.*x:\n", chmp, prec2, age); //champ < digit
	printf("0:%0*.*x:\n", chmp, prec2, age); //champ < digit
	printf("-:%-*.*x:\n", chmp, prec2, age); //champ < digit
	printf("/////champ > digit\n");
	printf("-:%*.*x:\n", chmp1, prec2, age); //champ < digit
	printf("-:%0*.*x:\n", chmp1, prec2, age); //champ < digit
	printf("-:%-*.*x:\n", chmp1, prec2, age); //champ < digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("-:%*.*x:\n", chmp2, prec, age); //champ < digit
	printf("-:%0*.*x:\n", chmp2, prec, age); //champ < digit
	printf("-:%-*.*x:\n", chmp2, prec, age); //champ < digit
	printf("/////precision > digit\n");
	printf("-:%*.*x:\n", chmp2, prec1, age); //champ < digit
	printf("-:%0*.*x:\n", chmp2, prec1, age); //champ < digit
	printf("-:%-10.*x:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() // c okkk
{
	char age = 127;

	printf("/////champ =< digit\n");
	printf("R:%10c:\n", age); //champ < digit
	printf("-:%-10c:\n", age); //champ < digit
	printf("-:%c:\n", age); //champ < digit
	printf("-:%c:\n", age); //champ < digit
	return (0);	
}*/

/*int main()  // pointeur okkk
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



	printf("R:%25p:\n", str); //champ < digit
	printf("-:%-25p:\n", str); //champ < digit
	printf("%p\n", p); //champ < digit
	printf("%p\n", p); //champ < digit
	printf("%p\n", p1); //champ < digit
	printf("%p\n", p1); //champ < digit
	printf("%p\n", p2); //champ < digit
	printf("%p\n", p2); //champ < digit
	printf("%p\n", p3); //champ < digit
	printf("%p\n", p3); //champ < digit
	printf("%p\n", p4); //champ < digit
	printf("%p\n", p4); //champ < digit
	printf("%p\n", p5); //champ < digit
	printf("%p\n", p5); //champ < digit
	printf("%p\n", zeb); //champ < digit
	printf("%p\n", zeb); //champ < digit
	printf("%p\n", zebi); //champ < digit
	printf("%.p\n", zebi); //champ < digit
	return (0);
}*/

/*int main() // int d avec * okkk
{
	int age = -2147483648;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%d:\n", age); //champ < digit
	printf("R:%*.*d:\n", chmp, prec2, age); //champ < digit
	printf("0:%0*.*d:\n", chmp, prec2, age); //champ < digit
	printf("-:%-*.*d:\n", chmp, prec2, age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("0:%0*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("-:%-*.*d:\n", chmp1, prec2, age); //champ < digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%*.*d:\n", chmp2, prec, age); //champ < digit
	printf("0:%0*.*d:\n", chmp2, prec, age); //champ < digit
	printf("-:%-*.*d:\n", chmp2, prec, age); //champ < digit
	printf("/////precision > digit\n");
	printf("R:%*.*d:\n", chmp2, prec1, age); //champ < digit
	printf("0:%0*.*d:\n", chmp2, prec1, age); //champ < digit
	printf("-:%-10.*d:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() // int i avec * okkk
{
	int age = -2;
	int prec = -3;
	int prec1 = -6;
	int prec2 = -10;
	int chmp = -3;
	int chmp1 = -6;
	int chmp2 = -10;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%i:\n", age); //champ < digit
	printf("R:%*.*i:\n", chmp, prec2, age); //champ < digit 
	printf("0:%0*.*i:\n", chmp, prec2, age); //champ < digit
	printf("-:%-*.*i:\n", chmp, prec2, age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%*.*i:\n", chmp1, prec2, age); //champ < digit
	printf("0:%0*.*i:\n", chmp1, prec2, age); //champ < digit
	printf("-:%-*.*i:\n", chmp1, prec2, age); //champ < digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%*.*i:\n", chmp2, prec, age); //champ < digit
	printf("0:%0*.*i:\n", chmp2, prec, age); //champ < digit
	printf("-:%-*.*i:\n", chmp2, prec, age); //champ < digit
	printf("/////precision > digit\n");
	printf("R:%*.*i:\n", chmp2, prec1, age); //champ < digit
	printf("0:%0*.*i:\n", chmp2, prec1, age); //champ < digit
	printf("-:%-10.*i:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() //string unprintables okkk
{
	char chaine[33];
	chaine[0] = 1;
	chaine[1] = 2;
	chaine[2] = 3;
	chaine[3] = 4;
	chaine[4] = 5;
	chaine[5] = 6;
	chaine[6] = 7;
	chaine[7] = 8;
	chaine[8] = 9;
	chaine[9] = 10;
	chaine[10] = 11;
	chaine[11] = 12;
	chaine[12] = 13;
	chaine[13] = 14;
	chaine[14] = 15;
	chaine[15] = 16;
	chaine[16] = 17;
	chaine[17] = 18;
	chaine[18] = 19;
	chaine[19] = 20;
	chaine[20] = 21;
	chaine[21] = 22;
	chaine[22] = 23;
	chaine[23] = 24;
	chaine[24] = 25;
	chaine[25] = 26;
	chaine[26] = 27;
	chaine[27] = 28;
	chaine[28] = 29;
	chaine[29] = 30;
	chaine[30] = 31;
	chaine[31] = 127;
	chaine[32] = 0;

	printf("digit > champ\n");
	printf("/////precision =< digit\n");
	printf("R:%s:\n", chaine); //champ < digit
	printf("R:%4.3s:\n", chaine); //champ < digit
	printf("-:%-4.3s:\n", chaine); //champ < digit
	printf("/////precision > digit\n"); ///////////part ici en couille
	printf("R:%2.6s:\n", chaine); //champ < digit
	printf("-:%-2.6s:\n", chaine); //champ < digit
	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10s:\n", chaine); //champ < digit
	printf("-:%-3.10s:\n", chaine); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10s:\n", chaine); //champ > digit
	printf("-:%-6.10s:\n", chaine); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3s:\n", chaine); //precision < digit
	printf("-:%-10.3s:\n", chaine); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6s:\n", chaine); //precision > digit
	printf("-:%-10.6s:\n", chaine); //precision > digit
	printf("/////precision == 0\n");
	printf("R:%10.0s:\n", chaine); //precision > digit
	printf("-:%-10.0s:\n", chaine); //precision > digit
	return (0);	
}*/

/*int main() //string printables okkk
{
	char *age = "\x";
	int khey = 132;

	printf("digit > champ\n");
	printf("/////precision =< digit\n");
	printf("R:%s:\n", age); //champ < digit
	printf("R:%4.3s:\n", age); //champ < digit
	printf("-:%-4.3s:\n", age); //champ < digit
	printf("/////precision > digit\n"); ///////////part ici en couille
	printf("R:%2.6s:\n", age); //champ < digit
	printf("-:%-2.6s:\n", age); //champ < digit
	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10s:\n", age); //champ < digit
	printf("-:%-3.10s:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10s:\n", age); //champ > digit
	printf("-:%-6.10s:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3s:\n", age); //precision < digit
	printf("-:%-10.3s:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6s:\n", age); //precision > digit
	printf("-:%-10.6s:\n", age); //precision > digit
	printf("/////precision == 0\n");
	printf("R:%10.0s:\n", age); //precision > digit
	printf("-:%-10.0s:\n", age); //precision > digit
	return (0);	
}*/

/*int main()  // int avec d okkk
{
	int age = 0;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%d:\n", age); //champ < digit
	printf("R:%3.10d:\n", age); //champ < digit
	printf("0:%03.10d:\n", age); //champ < digit
	printf("-:%-3.10d:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10d:\n", age); //champ > digit
	printf("0:%06.10d:\n", age); //champ > digit
	printf("-:%-6.10d:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3d:\n", age); //precision < digit
	printf("0:%010.3d:\n", age); //precision < digit
	printf("-:%-10.3d:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6d:\n", age); //precision > digit
	printf("0:%010.6d:\n", age); //precision > digit
	printf("-:%-10.6d:\n", age); //precision > digit
	return (0);
}*/

/*int main()  // int avec i okkk
{
	int age = 0;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10i:\n", age); //champ < digit
	printf("0:%03.10i:\n", age); //champ < digit
	printf("-:%-3.10i:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10i:\n", age); //champ > digit
	printf("0:%06.10i:\n", age); //champ > digit
	printf("-:%-6.10i:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3i:\n", age); //precision < digit
	printf("0:%010.3i:\n", age); //precision < digit
	printf("-:%-10.3i:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6i:\n", age); //precision > digit
	printf("0:%010.6i:\n", age); //precision > digit
	printf("-:%-10.6i:\n", age); //precision > digit
	return (0);
}*/

/*int main()  // int avec u okkk
{
	unsigned int age = 1;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10u:\n", age); //champ < digit
	printf("0:%03.10u:\n", age); //champ < digit
	printf("-:%-3.10u:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10u:\n", age); //champ > digit
	printf("0:%06.10u:\n", age); //champ > digit
	printf("-:%-6.10u:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); 
	printf("/////precision =< digit\n");
	printf("R:%10.3u:\n", age); //precision < digit
	printf("0:%010.3u:\n", age); //precision < digit
	printf("-:%-10.3u:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6u:\n", age); //precision > digit
	printf("0:%010.6u:\n", age); //precision > digit
	printf("-:%-10.6u:\n", age); //precision > digit
	return (0);
}*/

/*int main()  //printf testers
{
	printf("1:%%:\n");
	printf("2:%%%%:\n");
	printf("3:%%%%%%:\n");
	printf("4:%.10%:\n");
	printf("5:%-5%:\n");
	printf("5:%5%:\n");
	printf("6:%05%:\n");
	printf("7:%c%%:\n", '3');
	printf("8:%s%%:\n", "Hello3");
	return (0);
}*/

/*int main()  //printf testers
{
	printf(":%.*s:\n", 0, "Hello");
	printf(":%*.*s:\n", 0, 0, "Hello");
	printf(":%*.*s:\n", -5, 0, "Helloooooo");
	return (0);
}*/

/*int main()
{
	printf("%%d 0000042 == |%d|\n", 00000432);
	return (0);
}*/

/*#include <stdarg.h>

void	fonction(int ok, ...)
{
	va_list vl;
	va_start(vl, ok);
	printf("%d", va_arg(vl, int));
	va_end(vl);
}

int main(int argc, char **argv)
{
	(void) argc;
	fonction(19, 0000042);
}*/

/*int main()
{
	
	char *str = "salut\0 cava";
	printf("\n%d", printf("%s", str));
	return 0;
}*/

/*int main()
{
	
	//printf("%05s", "hello");
	//printf("%021s", NULL);
	//printf("%.0p", 0);
	//printf("%.5p", 0);
	//printf("%2.9p", 1234);
	//printf("%09s", "hello");
	return 0;
}*/

/*int main() //petit x okkk
{
	unsigned int age = 4294967295;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%x:\n", age); //champ < digit
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

/*int main()  //grand X okkk
{
	unsigned int age = 4294967295;
	int khey = 132;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%X:\n", age); //champ < digit
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

/*int main() //unsigned int avec * okkk
{
	unsigned int age = 0;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%*.*X:\n", chmp, prec2, age); //champ < digit
	ft_printf("0:%0*.*X:\n", chmp, prec2, age); //champ < digit
	ft_printf("-:%-*.*X:\n", chmp, prec2, age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("-:%*.*X:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%0*.*X:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%-*.*X:\n", chmp1, prec2, age); //champ < digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("-:%*.*X:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%0*.*X:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%-*.*X:\n", chmp2, prec, age); //champ < digit
	ft_printf("/////precision > digit\n");
	ft_printf("-:%*.*X:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%0*.*X:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%-10.*X:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() //unsigned int avec * okkk
{
	unsigned int age = 0;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%*.*x:\n", chmp, prec2, age); //champ < digit
	ft_printf("0:%0*.*x:\n", chmp, prec2, age); //champ < digit
	ft_printf("-:%-*.*x:\n", chmp, prec2, age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("-:%*.*x:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%0*.*x:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%-*.*x:\n", chmp1, prec2, age); //champ < digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("-:%*.*x:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%0*.*x:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%-*.*x:\n", chmp2, prec, age); //champ < digit
	ft_printf("/////precision > digit\n");
	ft_printf("-:%*.*x:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%0*.*x:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%-10.*x:\n", prec1, age); //champ < digit
	return (0);	
}*/

/*int main() // c okkk
{
	char age = 127;
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%10c:\n", age); //champ < digit
	ft_printf("-:%-10c:\n", age); //champ < digit
	ft_printf("-:%c:\n", age); //champ < digit
	ft_printf("-:%c:\n", age); //champ < digit
	return (0);	
}*/

/*int main()  // pointeur okkk
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


	ft_printf("R:%25p:\n", str); //champ < digit
	ft_printf("-:%-25p:\n", str); //champ < digit
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
	ft_printf("%.p\n", zebi); //champ < digit
	return (0);
}*/

/*int main() // int d avec * okkk
{
	int age = -2147483648;
	int prec = 3;
	int prec1 = 6;
	int prec2 = 10;
	int chmp = 3;
	int chmp1 = 6;
	int chmp2 = 10;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%d:\n", age); //champ < digit
	ft_printf("R:%*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("0:%0*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp, prec2, age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("0:%0*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp1, prec2, age); //champ < digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("0:%0*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%-*.*d:\n", chmp2, prec, age); //champ < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%*.*d:\n", chmp2, prec1, age); //champ < digit
	ft_printf("0:%0*.*d:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%-10.*d:\n", prec1, age); //champ < digit
	return (0);	
}*/

int main() // int i avec * okkk
{
	int age = -2;
	int prec = -3;
	int prec1 = -6;
	int prec2 = -10;
	int chmp = -3;
	int chmp1 = -6;
	int chmp2 = -10;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%i:\n", age); //champ < digit
	ft_printf("R:%*.*i:\n", chmp, prec2, age); //champ < digit 
	ft_printf("0:%0*.*i:\n", chmp, prec2, age); //champ < digit
	ft_printf("-:%-*.*i:\n", chmp, prec2, age); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%*.*i:\n", chmp1, prec2, age); //champ < digit
	ft_printf("0:%0*.*i:\n", chmp1, prec2, age); //champ < digit
	ft_printf("-:%-*.*i:\n", chmp1, prec2, age); //champ < digit
	ft_printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%*.*i:\n", chmp2, prec, age); //champ < digit
	ft_printf("0:%0*.*i:\n", chmp2, prec, age); //champ < digit
	ft_printf("-:%-*.*i:\n", chmp2, prec, age); //champ < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%*.*i:\n", chmp2, prec1, age); //champ < digit
	ft_printf("0:%0*.*i:\n", chmp2, prec1, age); //champ < digit
	ft_printf("-:%-10.*i:\n", prec1, age); //champ < digit
	return (0);
}

/*int main() //string unprintables okkk
{
	char chaine[33];
	chaine[0] = 1;
	chaine[1] = 2;
	chaine[2] = 3;
	chaine[3] = 4;
	chaine[4] = 5;
	chaine[5] = 6;
	chaine[6] = 7;
	chaine[7] = 8;
	chaine[8] = 9;
	chaine[9] = 10;
	chaine[10] = 11;
	chaine[11] = 12;
	chaine[12] = 13;
	chaine[13] = 14;
	chaine[14] = 15;
	chaine[15] = 16;
	chaine[16] = 17;
	chaine[17] = 18;
	chaine[18] = 19;
	chaine[19] = 20;
	chaine[20] = 21;
	chaine[21] = 22;
	chaine[22] = 23;
	chaine[23] = 24;
	chaine[24] = 25;
	chaine[25] = 26;
	chaine[26] = 27;
	chaine[27] = 28;
	chaine[28] = 29;
	chaine[29] = 30;
	chaine[30] = 31;
	chaine[31] = 127;
	chaine[32] = 0;

	ft_printf("digit > champ\n");
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%s:\n", chaine); //champ < digit
	ft_printf("R:%4.3s:\n", chaine); //champ < digit
	ft_printf("-:%-4.3s:\n", chaine); //champ < digit
	ft_printf("/////precision > digit\n"); ///////////part ici en couille
	ft_printf("R:%2.6s:\n", chaine); //champ < digit
	ft_printf("-:%-2.6s:\n", chaine); //champ < digit
	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10s:\n", chaine); //champ < digit
	ft_printf("-:%-3.10s:\n", chaine); //champ < digit
	ft_printf("/////champ > digit\n");
	ft_printf("R:%6.10s:\n", chaine); //champ > digit
	ft_printf("-:%-6.10s:\n", chaine); //champ > digit
	ft_printf("champ > precision && champ > digit\n"); 
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%10.3s:\n", chaine); //precision < digit
	ft_printf("-:%-10.3s:\n", chaine); //precision < digit
	ft_printf("/////precision > digit\n");
	ft_printf("R:%10.6s:\n", chaine); //precision > digit
	ft_printf("-:%-10.6s:\n", chaine); //precision > digit
	ft_printf("/////precision == 0\n");
	ft_printf("R:%10.0s:\n", chaine); //precision > digit
	ft_printf("-:%-10.0s:\n", chaine); //precision > digit
	return (0);
}*/

/*int main() //string printables  okkk
{
	char *age = "chocolatttt";
	int khey = 132;

	ft_printf("digit > champ\n");
	ft_printf("/////precision =< digit\n");
	ft_printf("R:%s:\n", age); //champ < digit
	ft_printf("R:%4.3s:\n", age); //champ < digit
	ft_printf("-:%-4.3s:\n", age); //champ < digit
	ft_printf("/////precision > digit\n"); ///////////part ici en couille
	ft_printf("R:%2.6s:\n", age); //champ < digit
	ft_printf("-:%-2.6s:\n", age); //champ < digit
	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%3.10s:\n", age); //champ < digit
	ft_printf("-:%-3.10s:\n", age); //champ < digit
	ft_printf("/////champ > digit\n"); ///////// ************ici
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

/*int main()  // int avec d okkk
{
	int age = 0;

	ft_printf("precision > champ && precision > digit\n");
	ft_printf("/////champ =< digit\n");
	ft_printf("R:%d:\n", age); //champ < digit
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

/*int main()  // int avec i okkk
{
	int age = 0;

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

/*int main()  // int avec u okkk
{
	unsigned int age = 1;

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
}*/

/*int main()  //printf testers
{
	ft_printf("2:%%%%:\n");
	ft_printf("3:%%%%%%:\n");
	ft_printf("4:%.10%:\n");
	ft_printf("5:%-5%:\n");
	ft_printf("5:%5%:\n");
	ft_printf("6:%05%:\n");
	ft_printf("7:%c%%:\n", '3');
	ft_printf("8:%s%%:\n", "Hello3");
	return (0);
}*/

/*int main()  //printf testers
{
	ft_printf("%02u\n", 0);
	ft_printf("%010u\n", 0);
	ft_printf("%011u\n", UINT_MAX);

	return (0);
}*/

/*int main()  //printf testers
{
	ft_printf("%.0d\n", 0);
	ft_printf("%.0i\n", 0);
	ft_printf("%.0u\n", 0);
	ft_printf("%.0x\n", 0);
	ft_printf("%.0X\n", 0);
	return (0);
}*/

/*int main()  //printf testers
{
	ft_printf(":%6.10s:\n", "Hello");
	//ft_printf(":%6.1s:\n", "Hello");
	//ft_printf(":%6.2s:\n", "Hello");
	return (0);
}*/

/*int main()  //printf testers
{
	ft_printf(":%02.0u:\n", 0);
	ft_printf(":%010.0u:\n", 0);
	ft_printf(":%010.2u:\n", 0);
	return (0);
}*/

/*int main()  //printf testers
{
	ft_printf(":%011.9x:\n", 429496764);
	ft_printf(":%011.9X:\n", 429496764);
	return (0);
}*/

/*int main()  //printf testers
{
	//ft_printf(":%.*s:\n", -3, "Hello");
	//ft_printf(":%*.*s:\n", 0, -5, "Hello");
	ft_printf(":%.s:\n", 42);
	return (0);
}*/

/*int main()  //printf testers
{

	ft_printf("%%d 0000042 == |%d|\n", 000042);
	return (0);
}*/

/*#include "printf.h"

int main()
{
	int count = 0;
	int count1 = 0;
	char a = 's';
	char *str = "Lorai";
	int d = -42;  // test with negatif number -42
	unsigned int u = 247;
	unsigned int u_ = 2999483647;
	unsigned int x = 2999483647;
	unsigned int X = 47269;
	int O = 0;

	// count = printf("simon%%\n");
    // count1 = ft_printf("simon%%\n");
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%-%\n");
    // count1 = ft_printf("simon%-%\n");
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%-5%simon\n");
    // count1 = ft_printf("simon%-5%simon\n");
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%-050%\n");
    // count1 = ft_printf("simon%-050%\n");
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%5%\n");
    // count1 = ft_printf("simon%5%\n");
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%c\n", a);
    // count1 = ft_printf("simon%c\n", a);
	// printf("\n%d\n%d\n", count, count1);

	// count = printf("simon%-0csimon\n", a);
    // count1 = ft_printf("simon%-.0csimon\n", a);
	// printf("\n%d\n%d\n", count, count1);

//s

	count = printf("simon %s\n", str);
    count1 = ft_printf("simon %s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("simon %-s\n", str);
    count1 = ft_printf("simon %-s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("simon %2.7s\n", str);
    count1 = ft_printf("simon %2.7s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.10s\n", str);
    count1 = ft_printf("%.10s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("simon %5.2s\n", str);
    count1 = ft_printf("simon %5.2s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-5s\n", str);
    count1 = ft_printf("%-5s\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-10ssimon\n", str);
    count1 = ft_printf("%-10ssimon\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-10.10ssimon\n", str);
    count1 = ft_printf("%-10.10ssimon\n", str);
	printf("\n%d\n%d\n", count, count1);

// p

	count = printf("%p\n", str);
    count1 = ft_printf("%p\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%15p\n", str);
    count1 = ft_printf("%15p\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-15psimon\n", str);
    count1 = ft_printf("%-15psimon\n", str);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%*psimon\n", 20, str);
    count1 = ft_printf("%*psimon\n", 20, str);
	printf("\n%d\n%d\n", count, count1);

// //d / i

// 	printf("----------------d/i-------------------\n");

// 	count = printf("%10.5d\n", INT_MAX);
//     count1 = ft_printf("%10.5d\n", INT_MAX);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%d\n", INT_MIN);
//     count1 = ft_printf("%d\n", INT_MIN);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%-d\n", INT_MIN);
//     count1 = ft_printf("%-d\n", INT_MIN);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%d\n", -2147483647 - 1);
//     count1 = ft_printf("%d\n", -2147483647 - 1);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%-d\n", -2147483647 - 1);
//     count1 = ft_printf("%-d\n", -2147483647 - 1);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%10.5d\n", d);
//     count1 = ft_printf("%10.5d\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-dsim\n", d);
//     count1 = ft_printf("sim%-dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10dsim\n", d);
//     count1 = ft_printf("sim%-10dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-1dsim\n", d);
//     count1 = ft_printf("sim%-1dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.1dsim\n", d);
//     count1 = ft_printf("sim%-10.1dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.5dsim\n", d);
//     count1 = ft_printf("sim%-10.5dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%10.5dsim\n", d);
//     count1 = ft_printf("sim%10.5dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%.5dsim\n", d);
//     count1 = ft_printf("sim%.5dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%.5dsim\n", d);
//     count1 = ft_printf("sim%.5dsim\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.*dsim\n", 2, d);
// 	count1 = ft_printf("sim%-10.*dsim\n", 2, d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.*dsim\n", 5, d);
//     count1 = ft_printf("sim%-10.*dsim\n", 5, d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-1.5d\n", d);
//     count1 = ft_printf("sim%-1.5d\n", d);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%--74.52i%0151.*i\n" ,-296196750,-88,-683739763);
//     count1 = ft_printf("%--74.52i%0151.*i\n" ,-296196750,-88,-683739763);
// 	printf("\n%d\n%d\n", count, count1);

// //u

// 	count = printf("sim%u\n", u);
//     count1 = ft_printf("sim%u\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-usim\n", u);
//     count1 = ft_printf("sim%-usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10usim\n", u);
//     count1 = ft_printf("sim%-10usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-1usim\n", u);
//     count1 = ft_printf("sim%-1usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.1usim\n", u);
//     count1 = ft_printf("sim%-10.1usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.5usim\n", u);
//     count1 = ft_printf("sim%-10.5usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%10.5usim\n", u);
//     count1 = ft_printf("sim%10.5usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%.5usim\n", u);
//     count1 = ft_printf("sim%.5usim\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.*usim\n", 2, u);
// 	count1 = ft_printf("sim%-10.*usim\n", 2, u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.*usim\n", 5, u);
//     count1 = ft_printf("sim%-10.*usim\n", 5, u);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-1.5u\n", u);
//     count1 = ft_printf("sim%-1.5u\n", u);
// 	printf("\n%u\n%u\n", count, count1);

// //x

// 	count = printf("sim%x\n", x);
//     count1 = ft_printf("sim%x\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%-xsim\n", x);
//     count1 = ft_printf("sim%-xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%-10xsim\n", x);
//     count1 = ft_printf("sim%-10xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%-1xsim\n", x);
//     count1 = ft_printf("sim%-1xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%-10.1xsim\n", x);
//     count1 = ft_printf("sim%-10.1xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%-10.5xsim\n", x);
//     count1 = ft_printf("sim%-10.5xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%10.5xsim\n", x);
//     count1 = ft_printf("sim%10.5xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// 	count = printf("sim%.5xsim\n", x);
//     count1 = ft_printf("sim%.5xsim\n", x);
// 	printf("\n%x\n%x\n", count, count1);

// //X

// 	count = printf("sim%X\n", X);
//     count1 = ft_printf("sim%X\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-Xsim\n", X);
//     count1 = ft_printf("sim%-Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-10xsim\n", X);
//     count1 = ft_printf("sim%-10Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-1Xsim\n", X);
//     count1 = ft_printf("sim%-1Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-10.1Xsim\n", X);
//     count1 = ft_printf("sim%-10.1Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-10.5Xsim\n", X);
//     count1 = ft_printf("sim%-10.5Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%10.5Xsim\n", X);
//     count1 = ft_printf("sim%10.5Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%.5Xsim\n", X);
//     count1 = ft_printf("sim%.5Xsim\n", X);
// 	printf("\n%X\n%X\n", count, count1);

// //X (cas spéciaux)

// 	count = printf("sim%.0xsim\n", O);
//     count1 = ft_printf("sim%.0xsim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%0.0xsim\n", O);
//     count1 = ft_printf("sim%0.0xsim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// //s (cas spéciaux)

// 	printf("----------special cases s-------------\n");

// 	count = printf("simon %.0s\n", str);
//     count1 = ft_printf("simon %.0s\n", str);
// 	printf("\n%d\n%d\n", count, count1);

// //u (cas spéciaux)

// 	count = printf("sim%u\n", O);
//     count1 = ft_printf("sim%u\n", O);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%.0usim\n", O);
//     count1 = ft_printf("sim%.0usim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%.025usim\n", O);
//     count1 = ft_printf("sim%.025usim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%0.0usim\n", O);
//     count1 = ft_printf("sim%0.0usim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%.1usim\n", O);
//     count1 = ft_printf("sim%.1usim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%-10.2usim\n", O);
// 	count1 = ft_printf("sim%-10.2usim\n", O);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.5usim\n", O);
//     count1 = ft_printf("sim%-10.5usim\n", O);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.*usim\n", 2, O);
// 	count1 = ft_printf("sim%-10.*usim\n", 2, O);
// 	printf("\n%u\n%u\n", count, count1);

// 	count = printf("sim%-10.*usim\n", 5, O);
//     count1 = ft_printf("sim%-10.*usim\n", 5, O);
// 	printf("\n%u\n%u\n", count, count1);


// //d/i (cas spéciaux)

// 	printf("---------special cases d/i------------\n");

// 	count = printf("sim%.0dsim\n", O);
//     count1 = ft_printf("sim%.0dsim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%.1dsim\n", O);
//     count1 = ft_printf("sim%.1dsim\n", O);
// 	printf("\n%X\n%X\n", count, count1);

// 	count = printf("sim%d\n", O);
//     count1 = ft_printf("sim%d\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%.0dsim\n", O);
//     count1 = ft_printf("sim%.0dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%.025dsim\n", O);
//     count1 = ft_printf("sim%.025dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%0.0dsim\n", O);
//     count1 = ft_printf("sim%0.0dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%.1dsim\n", O);
//     count1 = ft_printf("sim%.1dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.2dsim\n", O);
// 	count1 = ft_printf("sim%-10.2dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.5dsim\n", O);
//     count1 = ft_printf("sim%-10.5dsim\n", O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.*dsim\n", 2, O);
// 	count1 = ft_printf("sim%-10.*dsim\n", 2, O);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("sim%-10.*dsim\n", 5, O);
//     count1 = ft_printf("sim%-10.*dsim\n", 5, O);
// 	printf("\n%d\n%d\n", count, count1);

// //tester

	count = printf("%-5.0xsim\n", 0);
    count1 = ft_printf("%-5.0xsim\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-5.xsim\n", 0);
    count1 = ft_printf("%-5.xsim\n", 0);
	printf("\n%d\n%d\n", count, count1);


	count = printf("%5.0x\n", 0);
    count1 = ft_printf("%5.0x\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.0x\n", 0);
    count1 = ft_printf("%.0x\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.x\n", 0);
    count1 = ft_printf("%.x\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%5.0u\n", 0);
    count1 = ft_printf("%5.0u\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.0u\n", 0);
    count1 = ft_printf("%.0u\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.u\n", 0);
    count1 = ft_printf("%.u\n", 0);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%0051u\n" ,2897916334u);
    count1 = ft_printf("%0051u\n" ,2897916334u);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-68.d%-17p%0051u%-155p\n" ,-1711677117,(void*)4270119997202629886lu,2897916334u,(void*)17920985654296894023lu);
    count1 = ft_printf("%-68.d%-17p%0051u%-155p\n" ,-1711677117,(void*)4270119997202629886lu,2897916334u,(void*)17920985654296894023lu);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-155p\n" ,(void*)17920985654296894023lu);
    count1 = ft_printf("%-155p\n" ,(void*)17920985654296894023lu);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%0124d\n" ,-1312855834);
    count1 = ft_printf("%0124d\n" ,-1312855834);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%0192.0d\n" ,-1158443637);
    count1 = ft_printf("%0192.0d\n" ,-1158443637);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%0192.d\n" ,-1158443637);
    count1 = ft_printf("%0192.d\n" ,-1158443637);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%06d\n" ,-131);
    count1 = ft_printf("%06d\n" ,-131);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%00109x%-37p%-2p%088.119u\n" ,1464143185u,(void*)241136349164329019lu,(void*)11874258080500348230lu,1080220243u);
    count1 = ft_printf("%00109x%-37p%-2p%088.119u\n" ,1464143185u,(void*)241136349164329019lu,(void*)11874258080500348230lu,1080220243u);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%00109x\n" ,1464143185u);
    count1 = ft_printf("%00109x\n" ,1464143185u);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%---37.*s%-30c\n" ,-147,NULL,-42);
    count1 = ft_printf("%---37.*s%-30c\n" ,-147,NULL,-42);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%-30c\n" ,-42);
    count1 = ft_printf("%-30c\n" ,-42);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%---17.*s\n" ,-27,NULL);
    count1 = ft_printf("%---17.*s\n" ,-27,NULL);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%042.*d\n" ,-36,-347688384);
    count1 = ft_printf("%042.*d\n" ,-36,-347688384);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%000171.*u%--117p\n" ,-45,1053046204u,(void*)7148667860416170178lu);
    count1 = ft_printf("%000171.*u%--117p\n" ,-45,1053046204u,(void*)7148667860416170178lu);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%065.*X\n" ,-86,2120226080u);
    count1 = ft_printf("%065.*X\n" ,-86,2120226080u);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%61p\n" ,(void*)16380917327344061827lu);
    count1 = ft_printf("%61p\n" ,(void*)16380917327344061827lu);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%000*.*i\n" ,22,-63,12);
    count1 = ft_printf("%000*.*i\n" ,22,-63,12);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%000*.*i\n" ,22, 63,12);
	count1 = ft_printf("%000*.*i\n" ,22, 63,12);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%000*.*i\n" ,22,-13,12);
	count1 = ft_printf("%000*.*i\n" ,22,-13,12);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%000*.*i\n" ,22, 13,12);
	count1 = ft_printf("%000*.*i\n" ,22, 13,12);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%00022.63i\n" ,12);
    count1 = ft_printf("%00022.63i\n" ,12);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05i\n", 43);
	count1 = ft_printf("%05i\n", 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05.4i\n", 43);
    count1 = ft_printf("%05.4i\n", 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05.*i\n", -3, 43);
	count1 = ft_printf("%05.*i\n", -3, 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05.*i\n", 3, 43);
	count1 = ft_printf("%05.*i\n", 3, 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05.*i\n", -2, 43);
	count1 = ft_printf("%05.*i\n", -2, 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%05.*i\n", 2, 43);
	count1 = ft_printf("%05.*i\n", 2, 43);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%---*d\n" ,-80,1716023880);
    count1 = ft_printf("%---*d\n" ,-80,1716023880);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%---*d\n" ,80,1716023880);
    count1 = ft_printf("%---*d\n" ,80,1716023880);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%*d\n" ,-80,1716023880);
    count1 = ft_printf("%*d\n" ,-80,1716023880);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%*d\n" ,80,1716023880);
    count1 = ft_printf("%*d\n" ,80,1716023880);
	printf("\n%d\n%d\n", count, count1);

	count = printf("sim%.0ssim\n", "hello");
    count1 = ft_printf("sim%.0ssim\n", "hello");
	printf("\n%d\n%d\n", count, count1);

	count = printf("hello, %s.simon\n", NULL);
    count1 = ft_printf("hello, %s.simon\n", NULL);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.03s\n", NULL);
    count1 = ft_printf("%.03s\n", NULL);
	printf("\n%d\n%d\n", count, count1);

	count = printf("%.01s\n", "\0");
    count1 = ft_printf("%.01s\n", "\0");
	printf("\n%d\n%d\n", count, count1);

	count = printf("%3.0s\n", NULL);
    count1 = ft_printf("%3.0s\n", NULL);
	printf("\n%d\n%d\n", count, count1);

	count = printf("test1%3.s\n", NULL);
    count1 = ft_printf("test2%3.s\n", NULL);
	printf("\n%d\n%d\n", count, count1);

	count = printf("a%xb%xc%xd\n", 0, 55555, 100000);
    count1 = ft_printf("a%xb%xc%xd\n", 0, 55555, 100000);
	printf("\n%d\n%d\n", count, count1);

	count = printf("a%x\n", O);
    count1 = ft_printf("a%x\n", O);
	printf("\n%d\n%d\n", count, count1);

// warning

// 	count = printf("%2.9p\n", 1234);
//     count1 = ft_printf("%2.9p\n", 1234);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.5p\n", 0);
//     count1 = ft_printf("%.5p\n", 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.0psim\n", 0);
//     count1 = ft_printf("%.0psim\n", 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%04.3s%-7.4s\n", "hello", "world");
//     count1 = ft_printf("%04.3s%-7.4s\n", "hello", "world");
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%021s\n", NULL);
//     count1 = ft_printf("%021s\n", NULL);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%05c", '\0');
//     count1 = ft_printf("%05c", '\0');
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("% d\n", 9999);
//     count1 = ft_printf("% d\n", 9999);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("% d\n", -9999);
//     count1 = ft_printf("% d\n", -9999);
// 	printf("\n%d\n%d\n", count, count1);

// 	warning

// 	count = printf("%2.9p\n", 1234);
//     count1 = ft_printf("%2.9p\n", 1234);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.5p", 0);
//     count1 = ft_printf("%.5p", 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.0p", 0);
//     count1 = ft_printf("%.0p", 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%04.3s%-7.4s", "hello", "world");
//     count1 = ft_printf("%04.3s%-7.4s", "hello", "world");
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%021s", NULL);
//     count1 = ft_printf("%021s", NULL);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%05c", '\0');
//     count1 = ft_printf("%05c", '\0');
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%05c", 'a');
//     count1 = ft_printf("%05c", 'a');
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.0p, %.p", 0, 0);
//     count1 = ft_printf("%.0p, %.p", 0, 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.5p", 0);
//     count1 = ft_printf("%.5p", 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%2.9p", 1234);
//     count1 = ft_printf("%2.9p", 1234);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%2.9p", 1234567);
//     count1 = ft_printf("%2.9p", 1234567);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%.p, %.0p", 0, 0);
//     count1 = ft_printf("%.p, %.0p", 0, 0);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%x\n", -2147483648);
//     count1 = ft_printf("%x\n", -2147483648);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%015p\n", NULL);
//     count1 = ft_printf("%015p\n", NULL);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%010c", 't');
//     count1 = ft_printf("%010c", 't');
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
//     count1 = ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
//     count1 = ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%-ld\n",-2147483648);
//     count1 = ft_printf("%-d\n",-2147483647 -1);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%-100d\n",-2147483647 -1);;
//     count1 = ft_printf("%-100d\n",-2147483647 -1);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%-100d\n",-2147483647);
//     count1 = ft_printf("%-100d\n",-2147483647);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%100d\n",-2147483647);
//     count1 = ft_printf("%100d\n",-2147483647);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*x %*X %*i %*u\n", 10, 547, 1, 300, 100, -55, 1, -60);
// 	count1 = ft_printf("%*x %*X %*i %*u\n", 10, 547, 1, 300, 100, -55, 1, -60);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*s %*x %*X %*i %*u\n", 1, "hey", 10, 547, 1, 300, 100, -55, 1, -60);
// 	count1 = ft_printf("%*s %*x %*X %*i %*u\n", 1, "hey", 10, 547, 1, 300, 100, -55, 1, -60);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("ultimate4 %*.*x %*.*X\n", 1, 50, 100, 1, 0, 10);
//     count1 = ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 100, 1, 0, 10);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("ultimate2 %*d\n", 1, 5000);
//     count1 = ft_printf("ultimate2 %*d\n", 1, 5000);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*s\n", 1, "hey");
// 	count1 = ft_printf("%*s\n", 1, "hey");
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*x\n", 10, 54700);
// 	count1 = ft_printf("%*x\n", 10, 54700);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*X\n", 1, 300);
// 	count1 = ft_printf("%*X\n", 1, 300);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*i\n", 10000, -55);
// 	count1 = ft_printf("%*i\n", 10000, -55);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%*u\n", 1, -60);
// 	count1 = ft_printf("%*u\n", 1, -60);
// 	printf("\n%d\n%d\n", count, count1);

// 	count = printf("%020.5s", "Hallo heimur");
//     count1 = ft_printf("%020.5s", "Hallo heimur");
// 	printf("\n%d\n%d\n", count, count1);


    return(0);
}*/


/*int main()
{
	char *str = "hello";
	// ft_printf("%09s", "hello");
	ft_printf("%.p", str);
	ft_printf("%2.p", str);
	// ft_printf("%2.9p", 1234);
	// ft_printf("%.5p", 0);
	// ft_printf("%.0p", 0);
	// ft_printf("%021s", NULL);
	// ft_printf("%05s", "hello");
	ft_printf("%*s", -3, "hello");

	return 0;
}*/

/*int main()
{
	
	char *str = "salut\0 cava";
	printf("\n%d", printf("%s", str));
	ft_printf("\n%d\n", ft_printf("%s", str));

	printf("%d\n",printf("|%5X|\n", '\0'));
	printf("%d\n",ft_printf("|%5X|\n", '\0'));
	return 0;
}*/