/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:35:42 by satkins           #+#    #+#             */
/*   Updated: 2018/04/15 17:13:12 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int		check_paren(char c)
{
	if (c == '(')
		return (1);
	else if (c == ')')
		return (-1);
	else
		return (0);
}

char		*literal_command(char **input_str, int i)
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
		if (!(command = strappend(&command, (*input_str)[i]))) //possible optimization memcpy instead of char by char append
			return (NULL);
		i++;
	}
	meta_free(command);
	return (MAP_FAILED);
}

int		is_subshell(t_parser *par, char **input_str)
{
	char	*command;
	char	*unused;
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
	ret = manager(command, &unused);
	meta_free(command);
	if (ret == EXIT_FAILURE)
	{
		printf("Manager returned a fail :( \n");
		return (0);
	}
	return (ret == EXIT_FAILURE_SOFT ? -1 : CONTINUE);
}
