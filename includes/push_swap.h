/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:10 by mtangalv          #+#    #+#             */
/*   Updated: 2025/04/15 16:38:10 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				above_median;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
	int				push_cost;
	int				cheapest;
}	t_stack;

// error and parsing functions
int		check_arg(char *arg);
int		ft_error(void);
int		ft_error_stack(t_stack **stk);
int		ft_error_string(char **arr);
void	parse_string(char *str);
int		check_dup(t_stack **stk);
void	ft_free(t_stack **stack);

// linked list functions
t_stack	*new_stack_node(int num, int index);
void	stack_add_back(t_stack **head, t_stack *node);
t_stack	*stack_last(t_stack *head);
int		stack_size(t_stack *head);

// stack functions
t_stack	*init_str(char *argv);
t_stack	*init_stack(int argc, char **argv);
t_stack	*stack_min(t_stack *head);
t_stack	*stack_max(t_stack *head);

// stack operations
void	swap_a(t_stack **stk, int only);
void	swap_b(t_stack **b, int only);
void	rotate_a(t_stack **a, int only);
void	reverse_rotate_a(t_stack **a, int only);
void	rotate_b(t_stack **b, int only);
void	reverse_rotate_b(t_stack **b, int only);
void	rotate_both(t_stack **a, t_stack **b, int only);
void	reverse_rotate_both(t_stack **a, t_stack **b, int only);
void	push_a(t_stack **a, t_stack **b, int only);
void	push_b(t_stack **a, t_stack **b, int only);

// algo functions
int		stack_sorted(t_stack *stk);
void	sort_three(t_stack **a, int only);
void	sort_big(t_stack **a, t_stack **b);
void	init_a_to_b(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	init_b_to_a(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack **a, t_stack **b);

void	set_index_median(t_stack *stk);
t_stack	*get_cheapest(t_stack *a);
void	rr_stack(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rrr_stack(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	check_top_stack(t_stack **head, t_stack *node, char a_b);
#endif
