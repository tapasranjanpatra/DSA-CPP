#include<iostream>
#include<stdlib.h>

using namespace std;

class Stack
{
    private:
        int s[100];
        int top;
    public:
        Stack()
        {
            top = -1;
        }
        ~Stack()
        {
            top = -1;
        }
        void push(int value)
        {
            if(isStackFull())
            {
                cout<<"Stack Overflow"<<endl;
            }
            else
            {
                top++;
                s[top]=value;
            }
        }

        int isStackEmpty()
        {
            if(top == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int isStackFull()
        {
            if(top == 99)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int pop()
        {
            if(isStackEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                top--;
                return s[top+1];             }
        }
	int multipop(int v)
        {
            if(isStackEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else
            {
            	for(int i=0; i<v; i++ )
            	top--;
                
            	
              return 0;               
            }
        }
        int Top()
        {
            if(isStackEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else
            {
                return s[top];
            }
        }

        int Size()
        {
            return top+1;
        }
};

int main()
{
    int choice;
    Stack s;
    while(choice != 5)
    {
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Get Top"<<endl;
        cout<<"4. Get Size"<<endl;
        cout<<"5. multipop"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter your choice "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    int value;
                    cout<<"Enter a Number : "<<endl;
                    cin>>value;
                    s.push(value);
                    break;
                }
            case 2:
                {
                    int value = s.pop();
                    cout<<"Deleted value is "<<value<<endl;
                    break;
                }
            case 3:
                {
                    cout<<"Top of the Stack is "<<s.Top()<<endl;
                    break;
                }
            case 4:
                {
                    cout<<"Size of Stack is "<<s.Size()<<endl;
                    break;
                }
             case 5:
                {
                   int v;
                    cout<<"enter the element";
                    cin>>v;
                    s.multipop(v);
                   cout<<"Size is "<<s.Size()<<endl;
                    break;
                }
            case 6:
                {
                    exit(0);
                }
        }
    }
    return 0;
}