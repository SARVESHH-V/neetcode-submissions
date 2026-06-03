class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = prices[0];

        int maxprofit= 0;

        for(int i=1;i<n;i++){
            minprice = min(minprice,prices[i]);
            int p = prices[i]-minprice;
            maxprofit=max(maxprofit,p);
        }
        return maxprofit;
    }
};
