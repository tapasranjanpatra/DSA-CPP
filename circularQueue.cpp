#include<iostream>
using namespace std;

class CircularQueue
{
        int q[5];
        int front;
        int rear;
        int size;

    public :

        CircularQueue()
        {
            front = -1;
            rear = -1;
            size =  5;
        }


        void Enqueue(int v)
        {
            if(rear == -1)
            {
                rear++;
                front++;
                q[rear] = v;
            }
            else if((rear+1)%size == front)
            {
                cout<<"Overflow"<<endl;
            }
            else{
                rear = (rear+1)%size;
                q[rear] = v;
            }
        }

        void Dequeue()
        {
            if(front == -1)
            {
                cout<<"Underflow"<<endl;
            }
            else if(rear == front)
            {
                cout<<q[front]<<" deleted"<<endl;
                rear = front = -1;
            }
            else{
                cout<<q[front]<<" deleted"<<endl;
                front = (front+1)%size;
            }
        }

      void print()
        {
            if(front == -1)
            {
                cout<<"Queue is Empty"<<endl;
                return;
            }
            int i = front;
            while(1)
            {
                cout<<q[i]<<" ";
                 if(i == rear)
                    break;
                i = (i+1)%size;
            }
            cout<<endl;
        }
};

int main()
{
    CircularQueue q;
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

    return 0;
}