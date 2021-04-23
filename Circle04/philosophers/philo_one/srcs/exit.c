/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:26:48 by gipark            #+#    #+#             */
/*   Updated: 2021/04/22 00:30:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		print_error(int error)
{
	if (error == NUMBER_OF_ARG)
		printf("error: bad arguments\n");
	else if (error == NUMERIC_ARG)
		printf("error: numeric argument required\n");
	else if (error == MALLOC || error == MUTEX || error == PTHREAD)
		printf("error: fatal\n");
	return (FAILURE);
}

void	destroy_pthread_philo(t_philosopher *philo,
		t_mutex *mutex, t_info *info)
{
	int i;

	i = 0;
	while (i < info->number_of_philo)
	{
		pthread_mutex_destroy(&(mutex->fork_m)[i]);
		i++;
	}
	pthread_mutex_destroy(&(mutex->print_m));
	pthread_mutex_destroy(&(mutex->state_m));
	pthread_mutex_destroy(&(mutex->eat_m));
	free(philo);
	free(mutex->fork_m);
}
