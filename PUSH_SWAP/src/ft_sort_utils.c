/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:01:16 by bleaf             #+#    #+#             */
/*   Updated: 2022/03/28 15:50:36 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_list **stk)
{
	int		check;
	t_list	*lst;

	lst = *stk;
	if (!*stk)
		return (0);
	check = lst->content;
	while (lst)
	{
		if (check > lst->content)
			return (0);
		else
			check = lst->content;
		lst = lst->next;
	}
	return (1);
}

int	is_unq_stack(t_list	**lst)
{
	t_list	*il;
	t_list	*jl;

	il = *lst;
	while (il)
	{
		jl = il->next;
		while (jl)
		{
			if (il->content == jl->content)
				error(lst);
			jl = jl->next;
		}
		il = il->next;
	}
	return (1);
}

int	way_size(t_list **a, t_list **b, int elem)
{
	int		a_top;
	int		a_bottom;
	int		b_top;
	int		b_bottom;
	t_list	*pos;

	pos = find_pos(a, elem);
	a_top = get_pos_top(a, pos->content);
	a_bottom = get_pos_bottom(a, pos->content);
	b_top = get_pos_top(b, elem);
	b_bottom = get_pos_bottom(b, elem);
	return (min(min(max(b_bottom, a_bottom), max(a_top, b_top)),
			min(a_bottom + b_top, a_top + b_bottom)));
}

t_list	*find_best(t_list **a, t_list **b)
{
	t_list	*best;
	t_list	*iter;

	best = (*b);
	iter = (*b);
	while (iter)
	{
		if (way_size(a, b, best->content) > way_size(a, b, iter->content))
			best = iter;
		iter = iter->next;
	}
	return (best);
}

t_list	*find_min_elem(t_list **a)
{
	int		min;
	t_list	*mine;

	min = find_min(a);
	mine = *a;
	while (mine->content != min)
		mine = mine->next;
	return (mine);
}
