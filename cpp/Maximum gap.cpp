class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        if (min_val == max_val) return 0;

        // Calculate bucket size and count
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);

        // Populate buckets
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
        }

        // Calculate max gap between successive non-empty buckets
        int max_gap = 0;
        int previous_max = min_val;

        for (int i = 0; i < bucket_count; i++) {
            // Skip empty buckets
            if (bucket_min[i] == INT_MAX) continue;

            max_gap = max(max_gap, bucket_min[i] - previous_max);
            previous_max = bucket_max[i];
        }

        return max_gap;
    }
};
