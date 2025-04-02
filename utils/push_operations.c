/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:00:44 by zeroql            #+#    #+#             */
/*   Updated: 2025/03/29 17:36:52 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->prev = NULL;
	if (!*b)
	{
		*b = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *b;
		tmp->next->prev = tmp;
		*b = tmp;
	}
}
void push_a(t_stack **a, t_stack **b, int only)
{
	push(a, b);
	if (only == 1)
		ft_printf("pb\n");
}
void push_b(t_stack **a, t_stack **b, int only)
{
	push(b, a);
	if (only == 1)
		ft_printf("pb\n");
}