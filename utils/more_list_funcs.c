/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:43:25 by zeroql            #+#    #+#             */
/*   Updated: 2025/04/05 20:18:07 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_max(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return (head);
	current = head;
	while (head->next != NULL)
	{
		if (head->num > current->num)
			current = head;
		head = head->next;
	}
	if (head->num > current->num)
		current = head;
	return (current);
}

t_stack	*stack_min(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return (head);
	current = head;
	while (head->next != NULL)
	{
		if (head->num < current->num)
			current = head;
		head = head->next;
	}
	if (head->num < current->num)
		current = head;
	return (current);
}
