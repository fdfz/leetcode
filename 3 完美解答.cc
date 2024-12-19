class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128);
        int start = -1, end = 0, max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (v[s[i]] == 0)
            {
                v[s[i]] += 1;
                if (i - start > max)
                    max = i - start;
            }
            else
            {
                for(int j=start+1;j<i;++j){
                    if(s[j]==s[i]){
                        for(int k=start+1;k<j;k++){
                            v[s[k]]=0;
                        }
                        start=j;
                        
                    }
                    
                }
            }
        }
        return max;
    }
};