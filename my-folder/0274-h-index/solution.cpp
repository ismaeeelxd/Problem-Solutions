class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hI = 0;
        sort(citations.begin(),citations.end());
        if(citations.size() == 1 && citations[0] != 0){
            return 1;
        }
        for(int i = 0;i<citations.size();++i){
            if(citations[i] >= citations.size() - i)
                return citations.size() - i;
        }
        return hI;
    }
};
