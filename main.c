/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/07 14:11:34 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define MINUS (1 << 0)
#define ZERO (1 << 1)
#define RANGE (1 << 2)
#define CHAMP (1 << 3)

int main()
{
	int age = 122;
	int khey = 132;

	printf("2:%.10d:\n", age);
	printf("2:%0.10d:\n", age);
	printf("3:%010d:\n", age);
	printf("4:%10.d:\n", age);
	printf("4:%10d:\n", age);
	printf("1:%17d:\n", age);
	printf("5:%d:\n", age);
	printf("6:%.5d:\n", age);
	printf("7:%-10d:\n", age);
	printf("8:%-10.5d:\n", age);
	printf("9:%10.5d:\n", age);
	printf("10:%2d:\n", age);
	printf("11:%5.10d:\n", age);
	printf("11:%5.4d:\n", age);
	printf("11:%5.6d:\n", age);
	printf("11:%5.2d:\n", age);
	printf("12:%*d:\n", khey, age);
	printf("13:%*d:\n", age, khey);
	/*printf("0:%.5d:\n", age);
	printf("1:%17d:\n", age);*/
	return (0);
}

/*int main()
{
	int f;
	int i = 0;

	f = MINUS;
	printf("%d", f);
	
}*/

