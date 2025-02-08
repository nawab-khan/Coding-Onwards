class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size(), res = 0;

        if(n1&1)
            for(int i : nums2)
                res ^= i;

        if(n2&1)
            for(int i : nums1)
                res ^= i;

        return res;
    }
};