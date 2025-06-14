#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
unordered_set<string> lists(wordList.begin(), wordList.end());
    if (lists.find(endWord) == lists.end()) return 0;

    queue<string> my_q;
    my_q.push(beginWord);

    int result = 1;
    while (!my_q.empty()) {
        int count = my_q.size();

        for (int i = 0; i < count; i++) {
            string word = my_q.front();
            my_q.pop();

            if (word == endWord)
                return result;

            for (int j = 0; j < word.size(); j++) {
                char originalChar = word[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar)
                        continue;
                    word[j] = c;
                    if (lists.find(word) != lists.end()) {
                        my_q.push(word);
                        lists.erase(word);
                      
                    }
                    word[j] = originalChar;
                }
            }
        }
        result ++;
    }
    return 0;
    }
    
};