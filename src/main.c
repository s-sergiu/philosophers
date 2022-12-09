#include "../include/philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	i;
	int	sign;

	x = 0;
	i = 0;
	sign = 1;
	while (str[i] == 9 || str[i] == 32 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		x = x * 10 + str[i++] - '0';
	return (x * sign);
}

void	*routine (void *arg)
{
	struct s_data	*data;
	int				i;

	data = arg;
	printf("Routine...\n");
	i = -1;
//	pthread_mutex_lock(data->mutex);
	while (++i < 10000000)
		data->number++;	
//	pthread_mutex_unlock(data->mutex);
	return (arg);
}

void	init_optional(struct s_data **data, char **argv)
{
	int	i;
	(*data) = (struct s_data *)malloc(sizeof(struct s_data));
	(*data)->number = 0;
	(*data)->counter = 0;
	(*data)->philosophers = ft_atoi(argv[1]);
	(*data)->threads = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	i = -1;
	(*data)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*data)->mutex, NULL);
	while (++i < (*data)->philosophers)
		pthread_create(&((*data)->threads)[i], NULL, routine, (*data));
	i = -1;
	while (++i < (*data)->philosophers)
		pthread_join(((*data)->threads)[i], NULL);
	(*data)->ttd = ft_atoi(argv[2]);
	(*data)->tte = ft_atoi(argv[3]);
	(*data)->tts = ft_atoi(argv[4]);
	(*data)->times_eat = ft_atoi(argv[5]);
}

void	init_normal(struct s_data **data, char **argv)
{
	int			i;
	pthread_t	*threads;

	(*data) = (struct s_data *)malloc(sizeof(struct s_data));
	(*data)->number = 0;
	(*data)->counter = 0;
	(*data)->philosophers = ft_atoi(argv[1]);
	(*data)->threads = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	threads = (*data)->threads;
	i = -1;
	(*data)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*data)->mutex, NULL);
	while (++i < (*data)->philosophers)
		pthread_create(&threads[i], NULL, routine, (*data));
	i = -1;
	while (++i < (*data)->philosophers)
		pthread_join(threads[i], NULL);
	(*data)->ttd = ft_atoi(argv[2]);
	(*data)->tte = ft_atoi(argv[3]);
	(*data)->tts = ft_atoi(argv[4]);
	(*data)->times_eat = 1;
}

void	print_values(t_data **data)
{
	printf("Number of philosophers: %d.\n", (*data)->philosophers);
	printf("Time to die: %d.\n", (*data)->ttd);
	printf("Time to eat: %d.\n", (*data)->tte);
	printf("Time to sleep: %d.\n", (*data)->tts);
	printf("Number of times they eat: %d.\n", (*data)->times_eat);
}

int main (int argc, char **argv)
{
	struct	s_data	*data;		

	if (argc == 5)
		init_normal(&data, argv);
	else if (argc == 6)
		init_optional(&data, argv);
	else
		return (0);
	printf("Starting main\n");
	printf("\n");
	print_values(&data);
	printf("\n");
	printf("Initialized struct\n");
	pthread_mutex_destroy(data->mutex);
	printf("Exiting main\n");
	printf("number is %d\n", data->number);
	return (0);
}
