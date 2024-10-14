/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 08:46:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/10/14 09:18:24 by adakheel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	printf("\nCUB3D Controls:\n");
	printf("\nW: move forward\n");
	printf("S: move backward\n");
	printf("A: strafe left\n");
	printf("D: strafe right\n");
	printf("<: rotate left\n");
	printf(">: rotate right\n");
	printf("sin(0.5) = %f\n", sin(0.5));
    printf("cos(0.5) = %f\n", cos(0.5));
    printf("tan(0.5) = %f\n", tan(0.5));
    printf("asin(0.5) = %f\n", asin(0.5));
    printf("acos(0.5) = %f\n", acos(0.5));
    printf("atan(1.0) = %f\n", atan(1.0));
    printf("atan2(1.0, 1.0) = %f\n", atan2(1.0, 1.0));
	printf("abbas was here\n");
	return (0);
}
