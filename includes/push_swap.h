/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:10 by mtangalv          #+#    #+#             */
/*   Updated: 2025/03/20 16:38:26 by mtangalv         ###   ########.fr       */
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

int		check_arg(char *arg);
int		ft_error(void);
void	parse_string(char *str);
int		check_dup(t_stack *stk);

	// linked list functions
	t_stack *new_stack_node(int num, int index);
void	stack_add_back(t_stack **head, t_stack *node);
t_stack	*stack_last(t_stack *head);
void	print_stack(t_stack *head, int rev);
#endif
