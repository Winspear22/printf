/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:56:45 by adaloui           #+#    #+#             */
/*   Updated: 2021/08/30 16:19:43 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list			*g_get_info;
va_list			g_ap;
char			*g_base_16_l = "0123456789abcdef";
char			*g_base_16_u = "0123456789ABCDEF";
char			*g_base_10 = "0123456789";

void	ft_init_info(void)
{
	g_get_info->add = 0;
	g_get_info->addd = 0;
	g_get_info->plus = 0;
	g_get_info->pluss = 0;
	g_get_info->hashtag = 0;
	g_get_info->space = 0;
	g_get_info->type = 0;
}

char	*get_format_string(void)
{
	char	t;
	char	*format_str;

	format_str = 0;
	t = g_get_info->type;
	if (t == 'c')
		ft_conv_c(&format_str, va_arg(g_ap, int));
	else if (t == 's')
		ft_conv_s(&format_str);
	else if (t == 'x')
		ft_conv_ux(&format_str, g_base_16_l);
	else if (t == 'X')
		ft_conv_ux(&format_str, g_base_16_u);
	else if (t == 'd' || t == 'i')
		ft_conv_di(&format_str);
	else if (t == 'u')
		ft_conv_ux(&format_str, g_base_10);
	else if (t == 'p')
		ft_conv_p(&format_str);
	else if (t == '%')
		ft_conv_c(&format_str, '%');
	return (format_str);
}

void	ft_parse(const char *s, char *rtn, size_t *len)
{
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			ft_init_info();
			while (read_plus(&s) || read_hastag(&s) || read_space(&s))
				;
			g_get_info->type = *(s++);
			rtn = get_format_string();
			*len += ft_strlen(rtn) + g_get_info->add + g_get_info->addd;
			ft_putstr_fd(rtn, 1);
			free(rtn);
			rtn = 0;
		}
		else
		{
			ft_putchar_fd(*s++, 1);
			++(*len);
		}
	}
}

int	ft_printf(const char *s, ...)
{
	size_t	len;

	len = 0;
	va_start(g_ap, s);
	g_get_info = malloc(sizeof(t_list));
	ft_parse(s, 0, &len);
	va_end(g_ap);
	free(g_get_info);
	return ((int)len);
}
