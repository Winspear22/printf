/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_arg_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:55:39 by adaloui           #+#    #+#             */
/*   Updated: 2021/08/30 16:40:56 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(char **s, char c)
{
	int	g_cnull;

	g_cnull = !c;
	if (g_cnull)
	{
		ft_putchar_fd(0, 1);
		g_get_info->addd = 1;
		g_cnull = -1;
	}
	*s = malloc(2);
	(*s)[0] = c;
	(*s)[1] = 0;
}

void	ft_conv_s(char **s)
{
	*s = va_arg(g_ap, char *);
	if (*s == NULL)
	{
		*s = "(null)";
		*s = ft_strjoin(*s, "\0");
	}
	else
		*s = ft_strjoin(*s, "");
}
