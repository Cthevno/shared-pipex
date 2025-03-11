/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:28:32 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:34:44 by ctheveno         ###   ########.fr       */
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
	int		ac;
	char	**av;
	char	**env;
	int		nb_cmds;
	int		*pids;
	int		fd_in;
	int		fd_out;
	int		fd[2];
	// int		fd_temp;
}	t_data;
char	*ft_find_path(char **all_paths, char *str);
char	*ft_find_command(char **env, char **cmd_and_args);
int		ft_get_cmd_args(t_data *data);
int		ft_exec_cmd(char *av, char **env);
void	close_all_fds(t_data *data);
void	pipex_standard(t_data *d);
void	pipex_here_doc(t_data *d, int fd_temp_file);
void	ft_here_doc_loop(t_data *data, char *line, int fd_temp_file);
void	ft_here_doc(t_data *d);
pid_t	first_child_process(char *av, t_data *data);
pid_t	middle_child_process(char *av, t_data *data);
void	last_child_process(char *av, t_data *data);
void	error(const char *msg, const char *cmd, t_data *data, int exit_status);
void	waitpids(t_data *data);
void	clean_all(t_data *data);

#endif
