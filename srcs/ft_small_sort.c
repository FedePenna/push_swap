/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:23:17 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/16 16:23:18 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		pos;

	tmp = *a;
	min = tmp->nbr;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->nbr < min)
		{
			min = tmp->nbr;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	while (pos > 0 && pos <= i / 2 && pos--)
		ft_rotate(a, 0);
	while (pos++ < i && pos >= i / 2)
		ft_revrotate(a, 0);
	ft_push(a, b, 1);
}

void	ft_sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first > second && second < third && first < third)
		ft_swap(a, 0);
	else if (first > second && second > third)
	{
		ft_swap(a, 0);
		ft_revrotate(a, 0);
	}
	else if (first > second && second < third && first > third)
		ft_rotate(a, 0);
	else if (first < second && second > third && first < third)
	{
		ft_swap(a, 0);
		ft_rotate(a, 0);
	}
	else if (first < second && second > third && first > third)
		ft_revrotate(a, 0);
}

void	ft_small_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stacksize(*a) == 2)
		ft_swap(a, 0);
	else if (ft_stacksize(*a) == 3)
		ft_sort_three(a);
	else if (ft_stacksize(*a) == 4)
	{
		push_min_to_b(a, &b);
		ft_sort_three(a);
		ft_push(&b, a, 0);
	}
	else if (ft_stacksize(*a) == 5)
	{
		push_min_to_b(a, &b);
		push_min_to_b(a, &b);
		ft_sort_three(a);
		ft_push(&b, a, 0);
		ft_push(&b, a, 0);
	}
}
