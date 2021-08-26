#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	str[] = "     ----+-ABjhff0";
	char	base[] = "0123456789ABCDEF";

	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
