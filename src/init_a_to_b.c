/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:14 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/04 23:00:44 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index_median(t_stack *stk)
{
	int	i;
	int median;

	i = 0;
	if (!stk)
		return ;
	median = stack_size(stk) / 2;
	while (stk)
	{
		stk->index = i;
		if (i <= median)
			stk->above_median = 1;
		else
			stk->above_median = 0;
		stk = stk->next;
		++i;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_a;
	long	closest_num;

	while(a)
	{
		closest_num = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > closest_num)
			{
				closest_num = current_b->num;
				target_a = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_num == LONG_MIN)
			a->target = stack_max(b);
		else
			a->target = target_a;
		a = a->next;
	}
}

static void cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == 0)
			a->push_cost = len_a - (a->index);
		if (a->target->above_median == 1)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}
static void	find_cheapest(t_stack *stk)
{
	long cheapest_val;
	t_stack *cheapest_node;

	if (!stk)
		return ;
	cheapest_val = LONG_MAX;
	while (stk)
	{
		if (stk->push_cost < cheapest_val)
		{
			cheapest_val = stk->push_cost;
			cheapest_node = stk;
		}
		stk = stk->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_a_to_b(t_stack *a, t_stack *b)
{
	set_index_median(a);
	set_index_median(b);
	target_a(a, b);
	cost_a(a, b);
	find_cheapest(a);
}