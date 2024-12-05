<div align="center">
<h1>42 - Push Swap</h1>
<img src="subject/cover.png" alt="Main GIF" width="650" />

</br>
</br>

<strong>Because Swap Push, is less natural</strong>

<p>A sorting algorithm project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.</p>

</br>

<p><a href="https://github.com/MathysCogne/42_push_swap/blob/main/subject/fr.subject.pdf"><strong>Subject</strong></a></p>

</div>

## About The Project

Push_swap is a 42 School algorithm project that challenges us to sort a set of integers using two stacks and a limited set of operations, with the goal of using the minimum number of moves possible.

- Bonus checker program to verify sorting operations

### Available Operations

- `sa` : swap a - swap the first 2 elements at the top of stack a
- `sb` : swap b - swap the first 2 elements at the top of stack b
- `ss` : sa and sb at the same time

- `pa` : push a - take the first element at the top of b and put it at the top of a
- `pb` : push b - take the first element at the top of a and put it at the top of b

- `ra` : rotate a - shift up all elements of stack a by 1
- `rb` : rotate b - shift up all elements of stack b by 1
- `rr` : ra and rb at the same time

- `rra` : reverse rotate a - shift down all elements of stack a by 1
- `rrb` : reverse rotate b - shift down all elements of stack b by 1
- `rrr` : rra and rrb at the same time

### Performance

The program must achieve these operation counts:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

## Algorithm Overview

Implementation of a hybrid sorting algorithm combining Block Sort, Quick Sort, and Selection Sort concepts.

The sorting implementation uses a hybrid approach split into two main phases:

<img src="subject/joke.webp" alt="Main GIF" width="500" />

### Phase 1: Block Sort with Quick Sort Inspiration
- Divides the input into optimal-sized segments based on total size:
  - 13 elements for stacks ≤ 100
  - 20 elements for stacks ≤ 500
  - 29 elements for larger stacks
- Uses pivot-based sorting within segments
- Elements are distributed between stacks A and B:
  - Elements < pivot go to the bottom of B
  - Elements > pivot stay at the top of B
- Creates a rough pre-sort in stack B

### Phase 2: Modified Selection Sort
- Finds maximum values in stack B
- Uses optimal rotation direction to bring max elements to the top
- Pushes sorted elements back to stack A
- Includes adjacent element optimization
- Results in a fully sorted stack A

## Sorting Process Example

Let's sort this sequence: [12, 4, 53, 21, 7, 45]

### Initial State:
Stack A: [12, 4, 53, 21, 7, 45]
Stack B: []

### Phase 1: Push to B with Rotations

1. **Push elements to B**:
   - Push 12 and 4 to B.
   - Rotate B to keep smaller elements at the bottom.
   - Continue pushing 53, 21, 7, and 45 to B, rotating as needed to maintain order.

   **State**:
   - A: []
   - B: [53, 21, 7, 45, 12, 4]

### Phase 2: Push Back to A with Optimizations

2. **Push elements back to A**:
   - Push the largest element from B to A.
   - Reverse rotate B to bring the next largest element to the top.
   - Continue pushing elements from B to A, optimizing rotations to minimize moves.

   **Final State**:
   - A: [4, 7, 12, 21, 45, 53]
   - B: []

### Visual Summary:

1. Initial:
   - A: [12, 4, 53, 21, 7, 45]
   - B: []

2. After pushing to B:
   - A: []
   - B: [53, 21, 7, 45, 12, 4]

3. After pushing back to A:
   - A: [4, 7, 12, 21, 45, 53]
   - B: []

## Usage

```bash
# Compile
make

# Run with numbers
./push_swap 4 67 3 87 23

# Test with random numbers
ARG=$(shuf -i 0-100 -n 100 | tr "\n" " "); ./push_swap $ARG

# Count operations
./push_swap 4 67 3 87 23 | wc -l

# Checker (bonus)
make bonus
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

</br>

## Disclaimer
> At 42 School, most projects must comply with the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).