class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
            if (nums1.size() > nums2.size()) {
                return findMedianSortedArrays(nums2, nums1);
            }
    
            int n1 = nums1.size(), n2 = nums2.size();
    
            int l = 0, r = n1, m, res, mid = (n1 + n2 + 1)/2;
            int x1, x2, x3, x4;
    
            while(l <= r){
    
                m = l + (r - l)/2;
    
                x1 = (m <= 0) ? INT_MIN : nums1[m - 1];
                x2 = (mid - m <= 0) ? INT_MIN : nums2[mid - m - 1];
                x3 = (m >= n1) ? INT_MAX : nums1[m];
                x4 = (mid - m >= n2) ? INT_MAX :nums2[mid - m];
    
                if(x1 <= x4 && x2 <= x3){
    
                    if((n1 + n2)&1){
                        return max(x1,x2);
                    }
                    else{
                        return (max(x1,x2) + min(x3,x4))/(double) 2;
                    }
    
                }
    
                if(x1 > x4){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
    
            }
    
            return -1;
        }
    };