/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:24:21 by emamati           #+#    #+#             */
/*   Updated: 2024/02/01 14:57:31 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += hex_len(nb / 16);
	len++;
	return (len);
}

int	putnbr_sub(long int nb, const char flags, int *arg, int len)
{
	if (flags & (1 << FLAGSPACE) && nb >= 0 && !(flags & (1 << FLAGPLUS)))
		len += write(1, " ", 1);
	while (arg[ARGEMPTY] > len || (arg[ARG0] > len && flags & (1 << FLAGDOT)))
		len += write(1, " ", 1);
	if (nb < 0)
		write(1, "-", 1);
	if (flags & (1 << FLAGPLUS) && nb >= 0)
		write(1, "+", 1);
	while (arg[ARG0] > len && !(flags & (1 << FLAGDOT)))
		len += write(1, "0", 1);
	return (len);
}
