/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:31 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/15 16:48:50 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

int				history_append_file(char *buffer);
int				history_init(void);
t_dblist		*get_history(void);
void			up_history_command(void);
void			down_history_command(void);
int				delete_history(void);
int				display_history(void);

#endif
