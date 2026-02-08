class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr_1 = 0;
        int ptr_2 = numbers.size() - 1;
        while(ptr_1 < ptr_2) {
            int num1 = numbers[ptr_1];
            int num2 = numbers[ptr_2];
            if(num1 + num2 < target) ptr_1++;
            else if(num1 + num2 > target) ptr_2--;
            else return { ptr_1 + 1, ptr_2 + 1 };
        }

        return {};
    }
};
