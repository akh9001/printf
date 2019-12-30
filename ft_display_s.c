/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_outils_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 04:38:27 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/25 18:39:48 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_m(const char *str, int n)
{
	int i;

	i = -1;
	while (str[++i] && n--)
		ft_putchar(str[i]);
    return(i);
}

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
        i++;
    return (i);
}

void	ft_display_s(t_container *v, char *str)
{
    int len;

    if (!str)
        ft_display_s(v,"(null)");
    else
    {
        len = ft_strlen(str);
    if (v->minus && v->width > 0)
            v->width *= -1;
    if(v->precision >= 0)
    {
        if (!v->dot)
            v->precision = len;
        if (v->width < 0)
            ft_displaychar(' ', -(v->width) - ft_putstr_m(str, v->precision));
        else
        {
            if (v->precision <= len)
                ft_displaychar(' ', v->width - v->precision);
            else
                ft_displaychar(' ', v->width - len);
            ft_putstr_m(str, v->precision);
            
        }     
    }
    else
    {
        ft_displaychar(' ', v->width - len);
        ft_displaychar(' ', -(v->width) - ft_putstr(str));
    }   
    }
}