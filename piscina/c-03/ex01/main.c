/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:59:23 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/29 20:29:39 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strncmp.c"

int main()
{
    char *primera = "sef";
    char *segunda = "se";
    printf("%d\n",strncmp(primera,segunda,3));
    printf("%d",ft_strncmp(primera,segunda,3));
}