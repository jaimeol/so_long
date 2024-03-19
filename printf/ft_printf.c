/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:19:06 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/06 12:32:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *cont)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), cont);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), cont);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), cont);
	else if (*str == 'x')
		ft_puthexlow_pf(va_arg(va, unsigned int), cont);
	else if (*str == 'X')
		ft_puthexup_pf(va_arg(va, unsigned int), cont);
	else if (*str == 'u')
		ft_putunsigned_pf(va_arg(va, unsigned int), cont);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), cont);
	else if (*str == '%')
		ft_putchar_pf(*str, cont);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	cont;

	if (!str)
		return (0);
	cont = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &cont);
		}
		else
			ft_putchar_pf(*str, &cont);
		str++;
	}
	va_end(va);
	return (cont);
}
