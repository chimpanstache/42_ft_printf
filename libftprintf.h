/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:41:29 by ehafidi           #+#    #+#             */
/*   Updated: 2019/12/19 17:25:27 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define MINUS (1 << 0)
#define ZERO (1 << 1)
#define RANGE (1 << 2)
#define CHAMP (1 << 3)

void	ft_putchar(char c);
void	ft_putnbr_base(int n, char *base);
int		ft_strlen(char *base);
int		ft_atoi(const char *str);
int		ft_attribute(char *str);
int		ft_champ(char *str, va_list *prms);
int 	ft_precision(char *str);

#endif