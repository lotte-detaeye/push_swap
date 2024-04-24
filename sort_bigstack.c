/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:59:16 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/24 16:28:15 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
- push first two elements to b
- after that: push everything gradually to b, in the most efficient way
using calculations of the number of operations
- until there are three elements left in a, or if it turns out a is sorted
- sort three elements in a
- push everything back to a
- make sure the index to the head is set right
*/
void	sort_bigstack(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	if (!checksorted(*stack_a) && stack_len(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (!checksorted(*stack_a) && stack_len(*stack_a) > 3)
		sortthru_atob(stack_a, stack_b);
	if (!checksorted(*stack_a))
		sort_three(stack_a);
	sortthru_btoa(stack_a, stack_b);
	setrightindex(stack_a);
}

//This function pushes all the elements from a to b until there are
//only 3 elements left in a or a is sorted. For each action, it calculates 
//the lowest possible amount of necessary operations and then pushes the first 
//element in the stack it encounters to which that low number of operations
//applies to
void	sortthru_atob(t_stack **stack_a, t_stack **stack_b)
{
	int		opt_opnum;
	t_stack	*temp;

	while (!checksorted(*stack_a) && stack_len(*stack_a) > 3)
	{
		opt_opnum = calcul_opt(stack_a, stack_b);
		temp = *stack_a;
		while (opt_opnum >= 0)
		{
			if (opt_opnum == (case_ra_rb(stack_a, stack_b, temp->nbr)))
				opt_opnum = apply_ra_rb(stack_a, stack_b, temp->nbr, 'a');
			else if (opt_opnum == (case_rra_rb(stack_a, stack_b, temp->nbr)))
				opt_opnum = apply_rra_rb(stack_a, stack_b, temp->nbr, 'a');
			else if (opt_opnum == (case_ra_rrb(stack_a, stack_b, temp->nbr)))
				opt_opnum = apply_ra_rrb(stack_a, stack_b, temp->nbr, 'a');
			else if (opt_opnum == (case_rra_rrb(stack_a, stack_b, temp->nbr)))
				opt_opnum = apply_rra_rrb(stack_a, stack_b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

//This function pushes all the elements from b to a until there are
//no elements left in b. For each action, it calculates 
//the lowest possible amount of necessary operations and then pushes the first 
//element in the stack it encounters to which that low number of operations
//applies to
void	sortthru_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int		opt_opn;
	t_stack	*tmp;

	while (*stack_b)
	{
		opt_opn = calcul_opt_toa(stack_a, stack_b);
		tmp = *stack_b;
		while (opt_opn >= 0)
		{
			if (opt_opn == (case_ra_rb_toa(stack_a, stack_b, tmp->nbr)))
				opt_opn = apply_ra_rb(stack_a, stack_b, tmp->nbr, 'b');
			else if (opt_opn == (case_rra_rb_toa(stack_a, stack_b, tmp->nbr)))
				opt_opn = apply_rra_rb(stack_a, stack_b, tmp->nbr, 'b');
			else if (opt_opn == (case_ra_rrb_toa(stack_a, stack_b, tmp->nbr)))
				opt_opn = apply_ra_rrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (opt_opn == (case_rra_rrb_toa(stack_a, stack_b, tmp->nbr)))
				opt_opn = apply_rra_rrb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
}

//This function calculates the optimal number of operations, by looping through
//stack_a, trying them all and setting the return int value to the lowest 
//possible amount 
int	calcul_opt(t_stack **stack_a, t_stack **stack_b)
{
	int		opt_opnum;
	t_stack	*temp;

	temp = *stack_a;
	opt_opnum = case_ra_rb(stack_a, stack_b, (*stack_a)->nbr);
	while (temp)
	{
		if (opt_opnum > case_rra_rb(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_rra_rb(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_rra_rrb(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_rra_rrb(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_ra_rrb(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_ra_rrb(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_ra_rb(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_ra_rb(stack_a, stack_b, temp->nbr);
		temp = temp->next;
	}
	return (opt_opnum);
}

int	calcul_opt_toa(t_stack **stack_a, t_stack **stack_b)
{
	int		opt_opnum;
	t_stack	*temp;

	temp = *stack_b;
	opt_opnum = case_ra_rb_toa(stack_a, stack_b, (*stack_b)->nbr);
	while (temp)
	{
		if (opt_opnum > case_rra_rb_toa(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_rra_rb_toa(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_rra_rrb_toa(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_rra_rrb_toa(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_ra_rrb_toa(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_ra_rrb_toa(stack_a, stack_b, temp->nbr);
		if (opt_opnum > case_ra_rb_toa(stack_a, stack_b, temp->nbr)) 
			opt_opnum = case_ra_rb_toa(stack_a, stack_b, temp->nbr);
		temp = temp->next;
	}
	return (opt_opnum);
}
