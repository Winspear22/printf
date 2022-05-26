/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:38:14 by adaloui           #+#    #+#             */
/*   Updated: 2021/07/16 15:11:32 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_len(long long num, int base_len)
{
	if (num)
		return (1 + get_nbr_len(num / base_len, base_len));
	else
		return (0);
}

char	*ft_itoa_base(unsigned long long num, const char *base)
{
	int		len;
	char	*ret;
	int		base_len;

	base_len = (int)ft_strlen(base);
	len = 1 + get_nbr_len(num / base_len, base_len);
	ret = malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = base[(num % base_len)];
		num /= base_len;
	}
	return (ret);
}
