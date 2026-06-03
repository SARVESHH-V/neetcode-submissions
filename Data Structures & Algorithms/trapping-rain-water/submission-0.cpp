class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> p(n), s(n);

        p[0] = 0;

        for(int i = 1; i < n; i++) {
            p[i] = max(p[i - 1], height[i - 1]);
        }

        s[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--) {
            s[i] = max(s[i + 1], height[i + 1]);
        }

        int water = 0;

        for(int i = 0; i < n; i++) {
            water += max(0, min(p[i], s[i]) - height[i]);
        }

        return water;
    }
};