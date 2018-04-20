/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:31 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 03:19:07 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "ft_proto.h"

int				history_append_file(char *buffer);
int				history_init(void);
t_dblist		*get_history(void);
void			up_history_command(void);
void			down_history_command(void);
int				delete_history(void);
int				display_history(void);
void			free_dblist(t_dblist **delete);
char			*create_home_assoc(char *filename);

#endif
