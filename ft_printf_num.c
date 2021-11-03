/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:16:57 by tmartial          #+#    #+#             */
/*   Updated: 2021/11/03 15:48:24 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_and_i(int num, int *ret)
{
	unsigned int	nbr;

	if (num < 0)
	{
		nbr = (unsigned int)(num * -1);
		ft_putchar('-');
		(*ret)++;
	}
	else
		nbr = (unsigned int)(num);
	if (nbr >= 10)
	{
		print_d_and_i(nbr / 10, ret);
		print_d_and_i(nbr % 10, ret);
	}
	else
	{
		ft_putchar(nbr + '0');
		(*ret)++;
	}
}

void	print_u(unsigned int num, int *ret)
{
	if (num >= 10)
	{
		print_d_and_i(num / 10, ret);
		print_d_and_i(num % 10, ret);
	}
	else
	{
		ft_putchar(num + '0');
		(*ret)++;
	}
}

void	print_hexa(unsigned int hexa, int *ret, int convert)
{
	if (hexa >= 16)
	{
		print_hexa(hexa / 16, ret, convert);
		print_hexa(hexa % 16, ret, convert);
	}
	else if (hexa < 10)
	{
		(*ret)++;
		ft_putchar(hexa + '0');
	}
	else
	{
		ft_putchar(7 + convert + hexa + '0');
		(*ret)++;
	}
}

void	print_hexa_long(unsigned long hexa, int *ret, int convert)
{
	if (hexa >= 16)
	{
		print_hexa_long(hexa / 16, ret, convert);
		print_hexa_long(hexa % 16, ret, convert);
	}
	else if (hexa < 10)
	{
		(*ret)++;
		ft_putchar(hexa + '0');
	}
	else
	{
		ft_putchar(7 + convert + hexa + '0');
		(*ret)++;
	}
}

void	print_p(unsigned long num, int *ret)
{
	write(1, "0x", 2);
	*ret += 2;
	print_hexa_long(num, ret, 32);
}
