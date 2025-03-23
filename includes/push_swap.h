/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:10 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/23 16:56:31 by zeroql           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// error and parsing functions
int		check_arg(char *arg);
int		ft_error(void);
void	parse_string(char *str);
int		check_dup(t_stack *stk);
void	ft_free(t_stack *stack);

	// linked list functions
t_stack *new_stack_node(int num, int index);
void	stack_add_back(t_stack **head, t_stack *node);
t_stack	*stack_last(t_stack *head);
void	print_stack(t_stack *head, int rev);
int	stack_size(t_stack *head);

// stack functions
t_stack	*init_str(char *argv);
t_stack	*init_stack(int argc, char **argv);
t_stack	*stack_min(t_stack *head);
t_stack	*stack_max(t_stack *head);

// algo functions
int stack_sorted(t_stack *stk);
void	sort_three(t_stack **, int only);

//stack operations
void	swap_a(t_stack **stk, int only);
void	rotate_a(t_stack **a, int only);
void	reverse_rotate_a(t_stack **a, int only);

#endif
