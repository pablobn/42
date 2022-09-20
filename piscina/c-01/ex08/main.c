/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:16:09 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/30 18:17:53 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort_int_tab.c"

int main()
{
    int tab[6] = {3,56,-2,3,6,7};
    ft_sort_int_tab(tab,6);
    printf("%d\n",tab[0]);
    printf("%d\n",tab[1]);
    printf("%d\n",tab[2]);
    printf("%d\n",tab[3]);
    printf("%d\n",tab[4]);
    printf("%d\n",tab[5]);
}