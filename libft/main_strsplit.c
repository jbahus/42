#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	s[] = "Yo**how*are***you***";
	char	**p;
	int		i;

	i = 0;
	p = ft_strsplit(s, '*');
	while (i != 5)
	{
		printf("%s", p[i]);
		i++;
	}
	return (0);
}
