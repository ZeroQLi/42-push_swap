/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:00:44 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:24:34 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **a, t_stack **b)
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

void	push_a(t_stack **a, t_stack **b, int only)
{
	push(a, b);
	if (only == 1)
		ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b, int only)
{
	push(b, a);
	if (only == 1)
		ft_printf("pb\n");
}

void	rotate_both(t_stack **a, t_stack **b, int only)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	if (only == 1)
		ft_printf("rr\n");
}

void	reverse_rotate_both(t_stack **a, t_stack **b, int only)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	if (only == 1)
		ft_printf("rrr\n");
}
