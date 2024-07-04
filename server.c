/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:14:48 by emamati           #+#    #+#             */
/*   Updated: 2024/06/30 17:22:58 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <signal.h>

char	*addtostr(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	if (str)
	{
		newstr = malloc(ft_strlen(str) + 2);
		while (str[i])
		{
			newstr[i] = str[i];
			i++;
		}
	}
	else
		newstr = malloc(2);
	newstr[i] = c;
	newstr[i + 1] = 0;
	free(str);
	return (newstr);
}

void	signal_handler(int signal)
{
	static char	*str;
	static int	i;
	static char	c;

	if (i < 7)
		if (signal == SIGUSR1)
			c |= 1 << i;
	i++;
	if (i == 7)
	{
		if (c != 0)
			str = addtostr(str, c);
		else
		{
			if (str == NULL)
				exit((ft_printf("\nServer exits\n"), 0));
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server pid: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
