/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:02:53 by akhalidy          #+#    #+#             */
/*   Updated: 2020/01/01 01:22:07 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_put_nbr(long long n, int base, int uppercase, int sign)
{
	char			*str;
	unsigned int	m;

	str = "0123456789abcdef";
	if (sign)
	{
		if (n < 0)
		{
			ft_putchar('-');
			m = -n;
		}
		else
			m = n;
	}
	else
		m = n;
	if (m >= (long long)base)
	{
		ft_put_nbr(m / base, base, uppercase, sign);
		ft_putchar(uppercase ? ft_toupper(str[m % base]) : str[m % base]);
	}
	if (m < (long long)base)
	{
		ft_putchar(uppercase ? ft_toupper(str[m % base]) : str[m % base]);
	}
}

void	ft_put_nbr_p(long long n, int base, int uppercase, int sign)
{
	char					*str;
	unsigned long long		m;

	str = "0123456789abcdef";
	m = n;
	if (m >= (unsigned long long)base)
	{
		ft_put_nbr_p(m / base, base, uppercase, sign);
		ft_putchar(uppercase ? ft_toupper(str[m % base]) : str[m % base]);
	}
	if (m < (unsigned long long)base)
	{
		ft_putchar(uppercase ? ft_toupper(str[m % base]) : str[m % base]);
	}
}

void	ft_putnbr(long n)
{
	unsigned int m;

	if (n < 0)
	{
		ft_putchar('-');
		m = -n;
	}
	else
		m = n;
	if (m >= 10)
	{
		ft_putnbr(m / 10);
		ft_putchar(m % 10 + '0');
	}
	if (m < 10)
		ft_putchar(m % 10 + '0');
}

int		ft_dectohex(unsigned long long x, int i)
{
	if (x / 16 == 0)
	{
		return (i);
	}
	if (x / 16 > 0)
	{
		i++;
		return (ft_dectohex(x / 16, i));
	}
	else
		return (i);
}
