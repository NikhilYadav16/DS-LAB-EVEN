#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterToRight(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1); // Initialize result vector with -1
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i]; // Current element is the next greater for elements in the stack
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 7, 3, 1, 8, 5};

    std::vector<int> result = nextGreaterToRight(nums);

    std::cout << "Next greater to right: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
