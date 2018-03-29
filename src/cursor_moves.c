/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 14:57:58 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	move_cursor(t_cursor *cursor)
{
	int		og_col;
	int		og_line;
	int		new_col;
	int		new_lin;

	og_col = cursor->og_position.y;
	og_line = cursor->og_position.x;

	new_lin = (og_line + cursor->curr_position.x) % g_shell_env->window.ws_row;
	new_col = og_col + cursor->curr_position.x +
		(og_line + cursor->curr_position.x >= g_shell_env->window.ws_row);
	tputs(tgoto(tgetstr("cm", NULL), new_lin - 1, new_col - 1), 0, &my_putchar);
}

int		cursor_to_right(t_cursor *cursor)
{
	if (g_shell_env->buffer->len_buffer == cursor->curr_pos.x)
	{
		cursor->curr_position.x++;
		move_cursor(cursor);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int		ft_curleft(t_terminf *anti)
{
	anti = (void *)anti;
	char *str;
	if (!(str = tgetstr("le", 0)))
		return (EXIT_FAILURE);

		tputs(str, 1, my_stupidput);
	// if (write(STDIN_FILENO, "\e[1D", 4) < 0)
		// return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_curhome(t_terminf *anti)
{
	char	*temp;

	anti = (void *)anti;
	temp = tgetstr("cr", 0);
	tputs(temp, 1, my_stupidput);
	return (EXIT_SUCCESS);
}

int		ft_curend(t_terminf *anti)
{
	ft_printf("implement me!");
	/*
	char	*temp;

	temp = tgetstr("", 0);
	tputs(temp, 1, my_stupidput);
	*/
	anti = (void *)anti;
	return (EXIT_SUCCESS);
}

int		ft_clearscreen(t_terminf *anti)
{
	char	*temp;

	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_stupidput);
	anti = (void *)anti;
	ft_printf("42sh%% ");
	return (EXIT_SUCCESS);
}

int		ft_backspace(t_terminf *anti)
{
	char	*temp;

	ft_curleft(anti);
	if (!(temp = tgetstr("dc", 0)))
		return (EXIT_FAILURE);
	tputs(temp, 1, my_stupidput);
	return (EXIT_SUCCESS);
}

// int		ft_delete(t_terminf *anti)
// {
// 	char	*temp;
//
// 	temp = tgetstr("dl", 0);
// 	tputs(temp, 1, my_stupidput);
// 	return (EXIT_SUCCESS);
// }


void	ft_clearline(int clr)
{
	char	*temp;

	clr = 0;
	temp = tgetstr("do", 0);
	tputs(temp, 1, my_stupidput);
	ft_printf("42sh%% ");
}

int		ft_passinput(t_terminf *anti)
{
	ft_clearline(0);
	anti = (void *)anti;
	return (EXIT_SUCCESS);
}
