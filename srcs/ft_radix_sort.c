/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:34:08 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/09 13:34:10 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_bits(t_stack *a)
{
	int	maxi;
	int	bits;

	maxi = max(a);
	bits = 0;
	while ((maxi >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_sort(t_stack **a)
{
	t_stack	*b;
	int		i;
	int		size;
	int		bit;
	int		num;

	b = NULL;
	size = ft_stacksize(*a);
	bit = 0;
	while (bit < max_bits(*a))
	{
		i = 0;
		while (i < size)
		{
			num = (*a)->nbr;
			if (((num >> bit) & 1) == 0)
				ft_push(a, &b, 1);
			else
				ft_rotate(a, 0);
			i++;
		}
		while (b)
			ft_push(&b, a, 0);
		bit++;
	}
}
