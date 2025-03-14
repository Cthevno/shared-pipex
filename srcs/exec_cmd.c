/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:59:59 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/06 10:46:01 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec_absolute_path(char *av, char **env)
{
	char	**cmd_and_args;

	cmd_and_args = ft_split(av, ' ');
	if (!cmd_and_args)
		return (1);
	if (execve(av, cmd_and_args, env) == -1)
	{
		ft_free_doble_tab(cmd_and_args);
		return (1);
	}
	return (0);
}

int	ft_exec_cmd(char *av, char **env)
{
	char	*cmd_path;
	char	**cmd_and_args;

	if (access(av, X_OK) == 0)
		return (ft_exec_absolute_path(av, env));
	cmd_and_args = ft_split(av, ' ');
	if (!cmd_and_args)
		return (1);
	cmd_path = ft_find_command(env, cmd_and_args);
	if (!cmd_path)
	{
		ft_free_doble_tab(cmd_and_args);
		return (1);
	}
	else if (execve(cmd_path, cmd_and_args, env) == -1)
	{
		ft_free_doble_tab(cmd_and_args);
		ft_free(&cmd_path);
		return (1);
	}
	return (0);
}

char	*search_path_in_env(char **env)
{
	while (*env != NULL)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	return (*env +5);
}

char	*ft_find_command(char **env, char **cmd_and_args)
{
	char	*path_env;
	char	**all_paths;
	char	*cmd_path;

	cmd_path = NULL;
	path_env = NULL;
	path_env = search_path_in_env(env);
	if (path_env)
		all_paths = ft_split(path_env, ':');
	else
		all_paths = ft_split("", ':');
	if (all_paths)
		cmd_path = ft_find_path(all_paths, cmd_and_args[0]);
	if (cmd_path)
	{
		ft_free_doble_tab(all_paths);
		return (cmd_path);
	}
	ft_free_doble_tab(all_paths);
	return (NULL);
}

char	*ft_find_path(char **all_paths, char *str)
{
	char	*cmd_path;
	char	*temp_s;

	cmd_path = NULL;
	while (all_paths && *all_paths != NULL)
	{
		temp_s = ft_strdup(*all_paths);
		if (temp_s)
			temp_s = ft_strjoin(temp_s, "/");
		if (temp_s)
			cmd_path = ft_strjoin(temp_s, str);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		ft_free(&cmd_path);
		all_paths++;
	}
	return (NULL);
}
