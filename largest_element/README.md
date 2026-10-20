# Largest Element in an Array

Given a nonempty integer array `nums`, return the **value** of its largest
element. Duplicate and negative elements are supported.

## Files

- `largest_element.c`: Complete runnable C program.
- `largest_element.cpp`: Complete runnable C++ program.

## Constraints

- `1 <= nums.length <= 100000` (10^5).
- `-10000 <= nums[i] <= 10000` (from -10^4 to 10^4).
- The array may contain duplicates and does not need to be sorted.

## Approach: one linear scan

1. Initialize `largest` to the first element, `nums[0]`.
2. Start at index `1` and compare each remaining element with `largest`.
3. If the current element is greater, update `largest`.
4. Return `largest` after checking the entire array.

After each comparison, `largest` holds the greatest value seen so far. Once
every element has been examined, it is the maximum of the complete array.

Initializing from `nums[0]` handles all-negative arrays correctly. For example,
`[-8, -3, -12]` returns `-3`; initializing to `0` would give an incorrect answer.
A single-element array returns that element without any comparisons.

For `[3, 3, 6, 1]`, `largest` starts at `3`, stays `3` for the next element,
becomes `6`, and stays `6` for the last element. The result is `6`.

## Time complexity

Let `n` be the number of elements.

| Case | Time | Reason |
| --- | --- | --- |
| Best | O(n) | The algorithm checks every remaining element even when the first is the largest. |
| Average | O(n) | Each of the remaining elements is checked once. |
| Worst | O(n) | Each of the remaining elements is checked once. |

The function performs exactly `n - 1` element comparisons. Reading the input
also takes O(n) time, so the complete program takes O(n) time.

## Space complexity

- **Algorithm auxiliary space: O(1).** The function uses a maximum value and
  a loop index. It neither copies the array nor uses recursion. The C version
  receives an array pointer; the C++ version receives a constant reference.
- **Complete program space: O(n).** The C program stores the input in an array
  allocated with `malloc`; the C++ program uses a `std::vector<int>`. The C
  program frees its array, and the C++ vector releases its storage automatically.

The functions require a nonempty array, as guaranteed by the problem. Each
program checks the element count and values against the stated constraints.

## Compile and run

From the workspace folder:

```sh
cd DSA/largest_element
cc -std=c11 -Wall -Wextra -Werror -pedantic largest_element.c -o largest_element_c
c++ -std=c++17 -Wall -Wextra -Werror -pedantic largest_element.cpp -o largest_element_cpp
```

Input consists of the element count, followed by that many integers. Spaces
and newlines both separate values. No target value is needed.

Example input:

```text
4
3 3 6 1
```

Run either program:

```sh
printf '4\n3 3 6 1\n' | ./largest_element_c
printf '4\n3 3 6 1\n' | ./largest_element_cpp
```

Both print:

```text
6
```

The function returns the largest value, and `main` prints it. A successful
program run exits with status `0`. Invalid or incomplete input produces an
error message and a nonzero exit status.

## Examples and edge cases

| Array | Expected output |
| --- | --- |
| `[3, 3, 6, 1]` | `6` |
| `[3, 3, 0, 99, -40]` | `99` |
| `[-8, -3, -12]` | `-3` |
| `[-10000]` | `-10000` |
| `[0, 0, 0]` | `0` |
| `[10000, -10000, 3]` | `10000` |
| `[1, 2, 10000]` | `10000` |
