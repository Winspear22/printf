/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:59:14 by adaloui           #+#    #+#             */
/*   Updated: 2021/07/21 12:35:02 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p(char **s)
{
	unsigned long long	num;
	char				*tmp;

	num = (unsigned long long)va_arg(g_ap, void *);
	*s = ft_itoa_base(num, g_base_16_l);
	tmp = *s;
	*s = ft_strjoin("0x", *s);
	free(tmp);
}
