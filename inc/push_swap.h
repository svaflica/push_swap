/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:45:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 18:45:47 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PU_SWA_PUSH_SWAP_H
# define PU_SWA_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../ft_printf/inc/printf.h"
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_pair_stack
{
	t_stack			*a;
	t_stack			*b;
	int				size_a;
	int				size_b;
}					t_pair_stack;

typedef struct		s_w
{
	int				who;
	int				who_a;
	int				where;
}					t_w;

t_pair_stack		*ft_pair_stack_new(void);
int					ft_abs(int a);
t_stack				*thanks_norm(t_pair_stack *pe, t_stack *tmp_b, int *i);
t_stack				*thanks_norm2(t_pair_stack *pe, t_stack *tmp_b, int *i);
int					ft_is_max_or_min(t_pair_stack *pe, t_stack *tmp_b,
									int *who_a);
int					find_in_a(t_pair_stack *pe, t_stack *tmp_b, t_w *tmp);
void				ft_shift(t_pair_stack *pe, t_w *w, t_stack **sol);

void				ft_comm_go(t_stack **sol);

t_stack				*ft_stack_new(size_t size);
int					ft_stack_push(t_stack **beg, t_stack *s);
int					ft_stack_push_b(t_stack **beg, t_stack *s);
int					ft_stack_pop(t_stack **s);
void				ft_stack_del(t_stack **s);
void				ft_stacks_print(t_stack *a, t_stack *b);
int					ft_is_in_stack(t_stack *a, int num);
t_stack				*ft_stack_last(t_stack *a);

int					ft_is_sorted(t_stack **a);
t_stack				*ft_is_srt(t_stack *a);
void				ft_three_sort(t_pair_stack *pe, t_stack *tmp,
									t_stack **sol, int med);
int					ft_is_srt_num(t_stack *a);

void				ft_sort(t_pair_stack *pe, double med, t_stack **sol);
void				ft_bitch_sort(t_pair_stack *pe, t_stack **sol);

int					checker(t_stack *a, t_stack *b, char **str, int deb);
int					ft_is_arg_valid(char **arg);

int					ft_check_readed(char *str);
char				**ft_read(t_pair_stack *p, char *name);

int					ft_is_min(t_pair_stack *pe, t_stack *tmp_b, int *who_a);
int					ft_is_max(t_pair_stack *pe, t_stack *tmp_b, int *who_a);

void				s(t_stack *a);
void				p(t_stack **a, t_stack **b);
void				r(t_stack **a);
void				rr_f(t_stack **a);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				ss(t_stack *a, t_stack *b);

#endif
