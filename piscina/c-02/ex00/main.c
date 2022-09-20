/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:00:40 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/19 11:12:15 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_strcpy.c"

int main(){
    char destino[] = "aresresresresutfuyfuyf";
    char string[] = "hola que tal";
    ft_strcpy(destino,string);
    printf("%s",destino);
}
