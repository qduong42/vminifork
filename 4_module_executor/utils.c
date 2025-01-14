/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:50:27 by smischni          #+#    #+#             */
/*   Updated: 2022/07/26 16:24:11 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Takes a string array as parameter and frees every string as well as the array.
 * @param str [char **] String array to be freed.
 * @return [int] 1 at success, 0 at failure.
*/
int	free_str_array(char **str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (1);
}

/**
 * Takes an array of lists and frees every list element and the list itself.
 * @param lists [t_list **] Array of lists.
 * @return [int] 1 at success, 0 at failure.
*/
int	free_lst_array(t_list **lists)
{
	int	i;

	if (!lists)
		return (1);
	i = 0;
	while (lists[i])
	{
		ft_lstclear(&lists[i], free);
		free(lists[i++]);
	}
	free(lists);
	return (1);
}

/**
 * Takes a list containing the environmental variables and reassembles it into
 * a string array, containing each variable as one string.
 * @param [t_env *] List containing each environmental variable as an element.
 * @return [char **] String array containing the environmental variables.
*/
char	**reassemble_env(t_env *env)
{
	t_env	*tmp;
	char	*tmp2;
	char	**envp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (env)
	{
		tmp2 = ft_strjoin(env->bash_variable, "=");
		envp[i++] = ft_strjoin(tmp2, env->bash_v_content);
		free(tmp2);
		env = env->next;
	}
	return (envp);
}

//temporary function to check input
int	print_all_input(t_data *data)
{
	t_env		*env;
	t_parser	*parser;
	t_list		*cur_sec;
	int			i;
	int			j;
	
	i = 0;
	env = &(data->to_env_list);
	printf("\nCHECK T_DATA CONTENT:\n");
	printf("\nENV:\n");
	while (env)
	{
		printf("%s=%s\n", env->bash_variable, env->bash_v_content);
		env = env->next;
	}
	parser = &(data->to_parser_list);
	printf("\nSECTIONS:\n");
	while (parser->sections[i])
	{
		cur_sec = parser->sections[i];
		j = 1;
		while (cur_sec)
		{
			printf("%d. list element: %s\n", j++, (char *)cur_sec->line);
			cur_sec = cur_sec->next;
		}
		i++;
	}
	printf("\nPATH:\n");
	i = 0;
	while (parser->paths[i])
		printf("%s\n", parser->paths[i++]);
	printf("\nCOMMANDS:\n");
	i = 0;
	while (parser->command[i])
		printf("%s\n", parser->command[i++]);
	return (1);
}
