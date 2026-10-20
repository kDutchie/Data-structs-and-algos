# Linear Search in C and C++

These programs find the **first zero-based index** of a target integer in an
array. They return `-1` if the target is absent. The array does not need to be
sorted, and duplicate and negative values are supported.

## Files

- `linear_search.c`: Complete C program.
- `linear_search.cpp`: Complete C++ program.

## How it works

1. Start at index `0`.
2. Compare each element with the target, moving from left to right.
3. Return immediately when a match is found. This ensures the first occurrence
   is returned when the target appears more than once.
4. Return `-1` after reaching the end without finding a match.

For `[2, 3, 4, 5, 3]` and target `3`, the search checks `2`, then `3`, and returns
`1` without inspecting the remaining elements.

## Time complexity

Let `n` be the number of array elements.

| Case | Search time | Explanation |
| --- | --- | --- |
| Best | O(1) | The target is the first element, so only one comparison is needed. |
| Average | O(n) | Assuming a present target's first occurrence is equally likely at any index, the search makes `(n + 1) / 2` comparisons on average. |
| Worst | O(n) | The target is absent or first appears at the last index, so all `n` elements are checked. |

An empty array returns `-1` without any element comparisons. The complete
program takes O(n) time for nonempty input even when the search itself finishes
in O(1), because it first reads and stores all `n` elements.

## Space complexity

- **Search auxiliary space: O(1).** The function uses only a loop index and
  passes the existing array by pointer in C or by constant reference in C++.
  It does not copy the array or use recursion.
- **Complete program space: O(n).** The C program allocates an array with
  `malloc`, and the C++ program stores the input in a `std::vector<int>`.
  This input storage grows with the number of elements.

## Compile and run

From the workspace folder, enter this directory:

```sh
cd DSA/linear_search
```

Compile both programs with warnings enabled:

```sh
cc -std=c11 -Wall -Wextra -Werror -pedantic linear_search.c -o linear_search_c
c++ -std=c++17 -Wall -Wextra -Werror -pedantic linear_search.cpp -o linear_search_cpp
```

Each program reads whitespace-separated integers from standard input:

1. The nonnegative element count, `n`.
2. Exactly `n` array elements.
3. The target integer.

Example input:

```text
5
2 3 4 5 3
3
```

Run the example with either program:

```sh
printf '5\n2 3 4 5 3\n3\n' | ./linear_search_c
printf '5\n2 3 4 5 3\n3\n' | ./linear_search_cpp
```

Each prints:

```text
1
```

The index is the search function's return value and is printed to standard
output. A successful program run exits with status `0`, including when the
target is absent. Invalid or incomplete input produces an error message and
a nonzero exit status.

## Test cases

| Array | Target | Expected output |
| --- | --- | --- |
| `[2, 3, 4, 5, 3]` | `3` | `1` |
| `[2, -4, 4, 0, 10]` | `6` | `-1` |
| `[1, 3, 5, -4, 1]` | `1` | `0` |

For an empty array, input `0 6` also produces `-1`.
