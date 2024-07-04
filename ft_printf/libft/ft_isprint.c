/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:56:21 by emamati           #+#    #+#             */
/*   Updated: 2023/12/07 15:00:56 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(const int arg)
{
	if (32 <= arg && arg <= 126)
		return (1);
	else
		return (0);
}