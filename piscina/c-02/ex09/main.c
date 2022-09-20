/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:25:57 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/24 11:51:54 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_strcapitalize.c"

int main()
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

    ft_strcapitalize(str);
    printf("%s",str);
    
}