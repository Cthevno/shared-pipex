/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:20 by ctheveno          #+#    #+#             */
/*   Updated: 2025/02/26 15:27:07 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	middle_childs(char **av, char **env, int *fd)
{

}
void	pipex(int ac, char **av, char **env)
{

}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		pipex(ac, av, env);
	}
	else
		ft_printf("Error with args, ex of args : infile cmd1 cmd2 outfile\n");
	return (0);
}
