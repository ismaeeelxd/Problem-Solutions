class Solution {
public:
    int convertStringToInteger(string token) {
        bool isNegative = false;

        if(token[0] == '-' && token.size() > 1) isNegative = true;
        else {
            if(!isdigit(token[0])) return INT_MIN;
        }
        int number = 0;
        int multipler = 1;
        // 13445
        for(int i = token.size() - 1; i >= (isNegative ? 1 : 0); --i) {
            number+=(multipler*((int)(token[i] - '0')));
            multipler*=10;
        }
        return isNegative ? number*=-1 : number;
    }

    void printStack(stack<int> s) {
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            string token = tokens[i];
            int number = convertStringToInteger(token);
            if (number != INT_MIN) { // -11
                s.push(number);
                continue;
            }

            int number_1 = s.top();
            s.pop();
            int number_2 = s.top();
            s.pop();

            if (token == "+")
                s.push(number_1 + number_2);

            if (token == "-")
                s.push(number_2 - number_1);

            if (token == "*")
                s.push(number_2 * number_1);

            if (token == "/")
                s.push(number_2 / number_1);
        }
        return s.top();
    }
};
