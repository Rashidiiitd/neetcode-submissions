class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;

        for(auto it : tokens)
        {
            if(it.size() == 1 && (it[0] == '+' || it[0] == '-' || it[0] == '*' || it[0] == '/'))
            {
                // pop 2 elements from stack 
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                if(it[0] == '+')
                {
                    st.push(top1+top2);
                }
                if(it[0] == '-')
                {
                    st.push(top2-top1);
                }
                                if(it[0] == '*')
                {
                    st.push(top1*top2);
                }
                                if(it[0] == '/')
                {
                    st.push(top2/top1);
                }


            }

            else
            {
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};
