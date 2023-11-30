/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:23:05 by efaustin          #+#    #+#             */
/*   Updated: 2023/11/27 06:23:08 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!((curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z')))
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}
