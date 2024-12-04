<div align="center">
<h1>42 - Push Swap</h1>
<!-- <img src="textures/screenshots/main.gif" alt="Main GIF" width="650" /> -->

</br>
</br>

<strong>Parce que Swap_push, c’est moins naturel</strong>

<p>Push Swap DESCRIPTION 🌟<p>
<p>A sorting algorithm project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.</p>

</br>

<p><a href="https://github.com/MathysCogne/42_push_swap/blob/main/subject/fr.subject.pdf"><strong>Subject</strong></a></p>

</div>

## Features

- Implementation of a hybrid sorting algorithm combining Block Sort, Quick Sort, and Selection Sort concepts
- Efficient sorting for both small and large datasets
- Optimized number of operations based on input size
- Handles various edge cases and input validations
- Bonus checker program to verify sorting operations

## Algorithm Overview

The sorting implementation uses a hybrid approach split into two main phases:

### Phase 1: Block Sort with Quick Sort Inspiration
- Divides the input into optimal-sized segments based on total size:
  - 13 elements for stacks ≤ 100
  - 20 elements for stacks ≤ 500
  - 29 elements for larger stacks
- Uses pivot-based sorting within segments
- Elements are distributed between stacks A and B:
  - Elements < pivot go to bottom of B
  - Elements > pivot stay at top of B
- Creates a rough pre-sort in stack B

### Phase 2: Modified Selection Sort
- Finds maximum values in stack B
- Uses optimal rotation direction to bring max elements to top
- Pushes sorted elements back to stack A
- Includes adjacent element optimization
- Results in a fully sorted stack A

## Sorting Process Example

Let's sort this sequence: [12 4 53 21 96 7 45 2]

### Initial State:
Stack A: [12 4 53 21 96 7 45 2]
Stack B: []

### Phase 1: Block Segmentation (segment size = 13)
1. Calculate pivot (96 + 2) / 2 = 49

First Pass:
Initial pivot = (96 + 2) / 2 = 49
Step 1 - Push elements < 49 to B: 
A: [96 53] ← Elements > pivot stay 
B: [2 7 4 12 21 45] ← Elements < pivot, bottom first

Step 2 - Optimize B position: 
A: [96 53] 
B: [45 21 12 4 7 2] ← Pre-sorted in descending order

### Phase 2: Selection Sort Back

Step 1: Find max (45) in B 
A: [96 53] → [96 53 45] 
B: [45 21 12 4 7 2] → [21 12 4 7 2]

Step 2: Continue with 21 
A: [96 53 45] → [96 53 45 21] 
B: [21 12 4 7 2] → [12 4 7 2]

Final Steps: 
A: [96 53 45 21 12 7 4 2] → [2 4 7 12 21 45 53 96] 
B: [] → []

## About The Project

Push_swap is a 42 School algorithm project that challenges us to sort a set of integers using two stacks and a limited set of operations, with the goal of using the minimum number of moves possible.

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

### Performance Requirements

The program must achieve these operation counts:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

## Usage

```bash
# Clone repository
git clone https://github.com/MathysCogne/42_push_swap.git
cd 42_push_swap

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

</br>

## Disclaimer
> At 42 School, most projects must comply with the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).