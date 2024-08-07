/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-25 19:38:17 by rcabrero          #+#    #+#             */
/*   Updated: 2024-06-25 19:38:17 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "../minilibx-linux/mlx.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

//TODO: REVISAR QUE  DATOS SE USAN Y CUALES NO.......
//TODO: REVISAR QUE CONTIENE CADA COSA...
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	min_real;
	float	max_real;
	float	min_imag;
	float	max_imag;
	float	c_real;
	float	c_imag;
	t_image	img;
	int		zoom;
	float	move_x;
	float	move_y;
	float	step;
	int		is_initialized;
	int		color;
	int		max_iterations;
	int		fractal_type;
}				t_mlx_data;

typedef struct s_complex
{
	float	real;
	float	imag;
}	t_complex;

int		key_press(int keycode, t_mlx_data *mlx);
int		handle_options_input(int keycode, t_mlx_data *data);
int		zoom(t_mlx_data *mlx);
int		zoom_out(t_mlx_data *mlx);
int		move_up(t_mlx_data *mlx, float step);
int		move_down(t_mlx_data *mlx, float step);
int		move_rigth(t_mlx_data *mlx, float step);
int		move_left(t_mlx_data *mlx, float step);
int		increase_iterations(t_mlx_data *mlx);
int		decrease_iterations(t_mlx_data *mlx);
void	draw_mandelbrot(t_mlx_data *mlx, int first_time);
int		get_color(t_mlx_data *mlx, int color_scheme, int iteration);
int		mouse_press(int button, int x, int y, t_mlx_data *mlx);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
float	ft_atof(const char *str);
int		ft_isdigit(int c);
int		is_validated_number(const char *str);


//PARAMETERS INSTRUCTION ERROR
void	parameters_instructions(void);
//LEAKS CONTROLLER
void	leaks(void);
//INITIALIZERS
int		initialize_complex(t_mlx_data *mlx, char **argv);
int		initialize_fractol(t_mlx_data *mlx, int type, char **argv);
void	initialize_mlx_struct(t_mlx_data *mlx, int type);
int		initialize_mlx(t_mlx_data *mlx);
//CHECKERS
int		check_fractol_type(int argc, char **argv);
//FRACTOL CONTROLLER
int		fractol_controller(int type, char **argv);
void	handle_fractol(t_mlx_data *mlx);
int		close_window(t_mlx_data *mlx);
void	set_hooks(t_mlx_data *mlx);
void	cleanup_mlx(t_mlx_data *mlx);
//FRACTOL CALCULATOR
int		iterator_mandelbrot(t_complex c, int max_iterations);
int		iterator_julia(t_complex z, int max_iterations, float c_real, float c_imag);
void	calculate_y(t_mlx_data *mlx, int first_time);
void	calculate_x(t_mlx_data *mlx, int y,const float c_imag);
void	put_pixel_to_image(t_image *image, int x, int y, int color);
//COLOR
int		change_color_scheme(t_mlx_data *mlx, int new_color_scheme);

#endif
