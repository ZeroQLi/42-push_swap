/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:40:32 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/22 14:55:57 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//create new node
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
	return (s_node);
}
//add a node to the end of a list
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

	num = 1;
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		num++;
		head = head->next;
	}
	return (num);
}

void print_stack(t_stack *head, int	rev)
{
	if (rev == 1)
	{
		head = stack_last(head);
		while (head->prev != NULL)
		{
			ft_printf("%i: %i\n", head->index, head->num);
			head = head->prev;
		}
		ft_printf("%i: %i\n", head->index, head->num);
	}
	else
	{
		while (head->next != NULL)
		{
			ft_printf("%i: %i\n", head->index, head->num);
			head = head->next;
		}
		ft_printf("%i: %i\n", head->index, head->num);
	}
}
