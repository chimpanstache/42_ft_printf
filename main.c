/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/10 20:01:10 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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



	printf("R:%6p:\n", str); //champ < digit
	printf("-:%-6p:\n", str); //champ < digit
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

int main()  //printf testers
{
	printf(":%011.10x:\n", UINT_MAX);
	printf(":%011.10X:\n", UINT_MAX);
	return (0);
}