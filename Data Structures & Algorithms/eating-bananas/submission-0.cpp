class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = piles.size();
        int m = piles[0];
        for(int i=1;i<k;i++){
            m = max(m,piles[i]);
        }

        int l = 1;
        int r =  m;
        int ans=r;

        while(l<=r){
            int mid = l+(r-l)/2;

            long total_time = 0 ;

            for(int i=0;i<k;i++){
                long pp = ceil(static_cast<double>(piles[i])/mid);
                total_time+=pp;
            }

            if(total_time<=h){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

            
        }
        return ans;



    }
};
