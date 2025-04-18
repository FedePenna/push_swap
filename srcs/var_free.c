/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:00:24 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/04 10:00:28 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack **a)
{
	t_stack	*setfree;

	if (!a)
		return ;
	while (*a)
	{
		setfree = (*a)->next;
		(*a)->nbr = 0;
		free(*a);
		*a = setfree;
	}
}
