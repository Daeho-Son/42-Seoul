#include "../includes/philo.h"

int		main(int argc, char **argv)
{
	t_info	*info;

	param_check(argc, argv);
	info = init(argv);
	if (!info)
	{
		return (-1);
	}

	return (0);
}
