/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:00:39 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/27 15:04:11 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_displayd(t_container *v, long n)
{
	int sign;
	int len;
	long m;

	sign = 0;
	m = n;
	if (m < 0)
		{
			sign = 1;
			m *= -1;
		}
	len = ft_numlen(m);
	if (!(v->zero) && v->minus && v->width > 0)
			v->width *= -1;
	if (!m && !(v->precision)&& v->dot)
			len = 0;
	if (v->precision_exist)
	{
		if (v->precision >= 0)
			ft_positiveprecisiond(v, sign, len, m);	
		else
	 		ft_negativeprecisiond(v, sign, len, m);
	}
	else
	{
		if (v->dot)
			ft_dotexistd(v, sign, len, m);
		else
			ft_dotdontexistd(v, sign, len,m);
	}
		
}

void	ft_positiveprecisiond(t_container *v, int sign, int len, long n)
{
	if (v->precision < len)
		v->precision = 0;
	if (v->width < 0)
	{
		v->width *= -1;
		if (sign)
			ft_putchar('-');
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_putnbr(n);
		if (v->precision == 0)
			ft_displaychar(' ', v->width - len - sign);
		else
			ft_displaychar(' ', v->width - v->precision - sign);
	}
	else
	{
		if (v->precision == 0)
			ft_displaychar(' ', v->width - len - sign); //a verifier
		else
			ft_displaychar(' ', v->width - v->precision - sign);
		if (sign)
			ft_putchar('-');
		ft_displaychar('0', v->precision - len);
		if (len)
			ft_putnbr(n);
	}
}

void	ft_negativeprecisiond(t_container *v, int sign, int len, long n)
{
	if (v->zero && v->width > 0)
	{
		v->precision = v->width;
		if (sign)
			ft_putchar('-');
		ft_displaychar('0', v->precision - len - sign);
		if (len)
			ft_putnbr(n);
	}
	else if (v->width > 0)
	{
		ft_displaychar(' ', v->width - len - sign);
		if (sign)
			ft_putchar('-');
		if (len)
			ft_putnbr(n);
	}
	else
	{
		if (sign)
			ft_putchar('-');
		if (len)
			ft_putnbr(n);
		ft_displaychar(' ', -(v->width) - len - sign);
	}
}

void	ft_dotdontexistd(t_container *v, int sign, int len, long n)
{
	if (v->width_exist)
	{
		if (v->width > 0)
		{
			if (!v->zero)
				ft_displaychar(' ', v->width -len - sign);
			else
			{
				if (sign)
					ft_putchar('-');
				ft_displaychar('0', v->width - len - sign);
			}
			if(n && !v->zero)
				ft_putnbr(sign ? -n : n);
			else
				ft_putnbr(n);
		}
		else
		{
			ft_putnbr(sign ? -n : n);
			ft_displaychar(' ', -(v->width) - len - sign);
		}
	}
	else
		ft_putnbr(sign ? -n : n);
}

void	ft_dotexistd(t_container *v, int sign, int len, long n)
{
	if (v->width_exist)
	{
		if (v->width > 0)
		{
			ft_displaychar(' ', v->width - len - sign);
			if (n)
				ft_putnbr(sign ? -n : n);
			else if(len)
				ft_displaychar(' ', 1);
		}
		else
		{
			if (n)
				ft_putnbr(sign ? -n : n);
			ft_displaychar(' ', -(v->width) - len - sign);
		}
	}
	else
		if (n)
			ft_putnbr(sign ? -n : n);
			
}
