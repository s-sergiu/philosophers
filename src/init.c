/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:50:32 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/04 10:51:41 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* started at 8:30 
* 9:32 - managed to implement philo creation with routine;
  10:48 - implemented a simple routine with actions (eat, sleep and think);
  * don't feel as productive as I was; 
* todo - trying to solve the holding pattern; 
*/

#include "../include/philosophers.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')				
		return (1);
	return (0);
}

int	ft_atoi(char *string)
{
	int	number;
	int	i;

	i = -1;
	number = 0;
	while(string[++i] != 0)
	{
		if (ft_isdigit(string[i]))
			number = number * 10 + string[i] - '0';
		else
			return (-1);
	}
	return (number);
}

void	initialize_data(struct s_data **data, char **argv)
{
	int number;

	*data = (struct s_data*)malloc(sizeof(struct s_data));
	(*data)->number_of_philosophers = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);
	(*data)->flag = 0;
	number = (*data)->number_of_philosophers;
	(*data)->philosophers = malloc(sizeof(struct s_philosophers*) * number);

}

void	initialize_philosophers(struct s_data **data)
{
	int number;
	int i;
	struct s_philosophers **philo;

	i = 0;
	number = (*data)->number_of_philosophers;
	philo = (*data)->philosophers;
	while (i < number)
	{
		philo[i] = malloc(sizeof(struct s_philosophers));
		philo[i]->id = i;
		philo[i]->time_to_die = &(*data)->time_to_die;
		philo[i]->time_to_eat= &(*data)->time_to_eat;
		philo[i]->time_to_sleep = &(*data)->time_to_sleep;
		philo[i]->flag = &(*data)->flag;
		philo[i]->thread = malloc(sizeof(pthread_t*));
		philo[i]->number = &(*data)->number_of_philosophers;
		i++;
	}
	i = 0;
	while (i < number)
	{
	pthread_create(philo[i]->thread, NULL, routine, philo[i]);
	(*data)->flag++;
	i++;
	}
	i = 0;
	while (i < number)
	{
	pthread_join(*philo[i]->thread, NULL);
	i++;
	}
}
