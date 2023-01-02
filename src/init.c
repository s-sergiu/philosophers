/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:50:32 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/02 11:49:28 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isdigit(char c)
{
	if (c > 39 && c < 58)				
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
	*data = (struct s_data*)malloc(sizeof(struct s_data));
	(*data)->number_of_philosophers = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);

}

void	initialize_philosophers(struct s_data **data)
{
	printf("Number of philos: %d\n", (*data)->number_of_philosophers);
	printf("Time to die: %d\n", (*data)->time_to_die);
	printf("Time to eat: %d\n", (*data)->time_to_eat);
	printf("Time to sleep: %d\n", (*data)->time_to_sleep);
}
