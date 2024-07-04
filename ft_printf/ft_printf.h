/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:26:57 by emamati           #+#    #+#             */
/*   Updated: 2024/02/15 14:57:44 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# define ARGEMPTY 3
# define ARGMINUS 0
# define ARG0 1
# define ARGDOT 2
# define FLAGDOT 5
# define FLAGMINUS 4
# define FLAG0 3
# define FLAGPLUS 2
# define FLAGSHARP 1
# define FLAGSPACE 0

typedef struct t_FormatInfo
{
	char	flags;
	int		arg[4];
}			t_FormatInfo;

int			ft_printf(const char *args, ...);
int			type_hex(unsigned long nb, unsigned char flags, char type,
				int *arg);
int			ft_putnbr_long(long int nb, unsigned char flags, int *arg);
int			type_s(char *print_arg, unsigned char flags, int *arg);
int			type_c(char c, unsigned char flags, int *arg);
int			type_percent(unsigned char flags, int *arg);
int			ft_puthex(unsigned long nb, char type);
int			put_num(long int nb);
int			num_len(long long nb);
int			get_len(unsigned char flags, char type, int *arg, unsigned long nb);
int			str_len(const char *arg);
int			hex_len(unsigned long int nb);
int			putnbr_sub(long int nb, const char flags, int *arg, int len);

#endif
