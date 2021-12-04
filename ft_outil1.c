/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 21:23:00 by akhalidy          #+#    #+#             */
/*   Updated: 2020/01/01 02:51:08 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_p(long long n, int base)
{
	ft_putstr("0x");
	ft_put_nbr_p(n, base, 0, 0);
}

int		ft_atoi(const char *str)
{
	char			*s;
	int				signe;
	unsigned long	x;

	s = (char*)str;
	signe = 1;
	x = 0;
	while (*s >= '0' && *s <= '9')
	{
		x = x * 10 + (*s - '0');
		s++;
		if (x > 9223372036854775807)
			return (signe < 0 ? 0 : -1);
	}
	return (signe * x);
}

void	ft_displaychar(char c, int n)
{
	int i;

	i = n;
	while (i-- > 0)
		ft_putchar(c);
}

int		ft_numlen(long long n)
{
	int i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
