/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:32:27 by ehafidi           #+#    #+#             */
/*   Updated: 2019/10/08 14:29:31 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_strstr(char *str, char *to_find)
{
	int i;
	int a;

	while (str[i] != '\0')
	{
		a = 0;
		while (str[i + a] == to_find[a] && str[i + a] != '\0')
		{
			if (to_find[a + 1] == '\0')
				return (&str[i]);
			a++;
		}
		i++;
	}	
	return (0);
}

