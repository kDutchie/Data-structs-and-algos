#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int linear_search(const int values[], int count, int target)
{
    for (int i = 0; i < count; ++i) {
        if (values[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    /* Input: element count, array elements, then target (space-separated). */
    int count;
    if (scanf("%d", &count) != 1 || count < 0 ||
        (size_t)count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Invalid element count.\n");
        return EXIT_FAILURE;
    }

    int *values = NULL;
    if (count > 0) {
        values = malloc((size_t)count * sizeof(*values));
        if (values == NULL) {
            fprintf(stderr, "Unable to allocate array.\n");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(values);
            return EXIT_FAILURE;
        }
    }

    int target;
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Invalid target.\n");
        free(values);
        return EXIT_FAILURE;
    }

    printf("%d\n", linear_search(values, count, target));
    free(values);
    return EXIT_SUCCESS;
}
