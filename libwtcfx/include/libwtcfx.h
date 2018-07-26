/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libwtcfx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:47:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 20:30:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBWTCFX_H
# define LIBWTCFX_H

# include <math.h>
# include <mlx.h>
# include <stddef.h>
# include <time.h>
# include <stdbool.h>
# include <limits.h>
# include "wfx_mac_keys.h"
# include "f_memory.h"
# include "f_cntl.h"
# include "f_math.h"
# include "s_grid.h"

# define MAX_FPS 60

typedef	void*	t_mlx;

t_mlx			wfx_get_mlx(void);

typedef	struct	s_vec2i
{
	int x;
	int y;
}				t_vec2i;

t_vec2i			*vec2i_create();
void			vec2i_init(t_vec2i *v2, int x, int y);
void			*vec2i_copy(t_vec2i *v);
void			vec2i_add(t_vec2i *v1, t_vec2i v2);
void			vec2i_sub(t_vec2i *v1, t_vec2i v2);
void			vec2i_scale(t_vec2i *v1, int scalar);

# define VEC2I(x, y)		((t_vec2i){(int)(x), (int)(y)})
# define VEC2_TO_F(v)		(VEC2((double)v.x, (double)v.y))
# define ADD_VEC2I(v1, v2)	(NEW_VEC2I(v1.x + v2.x, v1.y + v2.y))
# define SUB_VEC2I(v1, v2)	(NEW_VEC2I(v1.x - v2.x, v1.y - v2.y))

typedef struct	s_vec2
{
	double x;
	double y;
}				t_vec2;

t_vec2			*vec2_create();
void			vec2_init(t_vec2 *v, t_vec2 val);
t_vec2			*vec2_copy(t_vec2 v);
void			vec2_add(t_vec2 *v1, t_vec2 v2);
void			vec2_sub(t_vec2 *v1, t_vec2 v2);
void			vec2_scale(t_vec2 *v1, double scalar);
double			vec2_len(t_vec2 v);
t_vec2			vec2_rotate(t_vec2 v, double rad);
t_vec2			vec2_norm(t_vec2 *v);
double			vec2_angle(t_vec2 v);
t_vec2			vec2_at_len(t_vec2 v, double len);

# define VEC2(x, y)			((t_vec2){(double)(x), (double)(y)})
# define VEC2_TO_I(v)		(VEC2I((int)v.x, (int)v.y))
# define ADD_VEC2(v1, v2)	(VEC2(v1.x + v2.x, v1.y + v2.y))
# define SUB_VEC2(v1, v2)	(VEC2(v1.x - v2.x, v1.y - v2.y))
# define LEN_VEC2(v)		(sqrt(v.x * v.x + v.y * v.y))
# define DOT_VEC3(v1, v2)	(v1.x * v2.x + v1.y * v2.y)

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

t_vec3			*vec3_create();
void			vec3_init(t_vec3 *v, t_vec3 val);
t_vec3			*vec3_copy(t_vec3 v);
void			vec3_add(t_vec3 *v1, t_vec3 v2);
void			vec3_sub(t_vec3 *v1, t_vec3 v2);
void			vec3_scale(t_vec3 *v1, double scalar);
void			vec3_norm(t_vec3 *v);
t_vec3			vec3_cross(t_vec3 v1, t_vec3 v2);

# define VEC3(x, y, z)		((t_vec3){(double)(x), (double)(y), (double)(z)})
# define VEC3_TO_I(v)		(VEC3I((int)v.x, (int)v.y))
# define ADD_VEC3(v1, v2)	(VEC3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z))
# define SUB_VEC3(v1, v2)	(VEC3(v1.x - v2.x, v1.y - v2.y, v1.z + v2.z))
# define SCALE_VEC3(v, s)	(VEC3(v.x * s, v.y * s, v.z * s))
# define LEN2_VEC3(v)		(v.x * v.x + v.y * v.y + v.z * v.z)
# define LEN_VEC3(v)		(sqrt(LEN2_VEC3(v)))
# define NORM_VEC3(v)		(SCALE_VEC3((v), 1 / LEN_VEC3(v)))
# define DOT_VEC3(v1, v2)	(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z)

