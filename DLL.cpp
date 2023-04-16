#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
    public:

    int value;
    node *prev;
    node *next;

    node()
    {
        value = 0;
        prev = NULL;
        next = NULL;
    }
};

class DLL
{
    node *head;

    public :
        DLL()
        {
            head = NULL;
        }

        void insertAtEnd(int v)
        {
            node *temp = new node();
            temp->value = v;

            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                node *t = head;

                while(t->next != NULL)
                {
                    t = t->next;
                }
                t->next = temp;
                temp->prev = t;
            }
        }

        void insertAtBegin(int v)
        {
            node *temp = new node();
            temp->value = v;

            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void insertInMiddle(int v, int n)
        {
            node *temp = new node();
            temp->value = v;
            node *t = head;

            if(n == 0 && head != NULL)
            {
                this->insertAtBegin(v);
                return;
            }

            if(head == NULL && n>1)
            {
                cout<<"Position not found"<<endl;
                return;
            }

            while(n>1)
            {
                n--;
                if(t->next == NULL)
                {
                    cout<<"Position not found"<<endl;
                    break;
                }
                else{
                    t = t->next;
                }
            }

            temp->next = t->next;
            temp->prev = t;
            if(t->next != NULL)
                t->next->prev = temp;
            t->next = temp;
        }

        void deletionInMiddle(int n)
        {
            node *t = head;
            if(head == NULL)
            {
                cout<<"Position not found"<<endl;
                return;
            }
            if(n==1)
            {
                head= t->next;
                head->prev = NULL;
                cout<<t->value<<" deleted"<<endl;
                delete t;
                return ;
            }
            else{

                while(n>1)
                {
                    n--;
                    if(t->next == NULL)
                    {
                        cout<<"Position not found"<<endl;
                        return;
                    }
                    t = t->next;
                }

                t->prev->next = t->next;
                if(t->next != NULL)
                    t->next->prev = t->prev;
                cout<<t->value<<" deleted"<<endl;
                delete t;
            }
        }

        void printDLL()
        {
            node *t = head;

            while(t != NULL)
            {
                cout<<t->value<<" <=> ";
                t=t->next;
            }
            cout<<endl;
        }
};

int main()
{
    DLL dl;

    int choice;

    
    
    while(1)
    {
    
	cout<<endl<<endl<<"================================"<<endl;
    cout<<"1. Insert the at end"<<endl;
    cout<<"2. Insert the at begin"<<endl;
    cout<<"3. Insert the at middle"<<endl;
    cout<<"4. Delete the at middle"<<endl;
    cout<<"5. Print"<<endl;
    cout<<"6. exit"<<endl;
    cout<<"Enter your choice"<<endl;
	cin>>choice;
    int value,position;
    
        switch(choice)
        {
            case 1:
                  cout<<"Enter the value"<<endl;
                  cin>>value;
                  dl.insertAtEnd(value);
                  break;
            case 2:
                  cout<<"Enter the value"<<endl;
                  cin>>value;
                  dl.insertAtBegin(value);
                  break;
            case 3:
                  cout<<"Enter the value and position"<<endl;
                  cin>>value>>position;
                  dl.insertInMiddle(value,position);
                  break;
            case 4:
                  cout<<"Enter the position You want to delete"<<endl;
                  cin>>position;
                  dl.deletionInMiddle(position);
                  break;
            case 5:
                  dl.printDLL();
                  break;
            case 6:exit(0);
        }
    }

    // dl.insertAtEnd(5);
    // dl.insertAtEnd(10);
    // dl.insertAtEnd(20);
    // dl.insertAtEnd(15);
    // dl.insertAtBegin(50);
    // dl.insertAtBegin(100);
    // dl.insertInMiddle(10,2);
    // dl.insertInMiddle(25,1);
    // dl.insertInMiddle(500,8);
    // dl.insertInMiddle(20,0);
    // dl.deletionInMiddle(3);
    // dl.deletionInMiddle(1);
    // dl.deletionInMiddle(8);
    // dl.deletionInMiddle(10);
    // dl.printDLL();

    return 0;
}