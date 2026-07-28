class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> node;
        unordered_map<char,int> indegree;

        for(auto word : words){
            for(char c : word){
                indegree[c]=0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];

            if(w1.size()>w2.size() && w1.substr(0,w2.size())==w2){
                return "";
            }

            int len = min(w1.size(),w2.size());
            
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    if(!node[w1[j]].count(w2[j])){
                        node[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto x : indegree){
            if(x.second==0){
                q.push(x.first);
            }
        }
        string ans;

        while(!q.empty()){
            char cur = q.front();
            q.pop();

            ans += cur;

            for(char nxt : node[cur]){
                indegree[nxt]--;
                if(indegree[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        if(ans.size()!=indegree.size()){
            return "";
        }
        return ans;
    }
};
