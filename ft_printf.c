/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:16:49 by tmartial          #+#    #+#             */
/*   Updated: 2021/11/03 12:18:11 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	i;
	int	ret;

	va_list(arg);
	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			check_percentage((char)str[i], arg, &ret);
		}
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
		i++;
	}
	return (ret);
}

void	check_percentage(char letter, va_list arg, int *ret)
{
	if (letter == 'c')
		print_c(va_arg(arg, int), ret);
	else if (letter == 's')
		print_s(va_arg(arg, char *), ret);
	else if (letter == 'p')
		print_p(va_arg(arg, unsigned long), ret);
	else if (letter == 'i' || letter == 'd')
		print_d_and_i(va_arg(arg, int), ret);
	else if (letter == 'u')
		print_u(va_arg(arg, unsigned int), ret);
	else if (letter == 'x')
		print_hexa(va_arg(arg, unsigned int), ret, 32);
	else if (letter == 'X')
		print_hexa(va_arg(arg, unsigned long int), ret, 0);
	else if (letter == '%')
	{
		(*ret)++;
		ft_putchar('%');
	}
}
