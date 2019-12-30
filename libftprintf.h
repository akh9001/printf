/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:25:13 by akhalidy          #+#    #+#             */
/*   Updated: 2019/12/30 21:37:34 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int g_r;

typedef struct		s_container
{
	int		minus;
	int		zero;
	int		width;
	int		width_exist;
	int		dot;
	int		precision;
	int		precision_exist;
	char	specifier;
}					t_container;

void				ft_struct_initialiser(t_container *v);
t_container			ft_fillstruct(char **fmt, va_list args);
int					ft_printf(char *format, ...);
void				ft_putchar(char c);
int					ft_putstr(const char *str);
void				ft_putnbr(long n);
int					ft_inthelist(char c, char *str);
int					ft_dectohex(unsigned long long x, int i);
void				ft_displaychar(char c, int n);
void				ft_displayd(t_container *c, long n);
void				ft_positiveprecisiond(t_container *v,
					int sign, int len, long n);
void				ft_negativeprecisiond(t_container *v,
					int sign, int len, long n);
void				ft_dotexistd(t_container *v, int sign, int len,
					long n);
void				ft_dotdontexistd(t_container *v, int sign,
					int len, long n);
void				ft_display_u(t_container *c, long long n, int base);
void				ft_positiveprecision_u(t_container *v,
					int base, int len, long long n);
void				ft_negativeprecision_u(t_container *v,
					int base, int len, long long n);
void				ft_dotexist_u(t_container *v, int base, int len,
					long long n);
void				ft_dotdontexist_u(t_container *v, int base,
					int len, long long n);
int					ft_putstr_m(const char *str, int n);
int					ft_strlen(const char *str);
void				ft_display_s(t_container *v, char *str);
void				ft_display_c(t_container *v, int c);
void				ft_put_nbr(long long n, int base, int uppercase, int sign);
int					ft_toupper(int c);
void				ft_display_p(t_container *v, long long n, int base);
void				ft_positiveprecision_p(t_container *v,
					int base, int len, long long n);
void				ft_negativeprecision_p(t_container *v,
					int base, int len, long long n);
void				ft_dotexist_p(t_container *v, int base, int len,
					long long n);
void				ft_dotdontexist_p(t_container *v, int base,
					int len, long long n);
int					ft_numlen(long long n);
void				ft_put_nbr_p(long long n, int base, int uppercase, int sign);

#endif