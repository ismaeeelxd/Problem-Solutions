class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(auto &x : s1) freq[x - 'a']++;
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> window_freq(26,0);
        while(ptr2 < s2.size() && ptr1 <= ptr2) {
            // eidbaooo
            /*
                e

            */
            int c1 = s2[ptr1] - 'a';
            int c2 = s2[ptr2] - 'a';

            bool ok = true;
            for(int i = 0; i < 26; ++i) {
                if(window_freq[i] != freq[i]) ok = false;
            }
            cout << endl; 
            if(ok) return true; 

            window_freq[c2]++;

            if(freq[c2] == 0) {
                for(int i = 0; i < 26; ++i) {
                    window_freq[i] = 0;
                }
                ptr1 = ptr2 + 1;
            } else if (window_freq[c2] > freq[c2]) {
                while(window_freq[c2] > freq[c2]) {      
                    int c3 = s2[ptr1] - 'a';
                    window_freq[c3] = (window_freq[c3] - 1) < 0 ? 0 : window_freq[c3] - 1;
                    ptr1++;
                }
            }

            ptr2++;
        }


                    bool ok = true;
            for(int i = 0; i < 26; ++i) if(window_freq[i] != freq[i]) ok = false;
            if(ok) return true; 

        return false;
    }
};
