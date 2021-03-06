/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:31:10 by bleaf             #+#    #+#             */
/*   Updated: 2022/07/07 23:48:29 by bleaf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

/*
	Find var PATH in environment, returns almost all string without "PATH=".
	If it doesn't exist, returns NULL
*/
static char	*find_path(char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", ft_strlen("PATH")) == 0)
		{
			while (envp[i][j] != '=' && envp[i][j])
				j++;
			j++;
			return (ft_substr(envp[i], j, ft_strlen(envp[i]) - j));
		}
		i++;
	}
	return (NULL);
}

/*
	Checking access to cmd, returns accessible path.
	If it doesn't exist, returns NULL.
*/
static char	*check_access(char *path, char *cmd)
{
	char	*comp_cmd;
	char	*path_with_slash;

	path_with_slash = ft_strjoin(path, "/");
	comp_cmd = ft_strjoin(path_with_slash, cmd);
	if (!access(comp_cmd, F_OK))
	{
		free(path);
		free(path_with_slash);
		return (comp_cmd);
	}
	free(path);
	free(path_with_slash);
	free(comp_cmd);
	return (NULL);
}

/*
	Fulfills cmds of the pipe.
	Frees var paths in f-n check_access().
*/
void	find_valid_path(char **envp, t_pipe *pipe, t_cmd *cmd)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(find_path(envp), ':');
	if (!paths)
		error_cmd(pipe, "Failure with finding PATH.");
	while (paths[i])
	{
		cmd->cmd_path = check_access(paths[i], cmd->cmd[0]);
		if (cmd->cmd_path)
			break ;
		i++;
	}
	free(paths);
}
