/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:38:25 by asyed             #+#    #+#             */
/*   Updated: 2018/03/22 19:48:37 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_EXEC_H
# define FT_EXEC_H
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ast.h"

typedef struct	s_process
{
	int	*stdin; // 0 and 1 are the same FD.
	int	*stdout; // 0 = read;1 = write
	int	*stderr; // ^
	int	*dep;
	int	ret;
}				t_process;

struct			s_redir_op
{
	char	*opflag;
	int		(*func)(t_process *, t_ast *, size_t pos);
}				t_redir_op;

int	redir_outfile(t_process *p_info, t_ast *ast, size_t pos);
int	redir_infile(t_process *p_info, t_ast *ast, size_t pos);

extern struct s_redir_op	redir_ops[];

#endif