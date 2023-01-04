/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:07:29 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/04 15:50:54 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(void *arg)
{
	struct s_philosophers	*philo;

	philo = arg;
	printf("Philo %d is eating;\n", philo->id);
	usleep(*philo->time_to_eat * 1000);
}

void	think(void *arg)
{
	struct s_philosophers	*philo;

	philo = arg;
	printf("Philo %d is thinking;\n", philo->id);
	usleep(*philo->time_to_die * 1000);
}

void	sleeping(void *arg)
{
	struct s_philosophers	*philo;

	philo = arg;
	printf("Philo %d is sleeping;\n", philo->id);
	usleep(*philo->time_to_sleep * 1000);
}

void *routine(void *arg)
{
	struct s_philosophers	*philo;

	philo = arg;
	while (*philo->dead_flag == 0)
	{
		eat(arg);
		think(arg);
		sleeping(arg);
	}
	return (NULL);
}
