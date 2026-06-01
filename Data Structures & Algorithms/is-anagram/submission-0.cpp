class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.size();
        vector<int> v(256);
        int l2 = t.size();
        vector<int> vv(256);
        if(l1!=l2){
            return false;
        }
        for(int i=0;i<l1;i++){
            int p = s[i];
            v[p]++;
        }
        for(int j=0;j<l2;j++){
            int p = t[j];
            vv[p]++;
        }
        if(v==vv){
            return true;
        }
        else{
            return false;
        }
    }
};
