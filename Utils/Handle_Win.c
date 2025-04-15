/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_Win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basile <basile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:55:42 by basile            #+#    #+#             */
/*   Updated: 2025/04/15 15:16:38 by basile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_Long.h"

int kill_win(t_mlx_data *data)
{
    mlx_destroy_window(data->mlx_ptr,data->win_ptr);// good mais ne termine pas le program
    free(data->mlx_ptr);
    exit(0);
    return 0;
}