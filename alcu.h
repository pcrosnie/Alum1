/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:47:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/21 17:55:25 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "libft.h"
# include <fcntl.h>

int		ft_human_play(int tab);
int		ft_play(int *tab);
void	ft_print_pipe(int *tab);
int		*fill_tab(char *buf, int fd);
int		fill_tab_std(char *buf);
int		*fill_other_tab(char *buf, int fd, int n);
void	ft_print_tab(int *tab);
int		ft_count_rows(int *tab);
int		ft_little_check(char *str, int n);
int		ft_complete(char *buf, int i, char *tmp);
int		fill_tab_std_pipe(char *buf);
int		ft_human_retry(int n, int nb, char *str);

#endif
