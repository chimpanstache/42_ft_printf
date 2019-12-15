/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:01:47 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/09 15:45:28 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void 	print_ints(int num, ...) //toujours mettre l'arg requis en prems, qui nous dira a propos des arg suivants, dans printf c'est la string de format. Qui nous dit ce qu,il y a ensuite
{
	va_list args;

	va_start(args, num);

	for (int i = 0; i < num ; i++)
	{
		int value = va_arg(args, int);
		printf("%d: %d\n", i, value);
	}
	va_end(args);
}

int 	main()
{
	print_ints(, 32, 334, 3333, 999);
	return (0);
}