/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:14:42 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/30 21:37:18 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_r++;
}

int	ft_putstr(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return(i);
}

int	ft_inthelist(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
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

int	ft_atoi(const char *str)
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

void	ft_struct_initialiser(t_container *v)
{
	v->minus = 0;
	v->zero = 0;
	v->width = 0;
	v->width_exist = 0;
	v->dot = 0;
	v->precision = 0;
	v->precision_exist = 0;
	v->specifier = 0;
}

t_container	ft_fillstruct(char **fmt, va_list args)
{
	t_container var;

	ft_struct_initialiser(&var);
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '-' && !var.minus)
			var.minus = 1;
		while (**fmt == '-')
			(*fmt)++;
		if (**fmt == '0' && !var.zero)
			var.zero = 1;
		while (**fmt == '0')
			(*fmt)++;
	}
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		var.width_exist = 1;
		if (**fmt == '*')
			var.width = va_arg(args, int);
		else
		{
			var.width = ft_atoi(*fmt);
			(*fmt) += ft_numlen(var.width) - 1;
		}
		(*fmt)++;
	}
	if (**fmt == '.')
	{
		var.dot = 1;
		(*fmt)++;
	}
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		var.precision_exist = 1;
		if (**fmt == '*')
			var.precision = va_arg(args, int);
		else
		{
			if (**fmt == '0' && ft_isdigit(*((*fmt) + 1)))
				(*fmt)++;
			var.precision = ft_atoi(*fmt);
			(*fmt) += ft_numlen(var.precision) - 1;
		}
		(*fmt)++;
	}
	if (ft_inthelist(**fmt, "cspdiuxX%"))
		var.specifier = **fmt;
	return (var);
}



int		ft_printf(char *format, ...)
{
	va_list args;
	t_container v;

	g_r = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			v = ft_fillstruct(&format, args);
			/*printf ("0 = %d\n",v.minus);
			printf("- = %d\n",v.zero);
			printf("width = %d\n",v.width);
			printf("width_ex = %d\n",v.width_exist);
			printf("dot = %d\n",v.dot);
			printf("precision = %d\n",v.precision);
			printf("precision_ex = %d\n",v.precision_exist);
			printf("specifier = %c\n",v.specifier);*/
			if (v.specifier == 'd' || v.specifier == 'i')
				ft_displayd(&v, va_arg(args, int));
			else if (v.specifier == 's')
				ft_display_s(&v, va_arg(args, char *));
			else if (v.specifier == 'c' || v.specifier == '%')
			{	
				if (v.specifier == 'c')
					ft_display_c(&v, va_arg(args, int));
				else
					ft_display_c(&v,'%');
			}	
			else if (v.specifier == 'u') // || v.specifier == 'x' || v.specifier == 'X'
				ft_display_u(&v, va_arg(args, int), 10);
			else if (v.specifier == 'x' || v.specifier == 'X') // || v.specifier == 'x' || v.specifier == 'X'
				ft_display_u(&v, va_arg(args, int), 16);
			else if (v.specifier == 'p')
				ft_display_p(&v, (long long)va_arg(args, void *), 16);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (g_r);
}
