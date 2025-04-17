/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:32 by mtangalv          #+#    #+#             */
/*   Updated: 2025/04/15 16:37:44 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack_node(int num, int index)
{
	t_stack	*s_node;

	s_node = malloc(sizeof(t_stack));
	if (!s_node)
		return (0);
	s_node->num = num;
	s_node->index = index;
	s_node->next = NULL;
	s_node->prev = NULL;
	s_node->above_median = 0;
	s_node->target = NULL;
	s_node->push_cost = INT_MAX;
	s_node->cheapest = 0;
	return (s_node);
}

void	stack_add_back(t_stack **head, t_stack *node)
{
	if (!head)
		return ;
	if (*head == NULL)
		*head = node;
	else
	{
		node->prev = stack_last(*head);
		stack_last(*head)->next = node;
	}
}

t_stack	*stack_last(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	stack_size(t_stack *head)
{
	int	num;

	if (head == NULL)
		return (0);
	num = 0;
	while (head)
	{
		head = head->next;
		num++;
	}
	return (num);
}
