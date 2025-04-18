/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushnswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:44:28 by fepennar          #+#    #+#             */
/*   Updated: 2025/03/25 17:44:46 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **src, t_stack **dst, int sign)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	if (sign == 0)
		write(1, "pa\n", 3);
	if (sign == 1)
		write(1, "pb\n", 3);
}

void	ft_swap(t_stack **stack, int sign)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (sign == 0)
		write(1, "sa\n", 3);
	if (sign == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 2);
	ft_swap(b, 2);
	write (1, "ss\n", 3);
}
