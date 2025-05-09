class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> users;
        for(int k = 0; k < messages.size(); ++k){
            string message = messages[k];
            for(int i = 0;i<message.size();++i){
                if(message[i] == ' ')
                    users[senders[k]]++;
            }
            users[senders[k]]++;
        }
        vector<string> top_users;
        string top_user;
        int counter = INT_MIN;
        for(const auto [user,count] : users){
            if(count == counter)
                top_users.push_back(user);
            else if(count > counter){
                counter = count;
                top_user = user;
                top_users.clear();
                top_users.push_back(top_user);
            }
            
        }  
        if(top_users.size()){
            auto largest = max_element(top_users.begin(), top_users.end());
            return *largest;
        }
        return top_user;
    }
};
