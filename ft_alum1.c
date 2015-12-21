/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alum1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:49:04 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/21 17:53:20 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		*fill_tab(char *buf, int fd)
{
	int i;
	int j;
	int *tab;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int) * 8000000);
	tab = ft_memset(tab, 0, 8000000);
	while (buf[i])
	{
		if (buf[i] == '|')
			tab[j]++;
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			return (NULL);
		if (i > 0)
			if (buf[i - 1] == '\n')
				j++;
		if (buf[i] != '|' && buf[i] != '\n' && buf[i] != '\0'
				&& buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\v')
			return (NULL);
		i++;
	}
	tab[j]++;
	return (tab);
}

int		fill_tab_std(char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * 10);
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t')
			return (0);
		while (buf[i] <= 57 && buf[i] >= 48)
			tmp[j++] = buf[i++];
		if ((buf[i] < 48 || buf[i] > 57)
				&& buf[i] != '\n' && buf[i] != '\t' && buf[i] != ' ')
			return (0);
		if (i != 0)
			return (ft_complete(buf, i, tmp));
		i++;
	}
	return (ft_atoi(tmp));
}

int		*fill_other_tab(char *buf, int fd, int n)
{
	int		i;
	int		j;
	int		*str;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * 200);
	str = (int *)malloc(sizeof(int) * 8000000);
	while (buf[i])
	{
		j = 0;
		if ((buf[i] > 57 || buf[i] < 48) && buf[i] != '\n'
				&& buf[i] != ' ' && buf[i] != '\t')
			return (NULL);
		while (buf[i] >= 48 && buf[i] <= 57)
			tmp[j++] = buf[i++];
		str[n++] = ft_atoi(tmp);
		if (ft_atoi(tmp) == 0)
			return (NULL);
		tmp = ft_memset(tmp, 0, 200);
		i++;
	}
	return (str);
}

void	ft_print_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putnbr(tab[i++]);
}

int		ft_count_rows(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
