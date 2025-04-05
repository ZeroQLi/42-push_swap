/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:39:21 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:16:05 by zeroql           ###   ########.fr       */
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
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median == 1 && cheapest->target->above_median == 1)
		rr_stack(a, b, cheapest);
	else if (cheapest->above_median == 0 && cheapest->target->above_median == 0)
		rrr_stack(a, b, cheapest);
	check_top_stack(a, cheapest, 'a');
	check_top_stack(b, cheapest->target, 'b');
	push_b(b, a, 1);
}
