/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:55:55 by adaloui           #+#    #+#             */
/*   Updated: 2021/07/21 11:34:03 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_di(char **s)
{
	long long	num;

	num = va_arg(g_ap, int);
	if (num < 0)
		g_get_info->pluss = 0;
	if (g_get_info->plus == 1 && g_get_info->pluss == 1)
	{
		g_get_info->space = 0;
		g_get_info->add = 1;
		ft_putchar_fd('+', 1);
	}
	if (g_get_info->space == 1 && num >= 0)
	{
		g_get_info->add = 1;
		ft_putchar_fd(' ', 1);
	}
	*s = ft_itoa(num);
}
