/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 01:39:40 by satkins           #+#    #+#             */
/*   Updated: 2018/04/18 20:01:17 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

extern char **environ;

static char	*create_subs_command(char **input_str, char close_char)
{
	if (close_char == ')')
		return (literal_command(input_str, DOLLAR_OFFSET));
	else if (close_char == BACKT)
		return (bquote_command(input_str));
	return (MAP_FAILED);
}

static int	set_tokens(char **words, t_parser *p)
{
	while (*words)
	{
		p->current_type = WORD;
		if (!(p->current_token = sh_strcat(&(p->current_token), *words)) ||
			(words[1] &&
			add_token(p->current_token, &p->current_type, p) == EXIT_FAILURE))
			return (EXIT_FAILURE);
		meta_free(*words);
		words++;
	}
	return (EXIT_SUCCESS);
}

static int	split_into_tokens(t_parser *p, char *token_str)
{
	char	**words;

	if (!(words = ft_splitwhitespace(token_str)) ||
		(p->current_type != WORD &&
		add_token(p->current_token, &(p->current_type), p) == EXIT_FAILURE))
		return (EXIT_FAILURE);
	meta_free(token_str);
	if (set_tokens(words, p) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	meta_free(words);
	return (EXIT_SUCCESS);
}

static int	recurs_into_subshell(t_parser *par, char *command)
{
	char	*output;
	int		ret;

	output = NULL;
	ret = manager(command, &output);
	meta_free(command);
	if (ret == EXIT_FAILURE || ret == EXIT_FAILURE_SOFT)
		return (ret);
	if (!output || split_into_tokens(par, output) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			is_command_sub(t_parser *par, char **input_str)
{
	char	close_char;
	char	*command;
	int		ret;

	if ((par->quoted & ~DOUBLE_QUOTE) ||
		!(**input_str == '$' || **input_str == BACKT))
		return (UNUSED_CHAR);
	if (**input_str == '$' && (*input_str)[1] != '(')
		return (UNUSED_CHAR);
	close_char = **input_str == '$' ? ')' : BACKT;
	if (!ft_strchr(&((*input_str)[1]), close_char))
		return (EXIT_FAILURE_SOFT);
	if (!(command = create_subs_command(input_str, close_char)) ||
		command == MAP_FAILED)
		return (command == NULL ? 0 : -1);
	ret = recurs_into_subshell(par, command);
	environ = g_environ->environ;
	if (ret == EXIT_FAILURE)
		return (0);
	else if (ret == EXIT_SUCCESS)
		return (CONTINUE);
	return (ret);
}
