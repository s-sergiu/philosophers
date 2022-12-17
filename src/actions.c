/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:07:29 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/17 07:57:31 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleeping(struct s_data *data)
{
	write(1, "Philosopher is sleeping\n", 25);
	usleep((*data).tts);
}

void	thinking(struct s_data *data)
{
	write(1, "Philosopher is thinking\n", 25);
	usleep((*data).ttd);
}

void	eating(struct s_data *data)
{
	write(1, "Philosopher is eating\n", 22);
	usleep((*data).tte);
}
