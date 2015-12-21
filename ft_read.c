/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:47:00 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/21 17:53:07 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		*ft_read(int fd)
{
	int		*tab;
	int		i;
	char	buf[8000000];

	i = 0;
	read(fd, buf, 8000000);
	while (buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\v')
		i++;
	if (buf[i] == '|')
		tab = fill_tab(buf, fd);
	else if (buf[i] >= 48 && buf[i] <= 57)
		tab = fill_other_tab(buf, fd, 0);
	close(fd);
	return (tab);
}

int		*ft_read_standard(int fd, int n, int ret)
{
	char	buf[8000000];
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * 200);
	i = 0;
	while ((ret = read(0, buf, 10000)) > 1)
	{
		buf[ret] = '\0';
		while (buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t'
				|| buf[i] == '\v')
			i++;
		if (buf[i] == '|')
			tab[n++] = fill_tab_std_pipe(buf);
		else if (buf[i] >= 48 && buf[i] <= 57)
			tab[n++] = fill_tab_std(buf);
		else
			return (NULL);
		if (n != 0)
			if (tab[n - 1] == 0)
				return (NULL);
	}
	if (n == 0)
		return (NULL);
	return (tab);
}

int		ft_file(char *argv, int fd, int n)
{
	fd = open(argv, O_RDONLY);
	if (ft_read(fd) == NULL)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_print_pipe(ft_read(fd));
	n = ft_play(ft_read(fd));
	if (n == 1)
		ft_putstr("AI wins.");
	else
		ft_putstr("Human wins.");
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	int n;
	int *tab;

	if (argc == 2)
	{
		ft_file(argv[1], fd, n);
		return (0);
	}
	else
	{
		tab = ft_read_standard(0, 0, 0);
		if (tab == NULL)
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		ft_print_pipe(tab);
		n = ft_play(tab);
		if (n == 1)
			ft_putstr("AI wins.");
		else
			ft_putstr("Human wins.");
	}
	return (0);
}
