/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:00:22 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/25 18:35:11 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strcat.c"

int main()
{
    char primera[] = "adios";
    char segunda[] = "h";
    
    printf("%s",ft_strcat(primera,segunda));
}