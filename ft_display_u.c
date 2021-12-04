/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 01:01:28 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/31 22:29:29 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_u(t_container *v, long long n, int base)
{
	int				len;
	unsigned int	m;

	m = n;
	if (base == 16)
		len = ft_dectohex(m, 1);
	else
		len = ft_numlen(m);
	if (!(v->zero) && v->minus && v->width > 0)
		v->width *= -1;
	(!m && !(v->precision) && v->dot) ? len = 0 : 1;
	if (v->precision_exist)
	{
		if (v->precision >= 0)
			ft_positiveprecision_u(v, base, len, m);
		else
			ft_negativeprecision_u(v, base, len, m);
	}
	else
	{
		if (v->dot)
			ft_dotexist_u(v, base, len, m);
		else
			ft_dotdontexist_u(v, base, len, m);
	}
}

void	ft_positiveprecision_u(t_container *v, int base, int len, long long n)
{
	int up;

	up = 0;
	(v->specifier == 'X') ? up = 1 : 1;
	(v->precision < len) ? v->precision = 0 : 1;
	if (v->width < 0)
	{
		v->width *= -1;
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_put_nbr(n, base, up, 0);
		if (v->precision == 0)
			ft_displaychar(' ', v->width - len);
		else
			ft_displaychar(' ', v->width - v->precision);
	}
	else
	{
		if (v->precision == 0)
			ft_displaychar(' ', v->width - len);
		else
			ft_displaychar(' ', v->width - v->precision);
		ft_displaychar('0', v->precision - len);
		(len) ? ft_put_nbr(n, base, up, 0) : 1;
	}
}

void	ft_negativeprecision_u(t_container *v, int base, int len, long long n)
{
	int up;

	up = 0;
	if (v->specifier == 'X')
		up = 1;
	if (v->zero && v->width > 0)
	{
		v->precision = v->width;
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_put_nbr(n, base, up, 0);
	}
	else if (v->width > 0)
	{
		ft_displaychar(' ', v->width - len);
		if (len)
			ft_put_nbr(n, base, up, 0);
	}
	else
	{
		if (len)
			ft_put_nbr(n, base, up, 0);
		ft_displaychar(' ', -(v->width) - len);
	}
}

void	ft_dotdontexist_u(t_container *v, int base, int len, long long n)
{
	int up;

	up = 0;
	if (v->specifier == 'X')
		up = 1;
	if (v->width_exist)
	{
		if (v->width > 0)
		{
			if (!v->zero)
				ft_displaychar(' ', v->width - len);
			else
				ft_displaychar('0', v->width - len);
			ft_put_nbr(n, base, up, 0);
		}
		else
		{
			ft_put_nbr(n, base, up, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else
		ft_put_nbr(n, base, up, 0);
}

void	ft_dotexist_u(t_container *v, int base, int len, long long n)
{
	int up;

	up = 0;
	if (v->specifier == 'X')
		up = 1;
	if (v->width_exist)
	{
		if (v->width > 0)
		{
			ft_displaychar(' ', v->width - len);
			if (n)
				ft_put_nbr(n, base, up, 0);
			else if (len)
				ft_displaychar(' ', 1);
		}
		else
		{
			if (n)
				ft_put_nbr(n, base, up, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else if (n)
		ft_put_nbr(n, base, up, 0);
}
