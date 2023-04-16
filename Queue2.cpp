#include<iostream>
using namespace std;

class Queue
{
        int q[100];
        int front;
        int rear;
        int size;

    public :

        Queue()
        {
            front = -1;
            rear = -1;
            size =  100;
        }

        void insertAtEnd(int v)
        {
            if(rear == -1)
            {
                rear++;
                front++;
                q[rear] = v;
            }
            else if(rear == size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else
            {
                q[++rear] = v;
            }
        }

        void DeleteAtFront()
        {
            if(front == -1)
                cout<<"Underflow"<<endl;
            else if(rear == front)
            {
                cout<<q[front]<<" deleted"<<endl;
                front = rear = -1;
            }
            else{
                cout<<q[front++]<<" deleted"<<endl;
            }
        }

        void deleteAtEnd()
        {
            if(rear == -1)
                cout<<"Underflow"<<endl;
            else if(rear == front)
            {
                cout<<q[rear]<<" deleted"<<endl;
                front = rear = -1;
            }
            else{
                cout<<q[rear--]<<" deleted"<<endl;
            }
        }

        void insertAtBegin(int v)
        {
            if(front == -1)
            {
                front++; rear++;
                q[front] = v;
            }
            else if(rear == size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else{
                    for(int i=rear; i>= front; i--)
                        q[i+1] = q[i];

                    rear++;
                    q[front] = v;
            }

        }


        void print()
        {
            if(front == -1)
            {
                cout<<"Queue is Empty"<<endl;
                return;
            }
            for(int i= front ; i<= rear ;i++)
                cout<<q[i]<<" ";
            cout<<endl;
        }
};

int main()
{
    Queue q;
    int choice;
	
    while(1)
    {
    	cout<<"1.Insert at end"<<endl;
    	cout<<"2.Insert at begin"<<endl;
    	cout<<"3.Delete at front"<<endl;
    	cout<<"4.Delete at end"<<endl;
    	cout<<"5.print"<<endl;
    	cout<<"6.Exit"<<endl;
		cout<<"Enter your choice "<<endl;
		cin>>choice;
    	switch(choice)
    	{
		
    	int value;
    		case 1:
    			cout<<"Enter the value"<<endl;
    			cin>>value;
    			q.insertAtEnd(value);
    			break;
    		case 2:
    			cout<<"Enter the value"<<endl;
    			cin>>value;
    			q.insertAtBegin(value);
    			break;
    		case 3:
    			q.DeleteAtFront();
    			break;
    		case 4:  			
    			q.deleteAtEnd();
    			break;
    		case 5:
    			q.print();
    			break;
    		case 6:exit(0);
			break;
    		    
    		    
    	}
    }
    

    return 0;
}