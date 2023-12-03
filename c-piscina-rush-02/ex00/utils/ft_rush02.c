/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:23:43 by efaustin          #+#    #+#             */
/*   Updated: 2023/12/03 02:23:44 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_getnb(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!(str))
		exit(1);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*ft_getval(int fd, char *c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!(str))
		exit(1);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*process_value(int fd, char *c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_getval(fd, c);
	while (tmp[i])
	{
		while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
			i++;
		if (tmp[i] && j > 0)
			tmp[j++] = ' ';
		while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\t')
			tmp[j++] = tmp[i++];
	}
	tmp[j] = '\0';
	return (ft_strdup(tmp));
}

t_list	*process_line(int fd)
{
	t_list	*entry;
	char	c[1];

	entry = malloc(sizeof(t_list));
	if (!entry)
		exit(1);
	entry->nb = ft_atoi(ft_getnb(fd));
	read(fd, c, 1);
	while (read(fd, c, 1) && (c[0] == ' ' || c[0] == '\t' || c[0] == ':'))
		;
	entry->val = process_value(fd, c);
	return (entry);
}

t_list	*process(char *file)
{
	int		i;
	int		fd;
	t_list	*tab;

	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(t_list) * 33);
	if (fd == -1 || !tab)
		exit(1);
	i = 0;
	while (i < 32)
	{
		tab[i] = *process_line(fd);
		i++;
	}
	close(fd);
	return (tab);
}
