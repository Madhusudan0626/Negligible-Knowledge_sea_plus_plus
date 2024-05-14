bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(nums[i]) != h.end()) {//if have return false that's why !=
                return true;
            }
            h.insert(nums[i]);
            if (h.size() > k) {
                h.erase(nums[i - k]);
            }
        }
        return false;
    }
