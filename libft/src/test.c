#include "libft.h"

int	main(void)
{
	char *str;

	str = ft_memalloc(1024);
	strcpy(str, "Hello World");
	str = realloc(str, 2048);
	printf("%s\n", str);
}