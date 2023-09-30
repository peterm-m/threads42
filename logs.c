/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:09:08 by pedro             #+#    #+#             */
/*   Updated: 2023/09/13 19:10:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_print_action(t_philo *ph, const char *log)
{
	static pthread_mutex_t	screen = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&screen);
	printf("%lld %lld %s\n", ph->t_life, ph->id, log);
	pthread_mutex_unlock(&screen);
	return ;
}
