/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:00:45 by atruphem          #+#    #+#             */
/*   Updated: 2021/02/24 00:01:32 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_X_MAX 2560
# define SCREEN_Y_MAX 1440

# ifdef MACOS
#  define KEY_L_ARROW 124
#  define KEY_R_ARROW 123
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_ESC 53
#  define EXIT_EVENT 17
#  define MACOSX 1

int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				mlx_destroy_display(void *mlx_ptr);

# else
#  define KEY_L_ARROW 65363
#  define KEY_R_ARROW 65361
#  define KEY_W 1219
#  define KEY_S 1220
#  define KEY_A 1217
#  define KEY_D 1212
#  define KEY_ESC 65307
#  define EXIT_EVENT 33
#  define MACOSX 0
# endif

typedef struct	s_bmphdata
{
	char	hfield[2];
	int		fsize;
	int		lol;
	int		offset;
	int		hsize;
	int		width;
	int		height;
	short	colorp;
	short	bpp;
	int		compression;
	int		isize;
	int		hppm;
	int		vppm;
	int		nbcolors;
	int		impcolors;
}				t_bmphdata;

typedef	struct	s_sprt
{
	double			x;
	double			y;
	double			sprtx;
	double			sprty;
	double			sprtdist;
	double			transformx;
	double			transformy;
	int				screenx;
	int				height;
	int				width;
	int				startx;
	int				starty;
	int				stopx;
	int				stopy;
	struct s_sprt	*next;
}				t_sprt;

typedef struct	s_cubpar
{
	int		sizex;
	int		sizey;
	char	*not;
	char	*sot;
	char	*wet;
	char	*eat;
	char	*st;
	int		c;
	int		f;
	int		sizemaxx;
	int		sizemaxy;
	int		line;
	int		bmp;
}				t_cubpar;

typedef struct	s_txtdat
{
	void	*ptr;
	char	*memptr;
	int		width;
	int		height;
	int		bpp;
	int		sizeline;
	int		endian;
	int		txtx;
	int		txty;
	double	step;
	double	txpos;
}				t_txtdat;

typedef struct	s_raypar
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_raypar;

typedef	struct	s_raydat
{
	double	screenx;
	double	dirx;
	double	diry;
	double	tox;
	double	toy;
	double	nextx;
	double	nexty;
	int		mapx;
	int		mapy;
	int		wall;
	int		whwall;
	int		stepx;
	int		stepy;
	double	disttowall;
	int		printheight;
	int		printstart;
	int		printstop;
	double	wallx;
}				t_raydat;

typedef struct	s_global
{
	void		*id;
	void		*wid;
	t_raypar	*rayp;
	t_raydat	*ray;
	int			**map;
	t_cubpar	*param;
	t_txtdat	**tex;
	t_sprt		*sprt;
	t_txtdat	*img;
}				t_global;

int				ft_get_params(char	*buffer, t_cubpar *param);
int				ft_size_map(char *file);
int				ft_read_map(int ***map, char *buffer, int line);
t_cubpar		*ft_read_cubfile(int ***map, char *file);
int				ft_test_map(int ***map, int line, char ***buffer,
								t_cubpar **param);
int				ft_read_map_error(int code);
int				test_fi(int ***map, int line);
int				test_fo(int ***map, int line);
void			ft_cleaner2(char ***buffer);
int				ft_isspace(int c);
int				ft_count_line(char *buffer, int bsize);
void			ft_clean_map(int ***map, int line);
int				size_line(int ***map, int y);
int				ft_cleaner(t_cubpar **param, char ***buffer, int fd,
							int ***map);
void			ft_cleaner2(char ***buffer);
t_txtdat		**load_texture(t_global *glob);
void			*ft_cleaner4(t_global	*glob);
void			*ft_cleaner3(t_global	*glob, t_txtdat ***tex);
t_raypar		*read_player_pos(int **map, t_global *glob);
int				deal_key(int key, t_global *glob);
void			move_n(t_global *glob);
void			move_s(t_global *glob);
void			raycaster_loop(t_global *glob);
int				resize_screen(t_cubpar *param, void *id);
void			ft_print_screen(t_global *glob);
void			*ft_cleaner5(t_global	*glob);
void			ft_get_color(char *color, char value, int index);
void			ft_print_sprites(t_global *glob);
void			manage_sprites(t_global *glob);
void			init_sprite(t_global *glob);
void			class_sprite(t_global *glob);
int				error_f_c(int ind);
int				error_dp();
void			ft_print_wall(t_global *glob, int *x, int *y);
int				smap_create(t_global *glob);
int				the_end(t_global *glob);
int				put_img(t_global *glob);
void			save_as_bmp(t_global *glob);
int				the_end2(t_global *glob);
int				the_end(t_global *glob);
int				cleaner12(t_global *glob);
int				cleaner10(t_global *glob);
int				cleaner11(t_global *glob);
void			free_sprt(t_global *glob);
int				error_gen(char *msg);
void			free_txts_sp(t_global *glob, t_txtdat **tex);
int				set_img(t_global *glob);
void			free_txts(t_global *glob);
#endif
