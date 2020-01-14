/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/14 17:12:29 by ehafidi          ###   ########.fr       */
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

int main()
{
	int age = -1234;
	int khey = 132;

	printf("precision > champ && precision > digit\n");
	printf("/////champ =< digit\n");
	printf("R:%3.10d:\n", age); //champ < digit
	printf("0:%03.10d:\n", age); //champ < digit
	printf("-:%-3.10d:\n", age); //champ < digit
	printf("/////champ > digit\n");
	printf("R:%6.10d:\n", age); //champ > digit
	printf("0:%06.10d:\n", age); //champ > digit
	printf("-:%-6.10d:\n", age); //champ > digit
	printf("champ > precision && champ > digit\n"); //pro fois gerer ces cas quand c'est negatif
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

/*int main()
{
	unsigned int age = 7295;
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