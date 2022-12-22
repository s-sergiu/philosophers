/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:51:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/21 14:57:20 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_values(struct s_data  **data)
{
	printf("Number of philosophers: %d.\n", (*data)->philosophers);
	printf("Time to die: %d.\n", (*data)->ttd);
	printf("Time to eat: %d.\n", (*data)->tte);
	printf("Time to sleep: %d.\n", (*data)->tts);
	printf("Number of times they eat: %d.\n", (*data)->times_eat);
	printf("The number is: %d.\n", (*data)->number);
}

void	*philo_routine(void *arg)
{
	struct s_data	*data;

	data = arg;
	// eat
	eating(data);	
	// think
	thinking(data);
	// sleep
	sleeping(data);
	return (NULL);
}

void	*routine(void *arg)
{
	struct s_data	*data;
	int				i;

	data = arg;
	i = -1;
	pthread_mutex_lock(data->mutex);
	eating(data);
	while (++i < 10)
	{
		data->number++;	
		printf("Routine...\n");
	}
	pthread_mutex_unlock(data->mutex);
	return (arg);
}

int main(int argc, char **argv)
{
	struct	s_data	*data;		

	if (argc == 5 || argc == 6)
		init_threads(&data, argv);
	else
		return (0);
	pthread_mutex_destroy(data->mutex);
	return (0);
}
