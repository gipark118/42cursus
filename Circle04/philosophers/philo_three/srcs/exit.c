/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:54:13 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 09:57:41 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		print_error(int error)
{
	if (error == NUMBER_OF_ARG)
		printf("error: bad arguments\n");
	else if (error == NUMERIC_ARG)
		printf("error: numeric argument required\n");
	else if (error == MALLOC || error == SEMAPHORE || error == PTHREAD)
		printf("error: fatal\n");
	return (FAILURE);
}

void	destroy_semaphore_philo(t_philosopher *philo)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat");
	sem_unlink("main");
	sem_unlink("philo");
	sem_close(philo->semaphore->fork_s);
	sem_close(philo->semaphore->print_s);
	sem_close(philo->semaphore->eat_s);
	sem_close(philo->semaphore->main_s);
	sem_close(philo->semaphore->philo_s);
}

void	wait_and_exit(t_philosopher *philo)
{
	int	i;

	i = 0;
	waitpid(-1, NULL, 0);
	while (i < philo->info->number_of_philo)
	{
		kill(philo->pid[i], SIGTERM);
		i++;
	}
	free(philo->pid);
}
