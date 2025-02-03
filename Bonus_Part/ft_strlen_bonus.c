/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:38:42 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 15:42:32 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int ft_strlen(const char *str)
{
    int count;
    
    count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}