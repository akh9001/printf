/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 20:59:27 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/29 20:37:08 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display_c(t_container *v, int c)
{
    if (v->minus && v->width > 0)
            v->width *= -1;
    if (!v->zero)
    {
        ft_displaychar(' ', v->width - 1);
        ft_putchar(c);
    }
    else if (v->specifier == '%')
    {
        ft_displaychar('0', v->width - 1);
        ft_putchar(c);
    }
    ft_displaychar(' ', -(v->width) - 1);
}