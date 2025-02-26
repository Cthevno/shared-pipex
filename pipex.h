/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:28:32 by ctheveno          #+#    #+#             */
/*   Updated: 2025/02/24 15:37:47 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	int		pid1;
	int		pid2;
	int		fd[2];
	int		ac;
	int		av_pos;
	char	**av;
	char	**env;
	char	*cmd_path;
	char	**cmd_and_args;
}	t_data;
char	*ft_find_path(char **all_paths, char *str);
char	*ft_find_command(char **env, char **cmd_and_args);
int		ft_get_cmd_args(t_data *data);
int		ft_exec_cmd(char *av, char **env);

#endif
