/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:43:04 by efaustin          #+#    #+#             */
/*   Updated: 2023/11/28 08:43:05 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_str_length_fast(char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dst;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaing;

	dst = dest;
	src_start = src;
	remaing = size;
	while (remaing-- != 0 && *dst != '\0')
		dst++;
	dst_length = dst - dest;
	remaing = size - dst_length;
	if (remaing == 0)
		return (dst_length + ft_str_length_fast(src));
	while (*src != '\0')
	{
		if (remaing > 1)
		{
			*dst++ = *src;
			remaing--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + (src - src_start));
}
