/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fpw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:41:04 by adaloui           #+#    #+#             */
/*   Updated: 2021/07/21 12:08:20 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_plus(const char **s)
{
	char	c;

	c = **s;
	if (c == '+')
	{
		g_get_info->plus = 1;
		g_get_info->pluss = 1;
		++(*s);
	}
	else
		return (0);
	return (1);
}

int	read_hastag(const char **s)
{
	char	c;
	char	j;

	c = **s;
	j = s[0][1];
	if (c == '#')
	{
		if (j == 'x')
			g_get_info->hashtag = 1;
		else if (j == 'X')
			g_get_info->hashtag = 2;
		++(*s);
	}
	else
		return (0);
	return (1);
}

int	read_space(const char **s)
{
	char	c;
	char	j;

	c = **s;
	j = s[0][1];
	if (j > 48 && j < 57 && s[0][0] == ' ')
	{
		g_get_info->space = 1;
		ft_putchar_fd(' ', 1);
		g_get_info->add = 1;
		++(*s);
	}
	if (c == ' ')
	{
		g_get_info->space = 1;
		++(*s);
	}
	else
		return (0);
	return (1);
}
