# PUSH SWAP

## Summary
### Data Sorting using two stacks a and b
> *This project focuses on sorting data efficiently on a stack using a limited set of instructions. The main objective is to achieve the lowest possible number of push_swap actions while manipulating various algorithms. The project requires careful consideration and selection of the most appropriate solution out of several possibilities to optimize the data sorting process.*

<br>

```console
Init stack a and b =>

4
2
1
3
- -
a b

--------
Execute operation ra =>

2
1
3
4
- -
a b

--------
Execute operation pb =>

1
3
4 2
- -
a b

---------
Execute operation pb =>

3 1
4 2
- -
a b

--------
Execute operation sb =>

3 2
4 1
- -
a b

--------
Execute operation pa =>

2
3 
4 1
- -
a b

--------
Execute operation pa =>

1
2
3 
4 
- -
a b
```

<br/>

## To Learn

- Sorting / Searching Algorithms

<br/>

## Tasks include

1. Implementing a program that sorts an array of integers using the least amount of moves with push_swap operations.
2. Implementing a checker program that verifies the operations performed to sort an array of integers using push_swap operations is valid.

<br/>

## Push_swap Operations

Here are list of operations push_swap can use:

- sa (swap a): Swaps the first 2 elements at the top of stack a. Does nothing if there is only one or no elements.
- sb (swap b): Swaps the first 2 elements at the top of stack b. Does nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Takes the first element at the top of b and puts it at the top of a. Does nothing if b is empty.
- pb (push b): Takes the first element at the top of a and puts it at the top of b. Does nothing if a is empty.
- ra (rotate a): Shifts up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shifts up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shifts down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shifts down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

<br/>

## Usage
You can compile and run the program by using these commands
```console
make; ./push_swap 3 2 1;
```

<br/>

### Using the checker
``` console
make;
ARG="3 2 1"; ./push_swap $ARG | ./bonus/checker $ARG;
```