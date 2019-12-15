/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:00:13 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/15 17:25:41 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int age = 18;
	int keh = 10;
	int zbb = 5;
	int pim = 20;
	int pam = 7;
	int pom = 9;
	char str[] = "zbb";
	
	printf("1:%10d:\n", age);
	printf("4:%.10d:\n", age);
	printf("3:%010d:\n", age);
	printf("3:%10.d:\n", age);
	printf("4:%d:\n", age);
	printf("5:%010.5d:\n", age);
	printf("6:%-10d:\n", age);
	printf("7:%-10.5d:\n", age);
	printf("7:%-10.3d:\n", age);
	printf("8:%2d:\n", age);
	printf("9:%50d:\n", age);
	printf("0:%.d:\n", age);
	printf("0:%*d:\n", age, zbb);
	printf("0:%.1s:\n", str);
	return (0);
}
