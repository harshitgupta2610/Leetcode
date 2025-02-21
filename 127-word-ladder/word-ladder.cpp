#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adj; 
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < wordList[i].size(); k++) {
                    if (wordList[i][k] != wordList[j][k]) diff++;
                    if (diff > 1) break; 
                }
                if (diff == 1) { 
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level; 

            for (const string& neighbor : adj[word]) {
                if (!visited.count(neighbor)) {
                    q.push({neighbor, level + 1});
                    visited.insert(neighbor);
                }
            }
        }
        return 0;
    }
};
