/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:14:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/21 18:03:56 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_little_check(char *str, int n)
{
	int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != ' ' && str[i] != '\n'
				&& str[i] != '\v' && str[i] != '\t' && str[i] != 0)
			return (4);
		i++;
	}
	return (n);
}

int		ft_complete(char *buf, int i, char *tmp)
{
	if (buf[i - 1] <= 57 && buf[i - 1] >= 48)
	{
		if (ft_atoi(tmp) > 10000 || ft_atoi(tmp) < 0)
			return (0);
		else
			return (ft_atoi(tmp));
	}
	return (0);
}

int		fill_tab_std_pipe(char *buf)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '|')
			return (0);
		if (buf[i] == '|')
			n++;
		i++;
	}
	return (n);
}

int		ft_human_retry(int n, int nb, char *str)
{
	ft_putstr("Input a number between 1 and ");
	ft_putnbr(n);
	ft_putchar('\n');
	read(0, str, 10);
	nb = ft_atoi(str);
	nb = ft_little_check(str, nb);
	return (nb);
}
