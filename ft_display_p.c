/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:40:17 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/31 21:28:36 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_p(t_container *v, long long n, int base)
{
	int len;

	len = 2;
	len += ft_dectohex(n, 1);
	if (v->minus && v->width > 0)
		v->width *= -1;
	if (v->precision_exist)
	{
		if (v->precision >= 0)
			ft_positiveprecision_p(v, base, len, n);
		else
			ft_negativeprecision_p(v, base, len, n);
	}
	else
	{
		if (v->dot)
			ft_dotexist_p(v, base, len, n);
		else
			ft_dotdontexist_p(v, base, len, n);
	}
}

void	ft_positiveprecision_p(t_container *v, int base, int len, long long n)
{
	if (v->precision < len)
		v->precision = 0;
	if (v->width < 0)
	{
		v->width *= -1;
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_put_p(n, base);
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
		if (len)
			ft_put_p(n, base);
	}
}

void	ft_negativeprecision_p(t_container *v, int base, int len, long long n)
{
	if (v->zero && v->width > 0)
	{
		v->precision = v->width;
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_put_p(n, base);
	}
	else if (v->width > 0)
	{
		ft_displaychar(' ', v->width - len);
		if (len)
			ft_put_p(n, base);
	}
	else
	{
		if (len)
			ft_put_p(n, base);
		ft_displaychar(' ', -(v->width) - len);
	}
}

void	ft_dotdontexist_p(t_container *v, int base, int len, long long n)
{
	if (v->width_exist)
	{
		if (v->width > 0)
		{
			if (!v->zero)
				ft_displaychar(' ', v->width - len);
			else
				ft_displaychar('0', v->width - len);
			ft_putstr("0x");
			ft_put_nbr_p(n, base, 0, 0);
		}
		else
		{
			ft_putstr("0x");
			ft_put_nbr_p(n, base, 0, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else
	{
		ft_putstr("0x");
		ft_put_nbr_p(n, base, 0, 0);
	}
}

void	ft_dotexist_p(t_container *v, int base, int len, long long n)
{
	if (v->width_exist)
	{
		if (!n)
			len--;
		if (v->width > 0)
		{
			ft_displaychar(' ', v->width - len);
			ft_putstr("0x");
			if (n)
				ft_put_nbr_p(n, base, 0, 0);
		}
		else
		{
			ft_putstr("0x");
			if (n)
				ft_put_nbr_p(n, base, 0, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else
	{
		ft_putstr("0x");
		if (n)
			ft_put_nbr_p(n, base, 0, 0);
	}
}
