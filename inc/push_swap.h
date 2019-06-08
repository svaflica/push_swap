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
}					t_pair_stack;

t_pair_stack		*ft_pair_stack_new(void);

void				ft_comm_go(t_stack **sol);

t_stack				*ft_stack_new(size_t size);
int					ft_stack_push(t_stack **beg, t_stack *s);
int					ft_stack_push_b(t_stack **beg, t_stack *s);
int					ft_stack_pop(t_stack **s);
void				ft_stack_del(t_stack **s);
void				ft_stack_print(t_stack *a);
int					ft_is_in_stack(t_stack *a, int num);

int					ft_is_sorted(t_stack **a);

void				ft_sort(t_pair_stack *pe, double med, t_stack **sol);
void				ft_bitch_sort(t_pair_stack *pe, int max, int min,
									double med, t_stack **sol);

int					checker(t_stack *a, t_stack *b, char **str);
int					ft_is_arg_valid(char **arg);

void				s(t_stack *a);
void				ss(t_stack *a, t_stack *b);
void				p(t_stack **a, t_stack **b);
void				r(t_stack **a);
void				rr(t_stack *a, t_stack *b);
void				rr_f(t_stack **a);
void				rrr(t_stack *a, t_stack *b);

double				ft_find_median(char **v, int len);
int					ft_find_min(t_stack *a);
int					ft_find_max(t_stack *a);

#endif
