#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	main(void)
{
	char c;

	while (read(STDIN_FILENO, &c, 1))
		printf("-> %c\n", c);
	printf("EOF!\n");
}