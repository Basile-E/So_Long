/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:58:00 by baecoliv          #+#    #+#             */
/*   Updated: 2024/09/07 15:58:02 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argument)
{
	return (argument >= 32 && argument <= 126);
}
