/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_uxX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:59:43 by adaloui           #+#    #+#             */
/*   Updated: 2021/07/21 10:46:04 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_ux(char **s, char *base)
{
	unsigned int	num;

	num = va_arg(g_ap, unsigned int);
	if (g_get_info->hashtag == 1 && num != 0)
	{
		ft_putstr_fd("0x", 1);
		g_get_info->add = 2;
	}
	else if (g_get_info->hashtag == 2 && num != 0)
	{
		ft_putstr_fd("0X", 1);
		g_get_info->add = 2;
	}
	*s = ft_itoa_base(num, base);
}
