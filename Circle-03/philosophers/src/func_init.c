#include "../includes/philo.h"

t_info	*init(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	memset(info, 0, sizeof(info));
// 	printf("argv 2: %s\n", argv[2]);
// 	printf("argv 3: %s\n", argv[3]);
// 	printf("argv 4: %s\n", argv[4]);
// 	printf("argv 5: %s\n", argv[5]);
	return (info);
}
