// https://leetcode.com/problems/search-insert-position/discuss/15371/My-understanding-of-(lower-boundupper-bound)-binary-search-in-C%2B%2B-thanks-to-two-post
// https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		/// comp is greater or equal to for lower_bound
		/// comp is greater for upper_bound
        int first=0, last=nums.size(), mid;
        while (first<last) {
            mid=(last+first)>>1; // first<=mid, mid<last
			// if(nums[mid]<=target) // for upper_bound
			if (nums[mid]<target) // for lower_bound
				first=mid+1; // first always increases
			else /// else recede last
				last=mid; // last always decreases (even last-first==1)
        }
        return first;
    }
};
