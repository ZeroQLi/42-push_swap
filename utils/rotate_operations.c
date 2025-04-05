/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:59:37 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:22:12 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **a, int only)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = stack_last(*a);
	tmp->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
	if (only == 1)
		ft_printf("ra\n");
}

void	reverse_rotate_a(t_stack **a, int only)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = stack_last(*a);
	tmp->prev->next = NULL;
	(*a)->prev = tmp;
	tmp->next = *a;
	tmp->prev = NULL;
	*a = tmp;
	if (only == 1)
		ft_printf("rra\n");
}

void	rotate_b(t_stack **b, int only)
{
	rotate_a(b, 0);
	if (only == 1)
		ft_printf("rb\n");
}

void	reverse_rotate_b(t_stack **b, int only)
{
	reverse_rotate_a(b, 0);
	if (only == 1)
		ft_printf("rrb\n");
}
