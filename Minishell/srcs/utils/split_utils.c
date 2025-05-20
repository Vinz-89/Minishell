/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:40:12 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:54 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell2.h"

void view_split(char **argv)
{
	int i;

	if(!argv || !*argv)
		return ;
	i = 0;
	while(argv[i])
	{
		printf("%s\n",argv[i++]);
		if(!argv[i])
			printf("(NULL)\n");
	}
}

void free_split(char **split)
{
	int i;

    if(!split)
        return;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

char *free_handler(char **split)
{
    
}

int size_split(char **split)
{
    int i;

    i = 0;
    while(split[i])
        i++;
    return(i);
}

char **first_split(char **split, char *str)
{
   char **new_split;

    new_split = malloc(sizeof(char *) * (2));
    if(!new_split)
    {
        perror("Probpeme first_split"); //Vraiment gérer
        return(NULL);
    }

    new_split[0] = str;
    new_split[1] = NULL;
    
    return (new_split);
}

char **new_split(char **split, char *str)
{
    int i;
    int size;
    char **new_split;

    if(!split)
    {
        new_split = malloc(sizeof(char *) * 2);
        if(!new_split)
            return(NULL);
        new_split[0] = ft_strdup(str);
        new_split[1] = NULL;
        return(new_split);
    }

    size = size_split(split); // compte les char * 
    new_split = malloc(sizeof(char *) * (size + 2));
    if(!new_split)
        return (NULL);

    i = 0;
    while(i < size)
    {
        new_split[i] = ft_strdup(split[i]); // ou juste recupérer les pointeurs
        i++;
    }
    new_split[i] = ft_strdup(str); //faire gaffe déja malloc
    new_split[i + 1] = NULL;

    free_split(split);
    return(new_split);
}
