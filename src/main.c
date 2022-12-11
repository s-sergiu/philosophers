/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:51:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/11 04:47:44 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_values(t_data **data)
{
	printf("Number of philosophers: %d.\n", (*data)->philosophers);
	printf("Time to die: %d.\n", (*data)->ttd);
	printf("Time to eat: %d.\n", (*data)->tte);
	printf("Time to sleep: %d.\n", (*data)->tts);
	printf("Number of times they eat: %d.\n", (*data)->times_eat);
}

void	*routine (void *arg)
{
	struct s_data	*data;
	int				i;

	data = arg;
	printf("Routine...\n");
	i = -1;
	pthread_mutex_lock(data->mutex);
	eating(data);
	while (++i < 10000000)
		data->number++;	
	pthread_mutex_unlock(data->mutex);
	return (arg);
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
