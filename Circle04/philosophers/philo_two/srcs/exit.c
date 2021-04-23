/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:45:23 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 09:08:24 by gipark           ###   ########.fr       */
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

void	destroy_semaphore_philo(t_philosopher *philo, t_semaphore *semaphore)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat");
	sem_close(semaphore->eat_s);
	sem_close(semaphore->fork_s);
	sem_close(semaphore->print_s);
	free(philo);
}
