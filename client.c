/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:14:23 by emamati           #+#    #+#             */
/*   Updated: 2024/06/30 17:14:26 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include <ctype.h>
#include <signal.h>

void	send_sig(char *message, pid_t id)
{
	int	i;
	int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 7)
		{
			if (message[i] & (1 << j))
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	j = 0;
	while (j < 7)
	{
		kill(id, SIGUSR2);
		j++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	id;
	int		i;

	id = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "\nWrong parameters. Usage: ./client <PID> <MESSAGE>\n\n", 54);
		return (-1);
	}
	if (!argv[2])
	{
		write(1, "\nEmpty Message\n\n", 16);
		return (-1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			write(1, "\nInvalid PID\n\n", 14);
			return (-1);
		}
		i++;
	}
	send_sig(argv[2], id);
}
