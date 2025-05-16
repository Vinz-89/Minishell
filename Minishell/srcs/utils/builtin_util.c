/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:24:55 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/16 13:35:07 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int str_token(char *token)
{
	char *tmp;
	char *tmp1;
	
	if(!token)
		return(-1);
	if(!strncmp("echo",token,4))
		return(0);
	if(!strncmp("cd",token,2))
		return(1);
	if(!strncmp("pwd",token,3))
		return(2);
	if(!strncmp("export",token,6))
		return(3);
	if(!strncmp("env",token,3))
		return(4);
	if(!strncmp("exit",token,4))
		return(5);

	tmp = ft_strjoin("bash: ", token);
	tmp1 = ft_strjoin(tmp,": command not found");
	printf("%s\n",tmp1);
	free(tmp);
	free(tmp1);
	return(-1);
}

void free_split(char **split)
{
	int i;

	if(!split || !*split)
		return ;

	i = 0;

	while(split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}

	free(split);
	
}

static char *ptr_binpath(char **split)
{
	int i;

	i  = 0;
	///usr/bin a trouver
	while(split[i])
	{
		if(!strncmp("/usr/bin",split[i],8))
			return(split[i]);
		i++;
	}
	return(NULL);
}

static char *builtin_path(char *cmd)
{
	char *env;
	char *tmp;
	int i;

	env = ft_strdup(getenv("PATH"));
	char **splite_env = ft_split(env,':');
	free(env);
	env = NULL;
	i = 0;

	/*
	while(splite_env[i])
		printf("%s\n",splite_env[i++]);
	printf("NULL\n");
	*/
	tmp = ft_strjoin(ptr_binpath(splite_env),"/"); // `prob return NULL
	env = ft_strjoin(tmp, cmd);
	free(tmp);
	tmp = NULL;
	free_split(splite_env);
	return(env);
}

int argc_split(char **argv)
{
	int i;

	i = 0;
	while(argv[i])
		i++;
	return(i);
}


int sanitize_string(int argc, char **argv)
{
	int i;
	int j;
	int size;
	char *str;

	if (!argv || !argv[1])
        return (-1);
	
	i = 0;
	j = 0;
	//size = size_sanitize(argv[1]);
	size = ft_strlen(argv[1]);
	str = malloc(sizeof(char) * (size + 1));
	if(!str)
		return(-1);
	//printf(argv[1][],argv[1][size - 1]);
	while (argv[1][i])
	{
		if((i == 0 && argv[1][i] == '\"') || (i  == size - 1 && argv[1][i] == '\"'))
			i++;
		if(argv[1][i] == '\\')
			i++;
		str[j++] = argv[1][i++];
	}
	str[j] = '\0';
	free(argv[1]);
	argv[1] = str;

	return(1);
}

void echo_handler(char *path, int argc, char **argv)
{
	int status;
	int	backslach;


	// \truc = truc ou $truc = dan la var ou \$truc = $truc
	/*
	backslach = 0;
	if(!strncmp("\e",argv[1],1))
		backslach = 1;
		*/
	//if(backslach == 1)
	//view_split(argv);
	sanitize_string(argc, argv);
	//view_split(argv);
	if(fork() == 0)
		execve(path,argv, NULL);
    wait(&status);
	
}

void export_handler(char *path, int argc, char **argv)
{
	int status;

	//char *envp[] = {"truc=valeur", NULL};


	// \truc = truc ou $truc = dan la var ou \$truc = $truc
	/*
	backslach = 0;
	if(!strncmp("\e",argv[1],1))
		backslach = 1;
		*/
	//if(backslach == 1)
	//view_split(argv);
	//sanitize_string(argc, argv);
	//view_split(argv);
	if(fork() == 0)
		execve(path,argv, NULL);
    wait(&status);
	
}

void builtin_handler(t_shell *shell, char **argv)
{
    //int		status;
	int 	argc;
	char	*path;
	int		token;

	token = str_token(*argv);
    if(!argv || !*argv || token == -1)
        return ;
	path = builtin_path(*argv);
	//printf("\n%s\n",path);
	//if(token == t_echo)

	//printf("PAth : %s",path);
	argc = argc_split(argv);
	if(token == t_echo)
		echo_handler(path, argc, argv);
	if(token == t_export)
		export_handler(path, argc, argv);
	if(token == t_env)
	/*
	if(fork() == 0)
		execve(path,argv, NULL);
    wait(&status);
	*/
	free(path);
	path = NULL;

}