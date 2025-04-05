/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:02:11 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:13:44 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_stack(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rotate_both(a, b, 1);
	set_index_median(*a);
	set_index_median(*b);
}

void	rrr_stack(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		reverse_rotate_both(a, b, 1);
	set_index_median(*a);
	set_index_median(*b);
}

void	check_top_stack(t_stack	**stk, t_stack *node, char a_b)
{
	while (*stk != node)
	{
		if (a_b == 'a')
		{
			if ((node)->above_median == 1)
				rotate_a(stk, 1);
			else
				reverse_rotate_a(stk, 1);
		}
		else if (a_b == 'b')
		{
			if (node->above_median == 1)
				rotate_b(stk, 1);
			else
				reverse_rotate_b(stk, 1);
		}
	}
}
