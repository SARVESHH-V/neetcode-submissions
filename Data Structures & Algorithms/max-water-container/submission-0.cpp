class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n-1;
        int area = 0;
        while(l<r){
            int w = r-l;
            int h = min(heights[l],heights[r]);

            int a = w*h;

            area = max(area,a);

            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return area;
    }
};
