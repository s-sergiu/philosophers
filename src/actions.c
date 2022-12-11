/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 03:07:29 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/11 04:04:43 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleeping()
{
	write(1, "Philosopher is sleeping\n", 22);
}

void	thinking()
{
	write(1, "Philosopher is thinking\n", 22);
}

void	eating(struct s_data *data)
{
	write(1, "Philosopher is eating\n", 22);
	usleep((*data).tte);
}
