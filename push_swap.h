/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:40:37 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/17 20:17:07 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

t_stack	*init_stack(int argc, char **argv);
t_stack	*ft_parsetwoargs(char *argv1);
void	addtobackstack(t_stack **stack, t_stack *node);
t_stack	*create_node(int data);
int		ft_atoi_new(const char *nptr, t_stack *stack);
int		ft_atoi_new_2(char *nptr, t_stack **stack_a, char ***arrayofarrays);
int		sign_check(char c);
// void	display_list(t_stack *stack);
// void 	display_array(char **arrayofarrays);
void	ft_free(t_stack **stack);
void	ft_free_arrays(char **arrayofarrays);
void	ft_error(void);
int		check_digits(char *argv1);
int		ft_checkdups(t_stack *stack_a);
int		checksorted(t_stack *stack_a);
int		count_numbers(t_stack *stack_a);
void	sort_stack(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack	**stack_a, t_stack **stack_b);
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_index(t_stack *stack, int nbr);
void	sort_three(t_stack **stack_a);
void	sort_bigstack(t_stack **stack_a, t_stack **stack_b);
void	sortthru_atob(t_stack **stack_a, t_stack **stack_b);
void	sortthru_btoa(t_stack **stack_a, t_stack **stack_b);
int		calcul_opt(t_stack **stack_a, t_stack **stack_b);
int		calcul_opt_toa(t_stack **stack_a, t_stack **stack_b);
int		case_ra_rb(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_rra_rb(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_ra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_rra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_ra_rb_toa(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_rra_rb_toa(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_ra_rrb_toa(t_stack **stack_a, t_stack **stack_b, int nbr);
int		case_rra_rrb_toa(t_stack **stack_a, t_stack **stack_b, int nbr);
int		findplace_b(t_stack *stack_b, int nbr);
int		findplace_a(t_stack *stack_a, int nbr);
int		apply_ra_rb(t_stack **stack_a, t_stack **stack_b, int nbr, char c);
int		apply_ra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr, char c);
int		apply_rra_rb(t_stack **stack_a, t_stack **stack_b, int nbr, char c);
int		apply_rra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr, char c);
void	setrightindex(t_stack **stack_a);

#endif