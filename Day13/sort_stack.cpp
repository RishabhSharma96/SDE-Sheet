/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertElement(stack<int>& s, int num){
    if(s.size() == 0 || s.top() < num){
        s.push(num);
        return ;
    }
    
    int x = s.top();
    s.pop() ;
    insertElement(s,num);
    s.push(x);
}

void SortedStack :: sort()
{
    if(s.size() == 0){
        return ;
    }
    
    int x = s.top();
    s.pop();
    sort();
    insertElement(s, x);
}