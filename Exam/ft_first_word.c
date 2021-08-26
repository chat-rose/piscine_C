#include <unistd.h>

int	main(int ac, char ** av)
{
	if (ac == 2)
	{
		char *str;
		int i;

		i = 0;	
		str = av[1];
		while (str[i] == ' ' || str[i] == 9)
			i++;
		while (str[i] != 9 && str[i] != ' ' && str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
