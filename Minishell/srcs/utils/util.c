/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:18:23 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/01 19:36:26 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    printshell()
{
    printf("▖  ▖▄▖▖ ▖▄▖▄▖▖▖▄▖▖ ▖ \n"
            "▛▖▞▌▐ ▛▖▌▐ ▚ ▙▌▙▖▌ ▌ \n"
            "▌▝ ▌▟▖▌▝▌▟▖▄▌▌▌▙▖▙▖▙▖\n\n");
}

void    mgetcwd(char *buffer, size_t size)
{
    if(!getcwd(buffer, size))
        perror("getcwd FAILED");
}