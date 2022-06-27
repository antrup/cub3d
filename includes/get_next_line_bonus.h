/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:19:24 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/27 00:23:29 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 64

typedef struct	s_fdparam
{
	char				*buffer;
	int					i[2];
	int					eofc;
	int					fd;
	struct s_fdparam	*next;
}				t_fdparam;
int				get_next_line(int fd, char **line);
int				ft_reader(t_fdparam *config, char **line, int fd,
							t_fdparam *root);
int				ft_resize(char **line, int j, t_fdparam *config,
							t_fdparam *root);
char			*ft_realloc(int size, char **line);
int				ft_initialize(int fd, t_fdparam *config, char **line);
t_fdparam		*ft_initconfig(int fd, t_fdparam **root);
t_fdparam		*ft_findconfig(int	fd, t_fdparam *root);
int				ft_clean(t_fdparam **config, t_fdparam **root);
int				ft_loadbuffer(int fd, t_fdparam *config, int *i);
#endif
