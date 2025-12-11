class Solution {
public:
    int countCollisions(string directions) {
        stack<int> st;
        int ans=0;
        for(int i=0; i<directions.size(); i++) {
            if(directions[i]=='R') {
                st.push(2);
            } else if(directions[i]=='L') {
                if(!st.empty()) {
                    ans+=st.top(); 
                    st.pop();
                    st.push(1);
                }
            } else {
                if(!st.empty() && st.top()==2) {
                    ans+=1;
                    st.pop();
                }
                st.push(1);
            }
        }
        int top=-1;
        while(!st.empty()) {
            if(st.top()==1) {
                top=1; 
            } else if(top!=-1) {
                ans+=1;
            }
            st.pop();
        }
        return ans;
    }
};
