/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:11:39 by satkins           #+#    #+#             */
/*   Updated: 2018/03/22 14:52:49 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static char			*strappend(char *str, char c)
{
	if (!(str = ft_realloc(str, ft_strlen(str) + 2)))
		return (NULL);
	str = ft_strncat(str, &c, 1);
	return (str);
}

static void			add_token(char *curr_token, t_token_type *curr_type,
	t_token_type *types, char **tokens)
{
	int				i;

	if (!curr_token || !curr_type)
		return ;
	i = -1;
	while (tokens[++i])
		;
	if (i > 0)
	{
		if (!(tokens = ft_realloc(tokens, sizeof(char *) * (i + 2)))
			|| !(types = ft_realloc(types, sizeof(t_token_type) * (i + 2))))
			return ;
	}
	else if (!(tokens = ft_memalloc(sizeof(char *) * 2))
		|| !(types = ft_memalloc(sizeof(t_token_type * 2))))
		return ;
	if (!(tokens[i] = ft_strdup(curr_token))
		|| !ft_memcpy(types[i], curr_type, sizeof(t_token_type)))
			return ;
	tokens[i + 1] = NULL;
	types[i + 1] = NULL;
	if (*curr_token != ';')
		ft_bzero(curr_token, ft_strlen(curr_token));
	ft_bzero(curr_type, sizeof(*t_token_type));

}

static uint8_t			quoted_flags(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	else if (c == '\"')
		return (DOUBLE_QUOTE);
	else if (c == '\\')
		return (BACKSLASH);
}

static void			handle_embedded_quotes(uint8_t *quoted,
	char **str, char **current_token)
{
	if (quoted & DOUBLE_QUOTE)
	{
		if (quoted & BACKSLASH)
		{
			if (!(**str == '\\' || **str == '\"'))
				*current_token = strappend(*current_token, '\\');
			*current_token = strappend(*current_token, **str);
		}
		if (**str == '\\' && (*(*str + 1)) == '\\' || *(*str + 1) == '\"')
			;
		else if (**str == '\"')
			quoted &= ~DOUBLE_QUOTE;
	}
	else if (quoted & )
}

void				parser(char *input_str)
{
	char			*current_token;
	char			**tokens;
	uint8_t			quoted;
	t_token_type	*types;
	t_token_type	*current_type;

	*tokens = NULL;
	current_token = NULL;
	types = NULL;
	*current_type = null;
	quoted = 0;
	while (*input_str)
	{
		if (!quoted && *input_str == ';')
		{
			add_token(current_token, current_type, tokens, types);
			add_token(";", operator, tokens, types);
		}
		else if (current_type && *current_type == operator && !quoted && is_op(current_token, *input_str))
			current_token = strappend(current_token, *input_str);
		else if (current_type && *current_type == operator)
		{
			add_token(current_token, current_type, tokens, types);
			continue ;
		}
		else if (IS_QUOTE(*input_str) && !quoted)
			quoted |= quoted_flags(*input_str);
		else if (IS_QUOTE(*input_str))
			handle_embedded_quotes(&quoted, &input_str);
		else if (!quoted && is_op("", *input_str))
		{
			add_token(current_token, current_type, tokens, types);
			*current_type = operator;
			strappend(current_token, *input_str);
		}
		else if (!quoted && (*input_str == '\n' || *input_str == ' '))
			add_token(current_token, current_type, tokens, types);
		else if (*current_type == word)
			current_token = strappend(current_token, *input_str);
		else if (*input_str == '#')
			break ;
		else
		{
			*current_type = word;
			current_token = strappend(current_token, *input_str);
		}
		input_str++;
	}
	add_token(current_token, current_type, tokens, types);
}
