/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:14:42 by akhalidy          #+#    #+#             */
/*   Updated: 2020/01/01 03:12:27 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_r++;
}

int		ft_putstr(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int		ft_inthelist(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

void	ft_conversion(char **format, t_container *v, va_list args)
{
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			*v = ft_fillstruct(format, args);
			if (v->specifier == 'd' || v->specifier == 'i')
				ft_displayd(v, va_arg(args, int));
			else if (v->specifier == 's')
				ft_display_s(v, va_arg(args, char *));
			else if (v->specifier == 'c')
				ft_display_c(v, va_arg(args, int));
			else if (v->specifier == '%')
				ft_display_c(v, '%');
			else if (v->specifier == 'u')
				ft_display_u(v, va_arg(args, int), 10);
			else if (v->specifier == 'x' || v->specifier == 'X')
				ft_display_u(v, va_arg(args, int), 16);
			else if (v->specifier == 'p')
				ft_display_p(v, (long long)va_arg(args, void *), 16);
		}
		else
			ft_putchar(**format);
		(*format)++;
	}
}

int		ft_printf(char *format, ...)
{
	va_list		args;
	t_container v;

	g_r = 0;
	va_start(args, format);
	ft_conversion(&format, &v, args);
	va_end(args);
	return (g_r);
}
