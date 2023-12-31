/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:11:15 by pedromar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
*	unsigned int	n_ph
*	unsigned int	t_die
*	unsigned int	t_eat
*	unsigned int	t_sleep
*	int				n_eat
*/

typedef long long int	t_time;

typedef struct s_input
{
	long long int	n_ph;
	t_time			t_die;
	t_time			t_eat;
	t_time			t_sleep;
	long long int	n_eat;
}	t_input;

#endif