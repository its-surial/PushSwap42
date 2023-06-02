/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkumar <surkumar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:29:01 by lgollong          #+#    #+#             */
/*   Updated: 2023/06/02 17:06:34 by surkumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_values
{
	int				value;
	int				index;
	struct s_values	*next;
}	t_values;

void	error(void);
// libft //
int		ft_atoi(const char *strn);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
// parse //
void	clear_data(t_values **stack_a, t_values **stack_b);
void	get_data(t_values **mystack, int argc, char **argv);
void	push_to_stack(t_values **mystack, int value);
void	check_data(t_values *mystack);
int		contains_char(char *str);
int		arg_len(char **strs);
int		space(char *str);
// operations //
void	swap(t_values **mystack, char s);
void	s_both(t_values **stack_a, t_values **stack_b);
void	swap_it(t_values **mystack);
void	push(t_values **src, t_values **dest, char s);
void	push_it(t_values **src, t_values **dest);
void	rotate(t_values **mystack, char s);
void	r_both(t_values **stack_a, t_values **stack_b);
void	rotate_it(t_values **mystack);
void	reverse_rotate(t_values **mystack, char s);
void	rr_both(t_values **stack_a, t_values **stack_b);
void	reverse_rotate_it(t_values **mystack);
// sorting //
void	sort_stack(t_values **stack_a, t_values **stack_b);
void	sort_of_3(t_values **stack_a);
void	sort_of_5(t_values **stack_a, t_values **stack_b);
void	big_sort(t_values **stack_a, t_values **stack_b);
void	last_chunk(t_values **stack_a, t_values **stack_b);
void	p_m_chunks(t_values **stack_a, t_values **stack_b, int s_len, int len);
void	p_s_chunks(t_values **stack_a, t_values **stack_b, int s_len, int len);
/* utils */
int		top_stack(t_values *mystack);
int		bottom_stack(t_values *mystack);
int		get_index(t_values *mystack, int count);
int		sorted(t_values *mystack);
int		biggest_index(t_values *mystack);
int		lowest_index(t_values *mystack);
int		stack_len(t_values *mystack);
int		get_position(t_values *mystack, int value);
void	set_index(t_values *mystack);
/* checker */
// void	get_operation(t_values *stack_a, t_values *stack_b);
char	*get_next_line(int fd);

#endif
