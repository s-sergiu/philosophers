#include "../include/philosophers.h"

void	*routine (void *arg)
{
	struct s_data	*data;
	int				i;

	data = arg;
	printf("Routine\n");
	pthread_mutex_lock(data->mutex);
	i = -1;
	while (++i < 500000)
		data->number++;	
	pthread_mutex_unlock(data->mutex);
	return (arg);
}

void	*routine_2 (void *arg)
{
	struct s_data	*data;
	int				i;

	data = arg;
	printf("Routine\n");
	pthread_mutex_lock(data->mutex);
	i = -1;
	while (++i < 1000000)
		data->number++;	
	pthread_mutex_unlock(data->mutex);
	return (arg);
}

void	initialize_struct(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	(*data)->number = 0;
	(*data)->counter = 0;
	(*data)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*data)->mutex, NULL);
}

int main (int argc, char **argv)
{
	struct	s_data	*data;		
	pthread_t		t1;
	pthread_t		t2;


	printf("Starting main\n");
	initialize_struct(&data);
	printf("Initialized struct\n");
	pthread_create(&t1, NULL, routine, data);
	pthread_create(&t2, NULL, routine_2, data);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(data->mutex);
	printf("Exiting main\n");
	printf("number is %d\n", data->number);
	return (0);
}
