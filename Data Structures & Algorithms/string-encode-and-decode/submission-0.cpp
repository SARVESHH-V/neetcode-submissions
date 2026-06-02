class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";

        for(int i=0;i<strs.size();i++){
            int l = strs[i].size();
            string ll = to_string(l);
            res+=ll;
            res+="#";
            res+=strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        int n = s.size();

        while(i<n){
            int j = i;

            while(s[j]!='#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));

            j++;

            string word = s.substr(j,len);
            ans.push_back(word);

            i = j+len;
        }
        return ans;

    }
};
