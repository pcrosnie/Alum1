/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:34:00 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/21 18:02:08 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_human_play(int n)
{
	int		nb;
	char	*str;

	str = (char *)malloc(sizeof(char) * 200);
	read(0, str, 200);
	nb = ft_atoi(str);
	nb = ft_little_check(str, nb);
	while (1)
	{
		str = ft_memset(str, 0, 200);
		if (n < 3)
		{
			if (nb >= 1 && nb <= n)
				return (nb);
			else
				nb = ft_human_retry(n, nb, str);
		}
		if (n >= 3)
		{
			if (nb >= 1 && nb <= 3)
				return (nb);
			else
				nb = ft_human_retry(3, nb, str);
		}
	}
}

void	ft_print_pipe(int *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (j < tab[i])
		{
			ft_putchar('|');
			j++;
		}
		ft_putstr("  ");
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_cpu_play(int tab, int n)
{
	int nb;

	if (n == 0)
	{
		if (nb % 4 != 0)
			return (nb % 4);
		return (1);
	}
	if (n == 1)
	{
		nb = (tab % 4) - 1;
		if (tab == 4)
			return (3);
		if (nb <= 3 && nb >= 1)
			return (nb);
	}
	return (1);
}

int		*fill_strategy(int *tab, int n)
{
	int i;
	int *str;

	i = 1;
	str = (int *)malloc(sizeof(int) * n);
	str[0] = 1;
	while (i < n)
	{
		if (tab[i - 1] % 4 == 1)
			str[i] = 0;
		else
			str[i] = 1;
		i++;
	}
	return (str);
}

int		ft_play(int *tab)
{
	int i;
	int	*sol;

	i = ft_count_rows(tab);
	sol = fill_strategy(tab, i);
	while (tab[0] != 0)
	{
		if (tab[i] == 0)
			i--;
		ft_putstr("Human plays :\n");
		tab[i] -= ft_human_play(tab[i]);
		if (tab[0] == 0)
			return (1);
		ft_print_pipe(tab);
		if (tab[i] == 0)
			i--;
		tab[i] -= ft_cpu_play(tab[i], sol[i]);
		if (tab[0] == 0)
			return (0);
		ft_putstr("AI plays :\n");
		ft_print_pipe(tab);
	}
	return (0);
}