# define MIN_INTERCEPT 0.0001
# define MAX_INTERCEPT 1.0e30

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	double	tmax;
}				t_ray;

# define RAY(s, t)			((t_ray){s, NORM_VEC3(t), })
# define CALC_RAY(r, t)	(ADD_VEC3(r.origin, SCALE_VEC3(r.direction, t)))

typedef	struct	s_image
{
	void	*ptr;
	int		width;
	int		height;
	int		*buffer;
}				t_image;

t_image			*wfx_create_image(void);
void			wfx_init_image(t_image *image, int width, int height);
void			wfx_destroy_image(t_image *image);
void			wfx_image_to_image(t_image *dst, t_image *src, t_vec2i pos);
t_image			*wfx_resize_image_nn(t_image *image, t_vec2i new_size);
t_image			*wfx_xpm_file_to_image(t_mlx mlx, char *path_name);

# define GET_IMAGE_PIXEL(i, x, y)		(i->buffer[(i->width * (y)) + (x)])
# define SET_IMAGE_PIXEL(i, x, y, col)	(GET_IMAGE_PIXEL(i, x, y) = col)

typedef struct	s_state
{
	int		(*loop)(void*);
	int		(*key_down)(int, void*);
	int		(*key_up)(int, void*);
	int		(*mouse_down)(int, int, int, void*);
	int		(*mouse_up)(int, int, int, void*);
	int		(*mouse_move)(int, int, void*);
}				t_state;

t_state			*create_state(void);
void			wfx_init_state(t_state *state);

typedef	struct	s_window
{
	t_mlx			mlx;
	void			*ptr;
	int				width;
	int				height;
	t_image			*front;
	t_image			*back;
	clock_t			last_blit;
	unsigned long	frame_count;
}				t_window;

t_window		*wfx_create_window(void);
void			wfx_init_window(t_window *window, int width, int height,
					char *title);
void			wfx_destroy_window(t_window *window);
void			wfx_blit(t_window *window);
void			wfx_clear_window(t_window *window);

int				wfx_colour_brightness(int color, double scale);

void			wfx_set_pixel(t_window *window, int x, int y, int col);
void			wfx_line(t_window *window, t_vec2i p1, t_vec2i p2, int colour);
void			wfx_rect(t_window *window, t_vec2i p1, t_vec2i p2, int colour);
void			wfx_frect(t_window *window, t_vec2i p1, t_vec2i p2, int colour);
void			wfx_circle(t_window *window, t_vec2i v, int radius, int colour);
void			wfx_fcircle(t_window *window, t_vec2i v, int radius,
					int colour);
void			wfx_grid(t_window *window, t_vec2i origin, t_vec2i grid_size,
					int cell_size);
void			wfx_image_to_window(t_window *window, t_image *image,
					t_vec2i pos);

void			wfx_mouse_press_hook(t_window *window,
					int (*f)(int, int, int, void*), void *param);
void			wfx_mouse_release_hook(t_window *window,
					int (*f)(int, int, int, void*), void *param);
void			wfx_motion_hook(t_window *window, int (*f)(int, int, void*),
					void *param);
void			wfx_key_press_hook(t_window *window,
					int (*f)(int, void*), void *param);
void			wfx_key_release_hook(t_window *window,
					int (*f)(int, void*), void *param);
void			wfx_expose_hook(t_window *window, int (*f)(void*), void *param);
void			wfx_exit_hook(t_window *window, int (*f)(void*), void *param);
void			wfx_loop_hook(t_window *window, int (*f)(void*), void *param);
void			invoke_state(t_window *window, t_state *state, void *param);
void			wfx_start(t_window *window);

#endif
