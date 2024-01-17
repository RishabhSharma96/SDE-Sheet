class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        int i=n-1, j=m-1, k=n+m-1;

        while(i>=0 && j>=0){
            if(nums2[j] > nums1[i]){
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];
            }
        }

        while(i>=0){
            nums1[k--] = nums1[i--];
        }

        while(j>=0){
            nums1[k--] = nums2[j--];
        }

    }
};