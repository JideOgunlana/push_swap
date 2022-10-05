#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define LIMIT 45
# define LIMIT_100 30
# include <stdio.h>
# include <stdlib.h>
# include "./includes/libft/libft.h"
# include <stdint.h>

/*
====================================================================
   Defining structs for queue structure and node the queue uses
====================================================================
*/

typedef struct s_queue_node
{
    int             item;
    struct s_queue_node   *next;
}               t_queue_node;

typedef struct s_queue
{
	int				size;
	int				least_item;
	t_queue_node	*node;
	t_queue_node	*front;
	t_queue_node	*back;
	t_queue_node	*before_back;
}               t_queue;

/*
====================================================================
   Defining structs for stack structure and node the stack uses
====================================================================
*/

typedef struct s_stack_node
{
	int	item;
	struct s_stack_node *next;
}			t_stack_node;

typedef struct s_stack
{
	int				size;
	t_stack_node	*s_nodes;
}				t_stack;

/*
====================================================================
			Temp Chunks used by Stack A
====================================================================
*/
typedef struct s_temp_chunks
{
	int	r;
	int	rr;
	int	total_r;
	int	total_rr;
	int	first;
	int	last;
}				t_temp_chunks;

/*
====================================================================
     Struct helps create chunks to move froom A to B
====================================================================
*/
typedef struct s_chunk_helper
{
	t_queue_node	*head_a;
	int				head_a_moves;
	int				hold_chunk_size;
	int				i;
}				t_chunk_helper;

/*
====================================================================
			Chunks sent to Stack B
====================================================================
*/
typedef struct s_chunks
{
	int	key;
	int	data;
}				t_chunks;

/*
====================================================================
			struct to help sort chunks in B to A
====================================================================
*/
typedef struct s_sort_chunk
{
	t_stack_node	*head_b;
	int				head_b_moves;
	int				chunk_size;
	int				median;
	int				*descending_arr;
	int				rotations;
	int				push_to_a_state;
	int				items_at_top_count;
	int				search_index;
	int 			search_val;
	int				search_at_top;
	int				total_chunks;
	int				temp_items_at_top;
	t_stack_node	*temp_head_b;
}				t_sort_chunk;

/*
====================================================================
			stack (A) implemented with a queue DS
====================================================================
*/
void			create_queue(t_queue *s);
t_queue_node	*new_node(t_queue *s, int new_item);
void			enqueue(t_queue *s, int val);
t_queue_node	*dequeue(t_queue *s);
void			display(t_queue *s);

/*
====================================================================
			Stack (B) implemented with a stack DS                                 
====================================================================
*/
void			create_stack(t_stack *s);
t_stack_node	*new_stack_node(int val);
int				is_empty(t_stack *s);
void			push(t_stack *s, int new_item);
t_stack_node	*pop(t_stack *s);
void			print_stack(t_stack *s);
void			peek(t_stack *);

/*
====================================================================
			push swap operations on stack A
====================================================================
*/
void	swap_a(t_queue *stack_a);
void	rotate_a(t_queue *stack_a);
void	rrotate_a(t_queue *stack_a);
void	push_b(t_queue *stack_a, t_stack *stack_b);

/*
====================================================================
			push swap operations on stack B
====================================================================
*/
void	rotate_b(t_stack *stack_b);
void	rrotate_b(t_stack *stack_b);
void	swap_b(t_stack *stack_b);
void	push_a(t_stack *stack_b, t_queue *stack_a);

/*
====================================================================
			push swap operations on both stacks
====================================================================
*/
void	swap_a_b(t_queue *stack_a, t_stack *stack_b);
void	rotate_a_b(t_queue *stack_a, t_stack *stack_b);
void	reverse_a_b(t_queue *stack_a, t_stack *stack_b);

/*
====================================================================
			Error checking functions
====================================================================
*/
int	check_passed_vals(char *str);
int	check_duplicates(t_queue *stack_a);

/*
====================================================================
			push swap sorting
====================================================================
*/
int	insertion_sort(t_queue	*stack_a);
int	insertion_sort_on_b(t_stack	*stack_b, int arr_size);
int	is_ordered(t_queue *stack_a);
int is_chunk_ordered(t_stack *stack_b, int chunk_size);
int	*gen_descending_chunk(t_stack *stack_b, int arr_size);
int	*gen_ascending_chunk(t_queue *stack_a);

/*
====================================================================
			push swap sorting
====================================================================
*/
void	stack_b_has_two(t_queue *stack_a, t_stack *stack_b);
void	stack_b_has_three(t_queue *stack_a, t_stack *stack_b);
void	stack_b_has_three_chunks(t_queue *stack_a, t_stack *stack_b);

void	move_chunks_to_b(t_queue *stack_a, t_stack *stack_b, int chunk_size);
void	move_chunks_to_a(t_stack *stack_b, t_queue *stack_a, t_chunks **chunks, int total_chunks);

/*
====================================================================
			functions to help create chunks
====================================================================
*/
t_chunks	*get_chunk_set(t_queue *stack_a, int set_count);

# endif