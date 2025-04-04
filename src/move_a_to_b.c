/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:39:21 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/03 23:22:10 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_cheapest(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->cheapest)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median == 1 && cheapest_node->target->above_median == 1)
		rr_stack(a, b, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target->above_median == 0)
		rrr_stack(a, b, cheapest_node);
	check_top_stack(a, cheapest_node, 'a');
	check_top_stack(b, cheapest_node->target, 'b');
	push_b(b, a, 1);
}