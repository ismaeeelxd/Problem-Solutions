class Solution {
public:
    int calPoints(vector<string>& operations) {
    int scores=0;
    stack<int> arr;
    for(int i = 0;i<operations.size();++i){
        if(!(operations[i] =="+" || operations[i] =="D" || operations[i] =="C"))
            arr.push(stoi(operations[i]));
        else if(operations[i] == "+"){
            int x =arr.top();
            arr.pop();
            int y =arr.top();
            arr.push(x);
            arr.push(x+y);
        }
        else if(operations[i] == "D"){
            arr.push(arr.top() * 2);
        }
        else if(operations[i] == "C"){
            arr.pop();
        }
    }
    while(!arr.empty()){
        scores+=arr.top();
        arr.pop();
    }

    return scores;
}
};
