/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:57:51 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/20 17:59:56 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_is_lowercase.c"
#include <stdio.h>
 
int main(){
    char *str = "hol34a";
    printf("%d",ft_str_is_lowercase(str));
}
