/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:57:57 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 21:09:03 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "t_map_attr.h"
# include "t_read.h"

//ft_bsq.c
int		ft_bsq(char *map_file);
void	ft_free_tab(int ***tab);
void	ft_free_chain(t_read *begin);
int		ft_bsq_stdin(void);
//ft_read_map.c
int		ft_parse_first_line(int fd, t_map_attr *attr);
char	*ft_define_map(int fd, t_map_attr *attr);
int		**ft_init_tab(t_map_attr *attr);
int		**ft_convert_strings(char *str, t_map_attr *attr, int **tab, int fd);
int		**ft_convert_map(char *map_file, t_map_attr *attr);
//ft_read_stdin
int		**ft_convert_map_stdin(t_map_attr *attr);
//ft_first_lines.c
t_read	*ft_add_link(char buf_c);
int		ft_first_read(int fd, t_read **begin);
char	*ft_join_chain(t_read *begin, int size);
int		ft_atoi(char *str, int size);
//ft_resolve_map.c
int		map_error(void);
int		ft_check_map_attr(t_map_attr *attr);
int		*ft_resolve_map(int **tab, t_map_attr *attr, char *str);
//ft_compute_tab.c
void	ft_new_sq(t_map_attr *attr, int size_sq, int y_sq, int x_sq);
int		ft_new_value(int **tab, int line, int pos, int *array);
int		*ft_res_first_line(t_map_attr *attr, char *str, int *array);
int		*ft_res_first_col(t_map_attr *attr, int *array, int line, char *str);
int		*ft_res_center(int **tab, t_map_attr *attr, int *array, char *str);
//ft_display.c
int		**ft_insert_square(int **tab, t_map_attr *attr);
void	ft_fill_str(int **tab, t_map_attr *attr, char *str, int line);
int		ft_display(int **tab, t_map_attr *attr);

#endif
