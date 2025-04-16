/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Imput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:46 by basile            #+#    #+#             */
/*   Updated: 2025/04/16 14:54:57 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int handle_imput(int keycode, t_mlx *data)
{
    ft_printf("hello from Keyhook%i,\n", keycode);

    
    if (keycode == 99)
        kill_win(data);

    if (keycode == 122)
        
    return (0);
}



