/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:51:31 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/05 19:25:12 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_invalid_input(struct s_data *data)
{
	if ((*data).number_of_philosophers < 0)
		return (1);
	return (0);
}

int	input_error(void)
{
	write(1, "Usage:\n", 7);
	return (0);
}

int main(int argc, char **argv)
{
	struct s_data	*data;
	struct timeval	t1;
	struct timeval	t2;
	long			elapsed;

	if (argc > 6 || argc < 5)
		return (input_error());
	else
	{
		initialize_data(&data, argv);
		gettimeofday(&t1, NULL);
		usleep(1000 * 100);
		gettimeofday(&t2, NULL);
		elapsed = (t2.tv_usec-t1.tv_usec) * 100 + t2.tv_usec-t1.tv_usec;
		printf("elapsed %ld\n", elapsed);
		if (is_invalid_input(data))
			return (input_error());
		initialize_philosophers(&data);
	}
	return (1);
}
