#include <stdio.h>
#include <stdlib.h>

/* Requires a nonempty array. */
int largest_element(const int nums[], int count)
{
    int largest = nums[0];

    for (int i = 1; i < count; ++i) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    return largest;
}

int main(void)
{
    /* Input: element count, followed by that many space-separated integers. */
    int count;
    if (scanf("%d", &count) != 1 || count < 1 || count > 100000) {
        fprintf(stderr, "Element count must be between 1 and 100000.\n");
        return EXIT_FAILURE;
    }

    int *nums = malloc((size_t)count * sizeof(*nums));
    if (nums == NULL) {
        fprintf(stderr, "Unable to allocate array.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &nums[i]) != 1 || nums[i] < -10000 || nums[i] > 10000) {
            fprintf(stderr, "Each element must be an integer between -10000 and 10000.\n");
            free(nums);
            return EXIT_FAILURE;
        }
    }

    printf("%d\n", largest_element(nums, count));
    free(nums);
    return EXIT_SUCCESS;
}
