/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotnrevrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:44:28 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/10 15:42:51 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack **stack, int sign)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	if (sign == 0)
		write(1, "ra\n", 3);
	if (sign == 1)
		write(1, "rb\n", 3);
}

void	ft_revrotate(t_stack **stack, int sign)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (sign == 0)
		write(1, "rra\n", 4);
	if (sign == 1)
		write(1, "rrb\n", 4);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 2);
	ft_rotate(b, 2);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_revrotate(a, 2);
	ft_revrotate(b, 2);
	write(1, "rrr\n", 4);
}
