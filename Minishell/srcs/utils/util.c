/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:18:23 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/19 13:16:52 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell2.h"

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