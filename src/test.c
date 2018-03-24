#include "ft_term.h"


int		terminit(t_terminf *anti)
{
	int		ret;
	char	*buff;
//	char	*temp;

	anti->term_buff = (char *)ft_memalloc(2048);
	anti->term_name = getenv("TERM");
	ft_printf("anti->term_name : %s\n", anti->term_name);
	ret = tgetent(anti->term_buff, anti->term_name);
	if (ret < 0)
		g_ft_errnum = TGETN;
	else if (ret == 0)
		g_ft_errnum = TGETZ;
	if (!(buff = (char *)ft_memalloc(2048)))
		return (EXIT_FAILURE);
//	if (!(temp = tgetstr("pc", &buff)))
//		g_ft_errnum = TGETSTR;
//	else
//		PC = *temp;
	/* for term_buff and tgoto */
	if (!(BC = tgetstr("le", &(anti->term_buff))))
		g_ft_errnum = TGETSTR;
	if (!(UP = tgetstr("up", &(anti->term_buff))))
		g_ft_errnum = TGETSTR;
	return (((ret > 0) && (!g_ft_errnum)) ? EXIT_SUCCESS : EXIT_FAILURE);
}

int		read_multibyte(char byte, int *mpass)
{
	char	discard[2];

	if (*mpass == 0
		|| (*mpass == 1 && byte == '['))
	{
		ft_printf("escape sequence %d\n", *mpass);
		(*mpass)++;
		return (EXIT_SUCCESS);
	}
	else if (*mpass && LSEEK(byte))
		ft_printf("\nhome or end\n");
	else if (*mpass && DEL(byte))
	{
		read(STDIN_FILENO, &discard, 1);
		ft_printf("\ndelete key\n");
	}
	else if (*mpass && SCRL(byte))
	{
		read(STDIN_FILENO, &discard, 1);
		ft_printf("\npgup or pgdwn\n");
	}
	else if (*mpass && HIST(byte))
		ft_printf("\narrup or arrdwn\n");
	else if (*mpass == 2 && byte == '1')
	{
		read(STDIN_FILENO, &discard, 2);
		ft_printf("\nshift\n");
	}
	*mpass = 0;

	return (EXIT_SUCCESS);
}

int		quote_mode(char byte)
{
	byte = 0;
	ft_printf("quote mode\n");
	return (EXIT_SUCCESS);
}

int		read_loop(t_terminf *anti)
{
	char	byte;
	int		mpass;

	anti = (void *)anti;
	mpass = 0;
	while (read(STDIN_FILENO, &byte, 1) == 1)
	{
		if ((byte == 27) || mpass)
			read_multibyte(byte, &mpass);
		else if (byte == 12 && !mpass)
			ft_printf("clearscreen\n");
		else if (byte == 127 && !mpass)
			ft_printf("backspace\n");
		else if (byte == 39 || byte == 34)
			quote_mode(byte);
	/* quick and dirty test to see what sort of tty flags need to be set on executions
		if (byte == 'p')
		{
			char	*catarg[2] = {"ls", 0};
			int pid = fork();
			if (pid == 0)
			{
				execv("//bin/ls", catarg);
			}
			else
				wait(&pid);
		}
	*/
		else if (byte == 4 && !mpass)
			break ;
		else if (!mpass)
			ft_printf("num:  %d\nchar: %c\n", byte, byte);
	}
	return (EXIT_SUCCESS);
}

/* 
** isatty returns 0 when it fails, and sets errno 
** tcgetattr returns -1 on failure and sets errno 
*/

int		io_init(t_terminf *anti)
{
	if (!(anti->antishell = ft_memalloc(sizeof(struct termios)))
		|| (!(isatty(STDIN_FILENO)))
		|| ((tcgetattr(STDIN_FILENO, &anti->og)) < 0)
		|| (!(anti->antishell = (struct termios *)ft_memcpy(anti->antishell,
				&anti->og, sizeof(struct termios))))
		|| (ft_setty(anti) == EXIT_FAILURE))
	{
		ft_printf("fail\n");
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


/*
** Welcome to the shitty shell.  I am your host, anti.
** To communicate around here, these parts shout at each other with:
** EXIT_SUCCESS = 0 and
** EXIT_FAILURE = 1
*/

int		main(void)
{
	t_terminf	anti;

	printf("errno: %d\n", errno);
	bzero(&anti, sizeof(t_terminf));
	if (io_init(&anti) == EXIT_FAILURE
		|| shsignal_handlers() == EXIT_FAILURE
		|| terminit(&anti) == EXIT_FAILURE
		|| read_loop(&anti) == EXIT_FAILURE
		|| ft_restoretty(&anti) == EXIT_FAILURE)
//		|| termloop(&anti) <= 0) == EXIT_FAILURE
		ft_terror();
	return (0);
}
