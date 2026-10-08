/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:34:56 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/29 15:20:00 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * Marks a cell as visited and pushes it on the fill stack.
 *
 * @param map Working copy of the grid.
 * @param stack Stack of cells still to expand.
 * @param x Row of the cell.
 * @param y Column of the cell.
 * @return 0 if the cell opens the map, 1 if it is a wall, already visited or
 * pushed, -1 on allocation failure.
 */
static int	visit(char **map, t_list **stack, int x, int y)
{
	t_point	*pt;
	t_list	*node;

	if (x < 0 || y < 0 || !map[x] || (size_t)y >= ft_strlen(map[x])
		|| map[x][y] == ' ' || !map[x][y])
		return (0);
	if (map[x][y] == '1' || map[x][y] == 'V')
		return (1);
	map[x][y] = 'V';
	pt = get_point(x, y);
	if (!pt)
		return (-1);
	node = ft_lstnew(pt);
	if (!node)
		return (free(pt), -1);
	ft_lstadd_front(stack, node);
	return (1);
}

/**
 * Visits the four neighbors of a cell, stopping at the first failure.
 *
 * @param map Working copy of the grid.
 * @param stack Stack of cells still to expand.
 * @param pt Cell to expand.
 * @return 1 if every neighbor is fine, 0 if the map is open, -1 on error.
 */
static int	expand(char **map, t_list **stack, t_point *pt)
{
	int	res;

	res = visit(map, stack, pt->x + 1, pt->y);
	if (res > 0)
		res = visit(map, stack, pt->x - 1, pt->y);
	if (res > 0)
		res = visit(map, stack, pt->x, pt->y + 1);
	if (res > 0)
		res = visit(map, stack, pt->x, pt->y - 1);
	return (res);
}

/**
 * Iterative flood fill checking that a region is closed by walls.
 *
 * Visited cells are marked 'V'. Reaching a space, an empty cell or the grid
 * border means the map is open. An explicit heap stack is used instead of
 * recursion so that very large maps cannot overflow the call stack.
 *
 * @param map Working copy of the grid.
 * @param pos Starting position (freed by the function).
 * @return 1 if closed, 0 if open, -1 on allocation failure.
 */
int	flood_fill(char **map, t_point *pos)
{
	t_list	*stack;
	t_list	*node;
	int		res;

	if (!pos)
		return (-1);
	stack = NULL;
	res = visit(map, &stack, pos->x, pos->y);
	free(pos);
	while (stack && res > 0)
	{
		node = stack;
		stack = stack->next;
		res = expand(map, &stack, node->content);
		free(node->content);
		free(node);
	}
	return (ft_lstclear(&stack, free), res);
}
