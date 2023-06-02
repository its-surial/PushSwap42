/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:31:07 by lgollong          #+#    #+#             */
/*   Updated: 2023/06/02 20:02:30 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	more_operations(t_values **stack_a, t_values **stack_b, char *op)
{
	if (!ft_strcmp("rb\n", op))
		rotate_it(stack_b);
	else if (!ft_strcmp("rr\n", op))
	{
		rotate_it(stack_a);
		rotate_it(stack_b);
	}
	else if (!ft_strcmp("rra\n", op))
		reverse_rotate_it(stack_a);
	else if (!ft_strcmp("rrb\n", op))
		reverse_rotate_it(stack_b);
	else if (!ft_strcmp("rrr\n", op))
	{
		reverse_rotate_it(stack_a);
		reverse_rotate_it(stack_b);
	}
	else
		error();
}

void	check_operations(t_values **stack_a, t_values **stack_b, char *op)
{
	if (!ft_strcmp("sa\n", op))
		swap_it(stack_a);
	else if (!ft_strcmp("sb\n", op))
		swap_it(stack_b);
	else if (!ft_strcmp("ss\n", op))
	{
		swap_it(stack_a);
		swap_it(stack_b);
	}
	else if (!ft_strcmp("pa\n", op))
		push_it(stack_b, stack_a);
	else if (!ft_strcmp("pb\n", op))
		push_it(stack_a, stack_b);
	else if (!ft_strcmp("ra\n", op))
		rotate_it(stack_a);
	else
		more_operations(stack_a, stack_b, op);
}

void	get_operation(t_values *stack_a, t_values *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		check_operations(&stack_a, &stack_b, op);
		free(op);
		op = get_next_line(0);
	}
	if (stack_a && !stack_b && sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_values	*stack_a;
	t_values	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	get_data(&stack_a, argc, argv);
	set_index(stack_a);
	get_operation(stack_a, stack_b);
	clear_data(&stack_a, &stack_b);
	return (0);
}
