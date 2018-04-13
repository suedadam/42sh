/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 01:39:40 by satkins           #+#    #+#             */
/*   Updated: 2018/04/13 13:46:05 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int	is_quoted(uint8_t *quoted, char c, char **command)
{
	if (*quoted & BACKSLASH)
	{
		if (!IS_ESCAPED(c))
			if (!(*command = strappend(command, '\\')))
				return (EXIT_FAILURE);
		*quoted &= ~BACKSLASH;
	}
	else if (IS_QUOTE(c))
		*quoted ^= quoted_flags(c);
	return (EXIT_SUCCESS);
}

static char	*litreal_command(char **input_str)
{
	int		i;
	int		embedded_open_paren;
	char	*command;

	embedded_open_paren = 0;
	command = NULL;
	i = 2;
	while ((*input_str)[i])
	{
		if ((*input_str)[i] == ')')
		{
			if (embedded_open_paren == 0)
			{
				*input_str = *input_str + i + 1;
				return (command);
			}
			else
				embedded_open_paren--;
		}
		else if ((*input_str)[i] == '(')
			embedded_open_paren++;
		if (!(command = strappend(&command, (*input_str)[i])))
			return (NULL);
		i++;
	}
	free(command);
	return (MAP_FAILED);
}

static int	close_chck(uint8_t quoted, char c, char **command, int paren)
{
	if (!(quoted & BACKSLASH) && c == BACKT)
	{
		if (quoted || paren)
		{
			free(*command);
			*command = NULL;
			return (EXIT_FAILURE_SOFT);
		}
		return (EXIT_SUCCESS);
	}
	return (UNUSED_CHAR);
}

int	check_paren(char c)
{
	if (c == '(')
		return (1);
	else if (c == ')')
		return (-1);
	else
		return (0);
}

static char	*bquote_command(char **input_str)
{
	int		i;
	char	*command;
	int		paren;
	uint8_t	quoted;

	quoted = 0;
	paren = 0;
	command = NULL;
	i = 1;
	while ((*input_str)[i])
	{
		if (close_chck(quoted, (*input_str)[i], &command, paren) != UNUSED_CHAR)
		{
			*input_str = *input_str + i + 1;
			return (command == NULL ? MAP_FAILED : command);
		}
		if (is_quoted(&quoted, (*input_str)[i], &command) == EXIT_FAILURE)
			return (NULL);
		if (!(quoted & BACKSLASH) &&
			!(command = strappend(&command, (*input_str)[i])))
			return (NULL);
		paren += check_paren((*input_str)[i]);
		i++;
	}
	free(command);
	return (MAP_FAILED);
}

static char	*create_subs_command(char **input_str, char close_char)
{
	if (close_char == ')')
		return (litreal_command(input_str));
	else if (close_char == BACKT)
		return (bquote_command(input_str));
	return (MAP_FAILED);
}

int		is_command_sub(t_parser *par, char **input_str)
{
	char	close_char;
	char	*command;

	if ((par->quoted & ~DOUBLE_QUOTE) || !(**input_str == '$' || **input_str == BACKT))
		return (UNUSED_CHAR);
	if (**input_str == '$' && (*input_str)[1] != '(')
		return (EXIT_FAILURE_SOFT);
	close_char = **input_str == '$' ? ')' : BACKT;
	if (!ft_strchr(&((*input_str)[1]), close_char))
		return (EXIT_FAILURE_SOFT);
	if (!(command = create_subs_command(input_str, close_char)) ||
		command == MAP_FAILED)
		return (command == NULL ? 0 : -1);
	ft_printf("this is the subshell command:\n%s\n", command);
	//Send to manager with subshell flag

	return (CONTINUE);
}