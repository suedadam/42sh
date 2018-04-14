/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:59:31 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 02:08:55 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOCOMPLETE_H
# define FT_AUTOCOMPLETE_H

# include <sys/stat.h>
# include "ft_term.h"
# include "ft_proto.h"

typedef struct	s_trie_with_level
{
	struct s_trie	*children[128];
	char			key;
	int				nbr_children;
	int				pos;
	char			child;
}				t_trie_with_level;

/*
** trie dfs autocomplete
*/
void		trie_dfs(t_trie *trie, t_stack *stack);

/*
**	For finding relative word location / count on the terminal, which will
**	then dictate the type of trie that needs to be built
**	(count_word.c)
*/

void		wcount_forword(char byte);
void		wcount_backword(char byte);
void		find_backwords(void);

/*
**
**	(id_add_name.c)
*/

int		id_add_name(struct stat *sbuf, struct dirent *entry);

/*
**
**	(check_possible_dir.c)
*/

char	*check_possible_dir(void);

/*
**
**	(gather_paths.c)
*/

char	**gather_paths(int word, char **basepath);

/*
**
**	(concat_path.c)
*/

char	*concatpath(char *fin, char *add);

/*
**
**	(find_pathnames.c)
*/

int		autofind_pathnames(void);

/*
**
**	(build_dirnames.c)
*/

int		buildir_names(DIR *d_base, char *basepath);

/*
**
**	(build_dirnames.c)
*/

void	del_paths(char **mul_paths);

#endif
