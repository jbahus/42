#include "fdf_test.h"

t_map	get_map(int nb, t_map *map)

void	go_map(char *str, t_map **map)
{
	int		i;
	char	**ret;
	t_map	**map;


	ret = ft_strsplit(str, ' ');
	if (!ret)
		return ;
	while (ret[i])
		get_map(ft_atoi(ret[i++]));
}

int 	main(int argc, char const **argv)
{
	int		fd;
	char	*ret;
	t_map	**map;
	int		i;

	i = 0;
	if (!argc)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &ret))
	{
		map[i] = (t_map**)malloc(sizeof(t_map) * ft_strlen(ret));
		go_map(ret, &map[i++]);
	}
	return (0);
}