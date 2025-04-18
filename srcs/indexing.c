/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:49:14 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/16 11:49:17 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_index(t_stack *a, int *original, int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (a && i < size)
	{
		j = 0;
		while (j < size)
		{
			if (original[i] == sorted[j])
			{
				a->nbr = j;
				break ;
			}
			j++;
		}
		a = a->next;
		i++;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	index_assignation(t_stack *a)
{
	int		*arr;
	int		*copy;
	t_stack	*tmp;
	int		i;
	int		s_size;

	s_size = ft_stacksize(a);
	arr = malloc(sizeof(int) * s_size);
	copy = malloc(sizeof(int) * s_size);
	if (!arr || !copy)
		ft_error_message();
	tmp = a;
	i = 0;
	while (i < s_size)
	{
		arr[i] = tmp->nbr;
		copy[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(copy, s_size);
	create_index(a, arr, copy, s_size);
	free(arr);
	free(copy);
}
