/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:43:15 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 01:10:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

# include "libft.h"

# define FOUND		42
# define NOT_FOUND	-42

typedef struct s_trie
{
	struct s_trie	*children[128];
	char			key;
	int				nbr_children;
}				t_trie;

void		add_word_to_trie(t_trie *trie, char *word);
t_trie		*new_trie(void);
int			search_word(t_trie *trie, char *word);
void		display_trie(t_trie *trie, int level);

#endif
