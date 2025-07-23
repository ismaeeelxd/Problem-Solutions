class Solution {
public:
    int maximumGain(string a, int x, int y) {
        // first phase of the algorithm is removing all the greater score
        // second phase is removing the left overs
        if(a == "ab") return x;
        if(a == "ba") return y;
        stack<int> s;
        int i = 1;
        s.push(a[0]);
        int score = 0;
        if (x > y) {
            // favour ab
            while (i < a.length()) {
                char currentChar = a[i++];
                if (!s.empty() && s.top() == 'a' && currentChar == 'b') {
                    s.pop();
                    score += x;
                } else
                    s.push(currentChar);
            }
            
            //make your own string cause you cannot process it in reverse order
            stack<int> s2;
            while (!s.empty()) {
                char currentChar = s.top(); 
                s.pop(); 
                if (!s2.empty() && s2.top() == 'a' && currentChar == 'b') {
                    score += y;
                    s2.pop();
                } else {
                    s2.push(currentChar);
                }
            }

        } else {
            // favour ba

            while (i < a.length()) {
                char currentChar = a[i++];
                if (!s.empty() && s.top() == 'b' && currentChar == 'a') {
                    s.pop();
                    score += y;
                } else
                    s.push(currentChar);
            }
            stack<int> s2;
            while (!s.empty()) {
                char currentChar = s.top();
                s.pop();
                if (!s2.empty() && s2.top() == 'b' && currentChar == 'a') {
                    score += x;
                    s2.pop();
                } else s2.push(currentChar);
            }
        }
        return score;
    }
};
