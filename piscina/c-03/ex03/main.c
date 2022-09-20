/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:44:13 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/25 16:30:36 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strncat.c"

int main()
{
    char primera[] = "hola";
    char segunda[] = "adios";
    
    printf("%s",ft_strncat(primera,segunda,3));
}