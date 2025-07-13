class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for(auto& op : operations){
            if(op == "+"){
                if(scores.size() >= 2) scores.push_back(scores[scores.size()-1] + scores[scores.size()-2]);
            }
            else if(op == "D"){
                if(scores.size()) scores.push_back(scores[scores.size()-1] * 2);
            }
            else if(op == "C"){
                if(scores.size()) scores.pop_back();
            } else {
                scores.push_back(stoi(op));
            }
        }

        int sum = 0;
        return accumulate(scores.begin(),scores.end(),0);

    }
};
