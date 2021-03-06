/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:47:39 by bleaf             #+#    #+#             */
/*   Updated: 2022/03/27 22:01:28 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	algo_sorting(t_list **a, t_list **b, t_list *best)
{
	t_list	*pos;
	int		a_top;
	int		b_top;
	int		a_bottom;
	int		b_bottom;

	best = find_best(a, b);
	pos = find_pos(a, best->content);
	a_top = get_pos_top(a, pos->content);
	a_bottom = get_pos_bottom(a, pos->content);
	b_top = get_pos_top(b, best->content);
	b_bottom = get_pos_bottom(b, best->content);
	if (way_size(a, b, best->content) == max(a_top, b_top))
		both_top(a_top, b_top, a, b);
	else if (way_size(a, b, best->content) == max(a_bottom, b_bottom))
		both_bottom(a_bottom, b_bottom, a, b);
	else if (way_size(a, b, best->content) == (a_top + b_bottom))
		at_bb(a_top, b_bottom, a, b);
	else if (way_size(a, b, best->content) == (a_bottom + b_top))
		ab_bt(a_bottom, b_top, a, b);
}
