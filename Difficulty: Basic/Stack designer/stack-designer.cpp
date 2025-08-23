/* _push function to insert elements of array to
   stack
*/
class Solution {
public:
    stack<int> push(vector<int> &arr) {
        // return a stack with all elements of arr inserted in it
        stack<int> res;
        for(auto it : arr){
            res.push(it);
        }
        return res;
        
        
    }

    /* _pop function to print elements of the stack
       remove as well
    */
    void pop(stack<int> s) {
        // print top and pop for each element until it becomes empty
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        
    }
};