/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:59:23 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/26 13:26:14 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strcmp.c"

int main()
{
    char *primera = "g";
    char *segunda = "";
    printf("%d\n",strcmp(primera,segunda));
    printf("%d",ft_strcmp(primera,segunda));
}