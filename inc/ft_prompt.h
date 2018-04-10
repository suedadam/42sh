/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:52:16 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 12:16:12 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include "ft_term.h"

# define NRM "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"

/*
**	backslash send
**	(backslash_char.c)
*/

int		backslash_char(void);

/*
**	Called when a '\' is at the end of a line buffer
**	(back_prompt.c)
*/

int		back_prompt(void);

/*
**	How a new prompt is created, calls to other required termcap and buffer
**	actions to ensure a clean start, prompt display can be defined
**	(new_prompt.c)
*/

int		new_prompt(char *prompt);

/*
**	Reset the prompt, also resets the cursor position, default prompt created
**	(reset_prompt.c)
*/

int		reset_prompt(void);

#endif
