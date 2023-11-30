/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:42:45 by efaustin          #+#    #+#             */
/*   Updated: 2023/11/28 08:42:46 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*haystack;
	char	*needle;

	if (*to_find == '\0')
		return (str);
	haystack = str;
	needle = to_find;
	while (true)
	{
		if (*needle == '\0')
			return ((char *)(haystack - (needle - to_find)));
		if (*haystack == *needle)
			needle++;
		else
			needle = to_find;
		if (*haystack == '\0')
			break ;
		haystack++;
	}
	return (0);
}
