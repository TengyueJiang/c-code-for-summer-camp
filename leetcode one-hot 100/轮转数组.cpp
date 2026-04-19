class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> dq(nums.size());
        for(int i=0;i<nums.size();i++){
            dq[i]=nums[i];
        }
        while(k--){
            int tmp=dq.back();
            dq.pop_back();
            dq.push_front(tmp);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=dq[i];
        }
    }
};
