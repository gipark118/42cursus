/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:35:10 by gipark            #+#    #+#             */
/*   Updated: 2021/04/14 18:51:05 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef	struct		s_info
{
	int				pivot;
	int				size_b;
	int				size_a;
	int				flags;
	int				p;
}					t_info;

typedef	struct		s_data
{
	int				max_a;
	int				max_b;
	int				flags_a;
	int				flags_b;
	int				pos_a;
	int				pos_b;
}					t_data;

int					resolve(t_list **list_a, t_info *info);
int					clear_all(t_list *list, t_info *info);
void				short_resolve(t_list **list_a, t_info *info);
int					find_min(t_list *list);
int					find_max(t_list *list, int skip);
int					find_pos(int n, t_list *list);
int					sort_size(t_list *list);
void				clear_list(t_list *list);
void				sa(t_list *list_a, int p);
void				sb(t_list *list_b, int p);
void				ss(t_list *list_a, t_list *list_b, int p);
void				pa(t_list **list_a, t_list **list_b, int p);
void				pb(t_list **list_a, t_list **list_b, int p);
void				ra(t_list **list_a, int p);
void				rb(t_list **list_b, int p);
void				rr(t_list **list_a, t_list **list_b, int p);
void				rra(t_list **list_a, int p);
void				rrb(t_list **list_b, int p);
void				rrr(t_list **list_a, t_list **list_b, int p);
int					is_sort(t_list *list_a);
int					sort_median(t_list *list_b, int size);
void				add_list(t_list **list, int n);
t_list				*init_list(int ac, char **av);

#endif
