#include "libft.h"

int	main(int ac, char **av)
{
	char	*line;
	int		num;

	(void)ac;
	num = ft_atoi(av[1]);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			ft_printf("%s\n", line);
			usleep(num);
			system("clear");
			while (get_next_line(0, &line))
			{
				if (ft_strstr(line, "Piece"))
					break ;
				ft_printf("%s\n", line);
				ft_strdel(&line);
			}
		}
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
}