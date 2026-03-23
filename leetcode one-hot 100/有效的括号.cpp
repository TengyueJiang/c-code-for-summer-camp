class Solution {
public:
    bool isValid(string s) {
        char st[10001];
        int tt=0;
        for(int i=0;i<s.size();i++){
            st[tt]=s[i];
            if(s[i]==')'&&tt>=1&&st[tt-1]=='(')  tt--;
            else if(s[i]==')'&&(tt<1||st[tt-1]!='('))  return false;
            else if(s[i]==']'&&tt>=1&&st[tt-1]=='[')  tt--;
            else if(s[i]==']'&&(tt<1||st[tt-1]!='['))  return false;
            else if(s[i]=='}'&&tt>=1&&st[tt-1]=='{')  tt--;
            else if(s[i]=='}'&&(tt<1||st[tt-1]!='{'))  return false;
            else tt++;
        }
        if(tt>0) return false;
        return true;
    }
};
