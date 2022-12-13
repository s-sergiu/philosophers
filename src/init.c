/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:50:32 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/12 09:45:15 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	create_threads(struct s_data **data)
{
	int			i;
	pthread_t	*threads;
	int			number;
	
	number = (*data)->philosophers;
	(*data)->threads = (pthread_t *)malloc(sizeof(pthread_t) * number);
	threads = (*data)->threads;
	i = -1;
	while (++i < (*data)->philosophers)
		pthread_create(&threads[i], NULL, routine, (*data));
	i = -1;
	while (++i < (*data)->philosophers)
		pthread_join(threads[i], NULL);
}

int	init_threads(struct s_data **data, char **argv)
{
	(*data) = (struct s_data *)malloc(sizeof(struct s_data));
	(*data)->number = 0;
	(*data)->philosophers = ft_atoi(argv[1]);
	(*data)->ttd = ft_atoi(argv[2]);
	(*data)->tte = ft_atoi(argv[3]);
	(*data)->tts = ft_atoi(argv[4]);
	if (argv[5])
		(*data)->times_eat = ft_atoi(argv[5]);
	if ((*data)->philosophers < 1 || (*data)->ttd < 1 || (*data)->tte < 1
		|| (*data)->tts < 1 || (*data)->times_eat < 1)
	{
		write(1, "Input error\n", 12);
		return (1);
	}
	(*data)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*data)->mutex, NULL);
	create_threads(data);
	//
	return (0);
}
