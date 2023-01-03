/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:07:29 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/03 18:19:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void *routine(void *arg)
{
	struct s_data *data;
	struct s_philosophers *philo;

	data = arg;
	philo = data->philosophers;
	printf("routine %d\n", philo->id);
	return (NULL);
}
