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

        void Enqueue(int v)
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

        void Dequeue()
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
		cout<<"1.Enqueue"<<endl;
    	cout<<"2.Dequeue"<<endl;
    	cout<<"3.Print"<<endl;
    	cout<<"4.Exit"<<endl;
		cout<<"Enter your choice"<<endl;
    	cin>>choice ;
    	switch(choice)
    	{
    	int value;
    		case 1:
    			cout<<"Enter the value"<<endl;
    			cin>>value;
    			q.Enqueue(value);
    			break;
    		case 2:
    			//cout<<"Enter the value"<<endl;
    			//cin>>value;
    			q.Dequeue();
    			break;
    		case 3:
    			q.print();
    			break;
    		case 4:exit(0);
    		    
    		    
    	}
    }
   // q.Enqueue(5);
    //q.Enqueue(10);
    //q.Enqueue(15);
    //q.print();
   // q.Dequeue();
    //q.print();
   // q.Dequeue();
   // q.print();
   // q.Dequeue();
   // q.print();
    return 0;
}