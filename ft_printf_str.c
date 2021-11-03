/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:17:02 by tmartial          #+#    #+#             */
/*   Updated: 2021/11/03 12:19:30 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_c(char c, int *ret)
{
	write(1, &c, 1);
	(*ret)++;
}

void	print_s(char *str, int *ret)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
			(*ret)++;
		}
	}
}
