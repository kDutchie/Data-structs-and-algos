#include <iostream>
#include <vector>

// Requires a nonempty array.
int largest_element(const std::vector<int>& nums)
{
    int largest = nums[0];

    for (std::size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    return largest;
}

int main()
{
    // Input: element count, followed by that many space-separated integers.
    int count;
    if (!(std::cin >> count) || count < 1 || count > 100000) {
        std::cerr << "Element count must be between 1 and 100000.\n";
        return 1;
    }

    std::vector<int> nums(static_cast<std::size_t>(count));
    for (int& num : nums) {
        if (!(std::cin >> num) || num < -10000 || num > 10000) {
            std::cerr << "Each element must be an integer between -10000 and 10000.\n";
            return 1;
        }
    }

    std::cout << largest_element(nums) << '\n';
    return 0;
}
