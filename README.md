# my_stacksort
* Sort with two stacks using limited operations.
* A program will receive a list of integers and return operations used.

## Available operations
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

## Algorithm
Used the concept of **Quick Sort**

### Step 1
* If there has more than three numbers in *stack A*, find a pivot and **push** numbers to *stack B* if a number <= a pivot.
* Save a count of numbers that are pushed to *stack B*.
* Repeat **Step 1** until numbers in *stack A* are below three.
* Use proper sort operation to *stack A*.

By completing above step, *stack A* will be fully sorted.

### Step 2
* If recently saved count of numbers are more than three, find a pivot from those numbers in *stack B* and **push** to *stack A* if a number > a pivot.
* Else, **push** those numbers in *stack B* to *stack A*.
* Do **Step 1**
* Repeat **Step 2** until *stack B* is empty.

By completing above step, *stack A* will be fully sorted and *stack B* will be empty.

### Special
* To reduce operations, if *stack A* only has three numbers, use simpler three number operations. Otherwise, use multiple **rra** not to affect sorted numbers in the bottom of *stack A*.
* If *stack A* only has five numbers, **push** numbers to *stack B* if a number < a pivot.

## Result
* The worst case of 100 random integers returns **823** operations.
* The worst case of 500 random integers returns **5715** operations.
