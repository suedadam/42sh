/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:35:42 by satkins           #+#    #+#             */
/*   Updated: 2018/04/18 20:18:12 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

extern char **environ;

int		check_paren(char c)
{
	if (c == '(')
		return (1);
	else if (c == ')')
		return (-1);
	else
		return (0);
}

char	*literal_command(char **input_str, int i)
{
	int		embedded_open_paren;
	char	*command;

	embedded_open_paren = 0;
	if (!(command = ft_memalloc(sizeof(char))))
		return (NULL);
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
		if (!(command = strappend(&command, (*input_str)[i++])))
			return (NULL);
	}
	meta_free(command);
	return (MAP_FAILED);
}

int		is_subshell(t_parser *par, char **input_str)
{
	char	*command;
	int		ret;

	if (par->quoted || **input_str != '(')
		return (UNUSED_CHAR);
	if (!ft_strchr(&((*input_str)[1]), ')'))
		return (EXIT_FAILURE_SOFT);
	command = literal_command(input_str, SUBSHELL_OFFSET);
	if (command == MAP_FAILED)
		return (EXIT_FAILURE_SOFT);
	else if (command == NULL)
		return (0);
	ret = manager(command, SUBSHELL_ENV);
	environ = g_environ->environ;
	meta_free(command);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (ret == EXIT_FAILURE_SOFT ? -1 : CONTINUE);
}
