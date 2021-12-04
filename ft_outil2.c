/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:34:15 by akhalidy          #+#    #+#             */
/*   Updated: 2020/01/01 05:02:12 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_struct_initialiser(t_container *v)
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

void			ft_fillzerominustruct(t_container *var, char **fmt)
{
	while (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '-' && !var->minus)
			var->minus = 1;
		while (**fmt == '-')
			(*fmt)++;
		if (**fmt == '0' && !var->zero)
			var->zero = 1;
		while (**fmt == '0')
			(*fmt)++;
	}
}

void			ft_fillwidthstruct(t_container *var, char **fmt, va_list args)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		var->width_exist = 1;
		if (**fmt == '*')
			var->width = va_arg(args, int);
		else
		{
			var->width = ft_atoi(*fmt);
			(*fmt) += ft_numlen(var->width) - 1;
		}
		(*fmt)++;
	}
}

void			ft_fillprecstruct(t_container *v, char **fmt, va_list args)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		v->precision_exist = 1;
		if (**fmt == '*')
			v->precision = va_arg(args, int);
		else
		{
			if (**fmt == '0' && ft_isdigit(*((*fmt) + 1)))
				(*fmt)++;
			v->precision = ft_atoi(*fmt);
			(*fmt) += ft_numlen(v->precision) - 1;
		}
		(*fmt)++;
	}
}

t_container		ft_fillstruct(char **fmt, va_list args)
{
	t_container var;

	ft_struct_initialiser(&var);
	ft_fillzerominustruct(&var, fmt);
	ft_fillwidthstruct(&var, fmt, args);
	if (**fmt == '.')
	{
		var.dot = 1;
		(*fmt)++;
	}
	ft_fillprecstruct(&var, fmt, args);
	(ft_inthelist(**fmt, "cspdiuxX%")) ? var.specifier = **fmt : 1;
	return (var);
}
