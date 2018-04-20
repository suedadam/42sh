/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:38:31 by asyed             #+#    #+#             */
/*   Updated: 2018/04/20 10:54:47 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	variable_expansion(char **str, t_environ *env)
{
	char	*local;

	if (**str == '$')
	{
		if (!(local = ft_strdup(ft_getenv(&((*str)[1]), env))))
			return ;
		meta_free(*str);
		*str = local;
	}
}

void	oldpwd_expansion(char **str, t_environ *env)
{
	size_t	len;
	size_t	homelen;
	char	*tmp;
	char	*local;

	len = ft_strlen(*str);
	if (!(homelen = ft_strlen(ft_getenv("OLDPWD", env))))
		return ;
	if (**str == '-')
	{
		if (!(local = ft_memalloc(sizeof(char) * len + homelen + 1)))
			return ;
		if (!(tmp = ft_strdup(&((*str)[1]))))
		{
			meta_free(local);
			return ;
		}
		memcpy(local, ft_getenv("OLDPWD", env), homelen);
		memcpy(local + homelen, tmp, len);
		meta_free(tmp);
		meta_free(*str);
		*str = local;
	}
}

void	home_expansion(char **str, t_environ *env)
{
	size_t	len;
	size_t	homelen;
	char	*tmp;
	char	*local;

	len = ft_strlen(*str);
	if (!(homelen = ft_strlen(ft_getenv("HOME", env))))
		return ;
	if (**str == '~')
	{
		if (!(local = ft_memalloc(sizeof(char) * len + homelen + 1)))
			return ;
		if (!(tmp = ft_strdup(&((*str)[1]))))
		{
			meta_free(local);
			return ;
		}
		memcpy(local, ft_getenv("HOME", env), homelen);
		memcpy(local + homelen, tmp, len);
		meta_free(tmp);
		meta_free(*str);
		*str = local;
	}
}

void	relative_hook(t_ast *curr, t_environ *env)
{
	int		i;

	i = 0;
	if (!curr || !env)
		return ;
	while (curr->token[i])
	{
		home_expansion(&(curr->token[i]), env);
		if (i && ft_strequ(curr->token[i - 1], "cd"))
			oldpwd_expansion(&(curr->token[i]), env);
		variable_expansion(&(curr->token[i]), env);
		i++;
	}
}
