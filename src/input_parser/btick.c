#include "ast.h"

static int	is_quoted(uint8_t *quoted, char c, char **command)
{
	if (*quoted & BACKSLASH)
	{
		if (!IS_ESCAPED(c))
			if (!(*command = strappend(command, '\\')))
				return (EXIT_FAILURE);
		*quoted &= ~BACKSLASH;
	}
	else if (IS_QUOTE(c))
		*quoted ^= quoted_flags(c);
	return (EXIT_SUCCESS);
}

static int	close_chck(uint8_t quoted, char c, char **command, int paren)
{
	if (!(quoted & BACKSLASH) && c == BACKT)
	{
		if (quoted || paren)
		{
			free(*command);
			*command = NULL;
			return (EXIT_FAILURE_SOFT); //parse error
		}
		return (EXIT_SUCCESS);
	}
	return (UNUSED_CHAR);
}

char		*bquote_command(char **input_str)
{
	int		i;
	char	*command;
	int		paren;
	uint8_t	quoted;

	quoted = 0;
	paren = 0;
	command = NULL;
	i = 1;
	while ((*input_str)[i])
	{
		if (close_chck(quoted, (*input_str)[i], &command, paren) != UNUSED_CHAR)
		{
			*input_str = *input_str + i + 1;
			return (command == NULL ? MAP_FAILED : command);
		}
		if (is_quoted(&quoted, (*input_str)[i], &command) == EXIT_FAILURE)
			return (NULL);
		if (!(quoted & BACKSLASH) &&
			!(command = strappend(&command, (*input_str)[i])))
			return (NULL);
		paren += check_paren((*input_str)[i]);
		i++;
	}
	free(command);
	return (MAP_FAILED);
}
