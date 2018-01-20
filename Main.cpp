#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node()
	 {
	  data = 0; 
	  next = NULL; 
	  }
    Node(int d=0, Node* n = NULL)
	 { 
	 data = d;
	  next = n; 
	  } 
};

class SLL 
{
private:
    Node* front;
public:
    SLL ()
	 { 
	 front = NULL;
	  } 

    void insert_to_front(int item)
    {
        Node* nn = new Node(item, front);
        front = nn;
    }
    
    void insert_to_back(int item)
    {
        if (front == NULL)
            front = new Node(item);
        else {
            Node* p = front;
            while (p->next != NULL)
                p = p->next;
            p->next = new Node(item);

        }
    }
    
      void delete_from_front()
    {
    	if(front == NULL)
    	{
    		cout<<"list is empty"<<endl;
		}
		else if(front->next == NULL)
		{
			delete(front);
		}
    	else
    	{
    		Node* p = front->next;
    		delete(front);
    		front = p;
		}
    	
	}
	
	 void delete_from_back()
    {
    	Node* prev;
    	if(front == NULL)
    	{
    		cout<<"list is empty"<<endl;
		}
		else if(front->next == NULL)
		{
			delete(front);
		}
    	else
    	 {
            Node* p = front;
            while (p->next != NULL)
            {
			
                prev = p;
                p = p->next;
            }
            prev->next = NULL;
            delete(p);
            

        }
    	
	}
	
	  void print()
    {
        Node* p = front;
        while (p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
	
		
	void delete_middle()
	{
   		int position = 1;
   		Node* slow_ptr = front;
    	Node* fast_ptr = front;
    	
    	if(front == NULL)
    	{
    		cout<<"List is empty"<<endl;
		}
		
		else if(front->next == NULL)
		{
			delete(front);
			
		}
 
    else 
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            position++;
        }
	Node* pointer;
	Node* s1;
	s1 = front;
        for(int i = 1; i< position; i++){
           pointer = s1;
           s1 = s1->next;
        }
        pointer->next = s1->next;
        delete(s1);
	
    }
   
}

    
    void insert_middle(int value)
    {
    	int position = 1;
    	Node* temp;
		 Node* pointer;
		 Node* s1;
        Node* slow_ptr = front;
       Node* fast_ptr =  front;
       if(front == NULL)
       {
       	cout<<"Currently no element present in the list"<<endl;
       	temp = new Node(value);
       	front = temp;
       	front->next = NULL;
	   }
      else if(front->next == NULL)
       {
       	cout<<"Currently only one element present in the list"<<endl;
       	temp = new Node(value);
       	front->next = temp;
       	front->next->next = NULL;
	   }
 
    else
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            position++;
        }
        
        temp = new Node(value);
	s1 = front;
        for(int i = 1; i< position; i++){
           pointer = s1;
           s1 = s1->next;
        }
	pointer->next = temp;
	temp->next = s1;
	
    }
   
	}

 Node* findMin()
    {
        Node* moving_ptr;
        Node* min;
        min = front;
        moving_ptr = front;
              while(moving_ptr != NULL)
                {
                     if(moving_ptr->data < min->data)
                        {
                         min = moving_ptr;
                        }
                     moving_ptr = moving_ptr->next;
                 }
                 return min;
    }

   void delete_in_Ascending_order()
    {

       Node* minimum;
       Node* temp;
       Node* min_prev;

       while(front != NULL)
          {
            minimum = findMin();
            temp = front;
            while(temp != minimum)
            {
            	min_prev = temp;
            	temp = temp->next;
			}
            
            if(minimum == front)

             {
                 front = front->next;
                 delete(minimum);

             }
              else{

                  min_prev->next = minimum->next;
                  delete(minimum);
                 }

          }
        
          cout<< "All nodes deleted in ascending order . Now single list is empty "<< endl;


    }

   };


int main(int argc, const char * argv[]) {
    SLL* sl = new SLL();
    sl->insert_to_front(2);
    sl->insert_to_front(3);
    sl->insert_to_front(4);
    sl->insert_to_front(5);
    sl->insert_to_front(6);
    sl->insert_to_back(1);
    sl->insert_to_back(0);
    sl->print();
    sl->delete_from_front();
    sl->print();
    sl->delete_from_back();
    sl->print();
    sl->delete_middle();
    sl->print();
    sl->insert_middle(3);
    sl->print();
    sl->insert_middle(7);
    sl->print();
    cout<<"minimum value is : ";
    cout<<sl->findMin()->data<<endl;
   sl->delete_in_Ascending_order();
   sl->print();

    return 0;
}

