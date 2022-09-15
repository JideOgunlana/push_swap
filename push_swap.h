#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

// Defining structs for queue structure and node the queue uses
typedef struct s_queue_node
{
    int             item;
    struct s_queue_node   *next;
}               t_queue_node;

typedef struct s_queue
{
    int     size;
    t_queue_node  *node;
    t_queue_node  *front;
    t_queue_node  *back;
    t_queue_node  *before_back;
}               t_queue;

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
			                stack B                                 
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
			stack (A) implemented with a queue      
====================================================================
*/
void			create_queue(t_queue *s);
t_queue_node	*new_node(t_queue *s, int new_item);
void			enqueue(t_queue *s, int val);
t_queue_node	*dequeue(t_queue *s);
void			display(t_queue *s);

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

# endif