/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:40:17 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/30 21:37:58 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_p(t_container *v, long long n, int base)
{
	int len;
	//unsigned long m;

	//m = n;
	//printf("%lu\n",m);
	len  = 2;
	//if (n < 0)
	//	len += ft_dectohex(m, 1);
	//else
		len += ft_dectohex(n, 1);
	if (v->minus && v->width > 0)
			v->width *= -1;
	/*if (!n && !(v->precision)&& v->dot)
			len = 0;*/
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
			ft_dotdontexist_p(v, base, len,n);
	}
		
}


/*void	ft_display_u(t_container *v, long long n, int base)
{
	int len;
	unsigned int m;

	m = n;
	if (base == 16)
		len = ft_dectohex(m, 1);	
	else
		len = ft_numlen(m);
	if (!(v->zero) && v->minus && v->width > 0)
			v->width *= -1;
	if (!m && !(v->precision)&& v->dot)
			len = 0;
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
			ft_dotdontexist_u(v, base, len,m);
	}
		
}*/

void	ft_positiveprecision_p(t_container *v, int base, int len, long long n)
{
	if (v->precision < len)
		v->precision = 0;
	if (v->width < 0)
	{
		v->width *= -1;
		ft_displaychar('0', v->precision - len);
		if (len)
		{
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);	
		}
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
		{
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);	
		}
	}
}

void	ft_negativeprecision_p(t_container *v, int base, int len, long long n)
{
	if (v->zero && v->width > 0)
	{
		v->precision = v->width;
		ft_displaychar('0', v->precision - len);
		if (len)
		{
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);
        }
	}
	else if (v->width > 0)
	{
		ft_displaychar(' ', v->width - len);
		if (len)
		{
            ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);
		}
	}
	else
	{
		if (len)
		{
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);
		}
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
				ft_displaychar(' ', v->width -len);
			else
				ft_displaychar('0', v->width - len);
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);
		}
		else
		{
			ft_putchar('0');
			ft_putchar('x');
			ft_put_nbr_p(n, base, 0, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else
	{
			ft_putchar('0');
			ft_putchar('x');
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
			ft_putchar('0');
			ft_putchar('x');
		
		    if (n)
			ft_put_nbr_p(n, base, 0, 0);
		    /*else if(len && !(v->specifier == 'p'))
				ft_displaychar(' ', 1);*/
        }
		else
		{
			ft_putchar('0');
			ft_putchar('x');
		    if (n)
				ft_put_nbr_p(n, base, 0, 0);
			ft_displaychar(' ', -(v->width) - len);
		}
	}
	else
	{
		ft_putchar('0');
		ft_putchar('x');
		if (n)
			ft_put_nbr_p(n, base, 0, 0);
	}
			
}
