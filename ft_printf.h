/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:20:08 by tmartial          #+#    #+#             */
/*   Updated: 2021/11/03 12:20:08 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
void	check_percentage(char letter, va_list arg, int *ret);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_c(char c, int *ret);
void	print_s(char *str, int *ret);
void	print_p(unsigned long num, int *ret);
void	print_d_and_i(int num, int *ret);
void	print_u(unsigned int num, int *ret);
void	print_hexa(unsigned int hexa, int *ret, int convert);
void	print_hexa_long(unsigned long hexa, int *ret, int convert);
void	ft_putchar(char c);

#endif