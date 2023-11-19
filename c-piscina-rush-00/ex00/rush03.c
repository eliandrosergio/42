/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:28:12 by efaustin          #+#    #+#             */
/*   Updated: 2023/11/18 17:30:18 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line3(int x, int a, int b, int c)
{
	int	i;

	i = 0;
	if (x >= 1)
		ft_putchar(a);
	while (i <= (x - 3))
	{
		ft_putchar(b);
		i++;
	}
	if (x >= 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y >= 1 && x >= 1)
		ft_line3(x, 'A', 'B', 'C');
	while (i < y - 2 && x >= 1)
	{
		ft_line3(x, 'B', ' ', 'B');
		i++;
	}
	if (y >= 2 && x >= 1)
	{
		ft_line3(x, 'A', 'B', 'C');
	}
}
