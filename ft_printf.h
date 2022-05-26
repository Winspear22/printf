/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:52:52 by adaloui           #+#    #+#             */
/*   Updated: 2021/08/30 16:40:54 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				plus;
	int				pluss;
	int				add;
	int				addd;
	int				hashtag;
	int				space;
	char			type;
}					t_list;

extern va_list		g_ap;
extern t_list		*g_get_info;
extern char			*g_base_16_l;
extern char			*g_base_16_u;
extern char			*g_base_10;

void	ft_parse(const char *s, char *rtn, size_t *len);
void	ft_conv_c(char **s, char c);
void	ft_conv_s(char **s);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_conv_di(char **s);
void	ft_conv_ux(char **s, char *base);

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *s, ...);
void	ft_init_info(void);
char	*get_format_string(void);

char	*ft_itoa_base(unsigned long long num, const char *base);

void	ft_conv_p(char **s);
int		read_plus(const char **s);
int		read_hastag(const char **s);
int		read_space(const char **s);

#endif
