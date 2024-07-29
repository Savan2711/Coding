/*
https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/

class Solution {
public:
    struct myComp {
        constexpr bool operator()(
            pair<char, int> const& a,
            pair<char, int> const& b)
            const noexcept
        {
            return a.second > b.second;
        }
    };

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed,
                          vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> umap;
        for(int i = 0; i < original.size(); i++) {
            umap[original[i]].push_back({changed[i], cost[i]});
        }

        long long ans = 0;
        vector<vector<int>> vec_ans(26 , vector<int> (26, 0));;
        for(int i = 0; i < source.length(); i++) {
            vector<bool> visited(26, false);
            visited[source[i] - 'a'] = true;
            if(source[i] == target[i]) {
                continue;
            }

            if(vec_ans[source[i] - 'a'][target[i] - 'a'] != 0) {
                ans += vec_ans[source[i] - 'a'][target[i] - 'a'];
                continue;
            }

            priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
            for(int j = 0; j < umap[source[i]].size(); j++) {
                pq.push(umap[source[i]][j]);
            }

            bool isFound = false;
            while(!pq.empty()) {
                pair<char, int> ele = pq.top();
                pq.pop();
                if(visited[ele.first - 'a']) {continue;}
                visited[ele.first - 'a'] = true;
                
                vec_ans[source[i] - 'a'][ele.first - 'a'] = ele.second;

                if(target[i] == ele.first) {
                    vec_ans[source[i] - 'a'][target[i] - 'a'] = ele.second;
                    isFound = true;
                    break;
                }

                for(int j = 0; j < umap[ele.first].size(); j++) {
                    if(!visited[umap[ele.first][j].first - 'a'])
                    {
                        pq.push({umap[ele.first][j].first, ele.second + umap[ele.first][j].second});
                    }
                }

            }

            if(!isFound) {return -1;}
            ans += vec_ans[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;

    }
};
