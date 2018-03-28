/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:46:18 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/28 12:31:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*g_pname;

int		main(int ac, char **av, char **ev)
{
	UNUSED(ac);
	g_pname = av[0] + 2;



	/*

	**while ( no_error )
	** {
	**		termio_output = termio part get user input
	**
			PM
			{
	**			satkins_output = satkins(termios_output);
	**			ast_output = ast(satkins_output);
	**			asyed = asyed(ast_output);
	**		}
	**		could be like : (if !satkins || !ast || !asyed) return big_Error_get_hella_here

	}

	*/


	return (0);
}
