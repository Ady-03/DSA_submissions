class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        if (endWord == beginWord)
            return 0;

        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            string temp = word;
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.size(); i++) {
                char original = temp[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    temp[i] = j;
                    if (st.count(temp)) {
                        st.erase(temp);
                        q.push({temp, steps + 1});
                    }
                }
                temp[i] = original;   // restore
            }
        }
        return 0;
    }
};