/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:07:29 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/21 15:05:03 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleeping(struct s_data *data)
{
	write(1, "Philosopher is sleeping\n", 24);
	usleep((*data).tts * 1000);
}

void	thinking(struct s_data *data)
{
	write(1, "Philosopher is thinking\n", 24);
	usleep((*data).ttd * 1000);
}

void	eating(struct s_data *data)
{
	pthread_mutex_lock(data->mutex);
	write(1, "Philosopher is eating\n", 22);
	pthread_mutex_unlock(data->mutex);
	usleep((*data).tte * 1000);
}
