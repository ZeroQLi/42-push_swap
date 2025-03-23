/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:22:22 by zeroql            #+#    #+#             */
/*   Updated: 2025/03/23 17:06:43 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, int only)
{
	t_stack	*largest_node;

	largest_node = stack_max(*a);
	if ((stack_last(*a))->num == largest_node->num)
	{
		if (!stack_sorted(*a))
			swap_a(a, only);
	}
	if ((*a)->num == largest_node->num)
	{
		rotate_a(a, only);
		if ((stack_last(*a))->num == largest_node->num)
		{
			if (!stack_sorted(*a))
				swap_a(a, only);
		}
	}
	if ((*a)->next->num == largest_node->num)
	{
		reverse_rotate_a(a, only);
		if (!stack_sorted(*a))
			swap_a(a, only);
	}
}
