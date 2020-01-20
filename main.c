/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/20 16:29:00 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MINUS (1 << 0)
#define ZERO (1 << 1)
#define RANGE (1 << 2)
#define CHAMP (1 << 3)

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

/*int main()
{
	char age = 'h';
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%c:\n", age); //champ < digit
	printf("0:%c:\n", age); //champ < digit
	printf("-:%-3.10c:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10c:\n", age); //champ > digit
	printf("0:%06.10c:\n", age); //champ > digit
	printf("-:%-6.10c:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%10.3c:\n", age); //precision < digit
	printf("0:%010.3c:\n", age); //precision < digit
	printf("-:%-10.3c:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6c:\n", age); //precision > digit
	printf("0:%010.6c:\n", age); //precision > digit 
	printf("-:%-10.6c:\n", age); //precision > digit
	return (0);	
}*/

/*int main()
{
	char *age = "choc";
	int khey = 132;

	printf("digit > champ\n");
	printf("/////precision =< digit\n");
	printf("R:%2.3s:\n", age); //champ < digit
	printf("-:%2.3s:\n", age); //champ < digit
	printf("/////precision > digit\n");
	printf("R:%2.6s:\n", age); //champ < digit
	printf("-:%-2.6s:\n", age); //champ < digit
	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10s:\n", age); //champ < digit
	printf("-:%-3.10s:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10s:\n", age); //champ > digit
	printf("-:%-6.10s:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%10.3s:\n", age); //precision < digit
	printf("-:%-10.3s:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6s:\n", age); //precision > digit
	printf("-:%-10.6s:\n", age); //precision > digit
	printf("/////precision == 0\n");
	printf("R:%10.s:\n", age); //precision > digit
	printf("-:%-10.s:\n", age); //precision > digit
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

/*int main()
{
	int age = 1234;
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

/*int main()  //tout fonctionne si nombre positif
{
	char *str;
	char *str1 = "1234";
	char *str2 = "1234";
	char *str3 = "1234";

	printf("%p\n", str); //champ < digit
	printf("%p\n", str1); //champ < digit
	printf("%p\n", str2); //champ < digit
	printf("%p\n", str3); //champ > digit
	return (0);
}*/

/*int main()
{
	unsigned int age = 1234;
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
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

/*int main()
{
	char age[] = "7295";
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10s:\n", age); //champ < digit
	printf("-:%-3.10s:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10s:\n", age); //champ > digit
	printf("-:%-6.10s:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
	printf("/////precision =< digit\n");
	printf("R:%10.3s:\n", age); //precision < digit
	printf("-:%-10.3s:\n", age); //precision < digit
	printf("/////precision > digit\n");
	printf("R:%10.6s:\n", age); //precision > digit 
	printf("-:%-10.6s:\n", age); //precision > digit
	return (0);	
}*/

int main()  //tout fonctionne si nombre positif
{
	int age = 1234;
	int *p = &age;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
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
	//ft_printf("%p\n", str); //champ < digit
	printf("%p\n", p); //champ < digit
	//ft_printf("%p\n", p); //champ < digit
	printf("%p\n", p1); //champ < digit
	//ft_printf("%p\n", p1); //champ < digit
	printf("%p\n", p2); //champ < digit
	//ft_printf("%p\n", p2); //champ < digit
	printf("%p\n", p3); //champ < digit
	//ft_printf("%p\n", p3); //champ < digit
	printf("%p\n", p4); //champ < digit
	//ft_printf("%p\n", p4); //champ < digit
	printf("%p\n", p5); //champ < digit
	//ft_printf("%p\n", p5); //champ < digit
	
	return (0);
}*/