/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:27:02 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/25 18:41:29 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strlcat.c"

int main()
{
    char primera[] = "e";
    char segunda[] = "sf";
    
    printf("%lu\n",strlcat(primera,segunda,3));
    printf("%u",ft_strlcat(primera,segunda,8));
}