#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_Map;
        int n = nums.size();


        for (int i = 0; i < n; i++) {
            nums_Map[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int key = target - nums[i];
            if (nums_Map.count(key) && nums_Map[key] != i) {
                return { i, nums_Map[key] };
            }
        }

        return {};
    }
};

class Solution_2 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i];
            }
        }

        return index + 1;
    }
};

class Solution_3 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; ) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                n--;
            }
            else {
                i++;
            }
        }
        return n;
    }
};


class Solution_4 {
public:
    int strStr(string haystack, string needle) {
        int ans = haystack.find(needle);
        if (ans != string::npos) {
            return ans;
        }
        else {
            return -1;
        }
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());


        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }

                else {
                    vector<int> temp = { nums[i], nums[j], nums[k] };
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};


int main()
{

}















