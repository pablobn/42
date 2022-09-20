/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:37:07 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/24 12:57:10 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_strncpy.c"
#include <string.h>

int main(){
    char destino[] = "w3hy";
    char ejemplo[] = "w3hy";
    char string[] = "abc";
    ft_strncpy(destino,string,4);
    strncpy(ejemplo,string,4);
    
    printf("%s\n",destino);
    printf("%s\n",ejemplo);
}
