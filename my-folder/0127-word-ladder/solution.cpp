class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int idx = -1;
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; ++i) {
            if(wordList[i] == endWord) idx = i;
            for (int j = i + 1; j < n; ++j) {
                string word1 = wordList[i];
                string word2 = wordList[j];
                int diff = 0;
                int minSize =
                    word1.size() < word2.size() ? word1.size() : word2.size();
                for (int k = 0; k < minSize; ++k) {
                    if (word1[k] != word2[k])
                        diff++;
                }
                int diffSize =
                    word1.size() < word2.size() || word2.size() > word1.size()
                        ? abs((int)word2.size() - (int)word1.size())
                        : 0;
                diff+=diffSize;
                if(diff != 1) continue;
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
        if (idx == -1 || beginWord == endWord)
            return 0;

        queue<int> q;
        vector<int> dist(n, 1e8);
        vector<bool> vis(n, false);
        q.push(n-1);
        dist[n-1] = 1;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            if(k == idx) return dist[k]; //reached end
            if(vis[k]) continue;
            vis[k] = 1;
            for(int i = 0; i < adjList[k].size(); ++i){
                int neighbour = adjList[k][i];
                if(dist[neighbour] > dist[k] + 1){
                    dist[neighbour] = dist[k] + 1;
                }
                q.push(neighbour);
            }
        }

        return 0;
    }
};
