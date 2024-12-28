//321. create maximum number
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>



std::vector<int> Combine(std::vector<int> nums1, std::vector<int> nums2) {
    int first = 0, second = 0;
    std::vector<int> result;
    
    while (first < nums1.size() || second < nums2.size()) {
        if (first < nums1.size() && (second >= nums2.size() || nums1[first] > nums2[second] || 
            (nums1[first] == nums2[second] && std::vector<int>(nums1.begin() + first, nums1.end()) > std::vector<int>(nums2.begin() + second, nums2.end())))) {
            result.push_back(nums1[first++]);
        } else {
            result.push_back(nums2[second++]);
        }
    }
    
    return result;
}

std::vector<int> Highest(std::vector<int> nums1, int k) {
    int n = nums1.size() - k;
    std::stack<int> St;
    
    for (int i = 0; i < nums1.size(); ++i) {
        while (!St.empty() && St.top() < nums1[i] && n > 0) {
            St.pop();
            n--;
        }
        St.push(nums1[i]);
    }
    
    std::vector<int> result;
    while (!St.empty()) {
        result.push_back(St.top());
        St.pop();
    }
    
    std::reverse(result.begin(), result.end());
    result.resize(k);

    return result;
}

std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<int> Result;
    for (int i = 0; i <= k; ++i) {
        if (i <= nums1.size() && (k - i) <= nums2.size()) {
            std::vector<int> v1 = Highest(nums1, i);
            std::vector<int> v2 = Highest(nums2, k - i);
            std::vector<int> candidate = Combine(v1, v2);
            
            if (candidate > Result) {
                Result = candidate;
            }
        }
    }
    return Result;
}

int main() {
    std::vector<int> nums1 = {3, 4, 6, 5};
    std::vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;

    std::vector<int> result = maxNumber(nums1, nums2, k);
    
    std::cout << "Result: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
