#include <iostream>
#include <vector>

int linear_search(const std::vector<int>& values, int target)
{
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main()
{
    // Input: element count, array elements, then target (space-separated).
    int count;
    if (!(std::cin >> count) || count < 0) {
        std::cerr << "Invalid element count.\n";
        return 1;
    }

    std::vector<int> values(static_cast<std::size_t>(count));
    for (int& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Invalid array element.\n";
            return 1;
        }
    }

    int target;
    if (!(std::cin >> target)) {
        std::cerr << "Invalid target.\n";
        return 1;
    }

    std::cout << linear_search(values, target) << '\n';
    return 0;
}
