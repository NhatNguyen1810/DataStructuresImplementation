#include <iostream>



using namespace std;



struct ListNode {

        int data;

        ListNode *next;

        ListNode(int x) : data(x), next(nullptr) {}

};



class LinkedList {

private:

    ListNode *head = nullptr;

    ListNode *tail = nullptr;

public:



    void addNode(int x)

    {

       /// To do: Add your code here

       /// Add a node to the list by using new operator.

       /// 1. If the list is empty, create the head node.

       /// 2. If the list exists, add the node to the tail.
       if(head == nullptr){
            head = new ListNode(x);
        }
        else{
            ListNode *g = head;
            while(g->next != nullptr){
                g = g->next;
            }
            g->next = new ListNode(x);
            tail = g->next;
        }


    }



    void addNodeToSortedList(int x)

    {

       /// To do: Add your code here

       /// Add a node to the list

       /// 1. If the list is empty, create the head node.

       /// 2. If the list exists, add the node to a proper position in the  list and keep the list sorted.

        ListNode *g = new ListNode(x);


       if(head == nullptr || x < head->data){

            g->next = head;
            head = g;


       }

       else {

                ListNode *current = head;


                while(current->next != nullptr && current->next->data < x){

                    current = current->next;

                }
                g->next = current->next;
                current->next = g ;
       }



    }

    void deleteAll()

    {

        /// To do: Add your code here

        /// Delete all nodes and free the memory
        ListNode* current = head;
        ListNode* next;
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }


    void reverseList()
    {
        /// To do: Add your code here

        /// It will reverse the list.

        /// Example:

        /// Before calling 1 -> 2 -> 6 -> 28 -> @

        /// After calling 28 -> 6 -> 2 -> 1 -> @

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;


    }

    void display()

    {

        /// To do: Add your code here

        /// Display all nodes in the sequence from head to tail

        /// Example:

        ///   6 -> 2 -> 28 -> 1 -> @

        ListNode* g = head;
        while(g != nullptr){
            cout << g->data;
            cout << " -> ";
            g = g->next;
        }

        cout << " @ " << endl;


    }



};

int main()

{

    LinkedList ll;
    ll.addNode(6);
    ll.addNode(2);
    ll.addNode(28);
    ll.addNode(1);


    /// Display 6 -> 2 -> 28 -> 1 -> @

    cout <<"Display the first time" << endl;
    ll.display();
    ll.deleteAll();
    /// Display either @ or -> @
    cout << "Display after deleting to check if it is deleted" << endl;
    ll.display();

    ll.addNodeToSortedList(6);
    ll.addNodeToSortedList(2);
    ll.addNodeToSortedList(28);
    ll.addNodeToSortedList(1);
    /// Display 1 -> 2 -> 6 -> 28 -> @
    cout << "Display the sorted list" << endl;
    ll.display();

    ll. reverseList();
    /// Display 28 -> 6 -> 2 -> 1 -> @
    cout << "Display the reverse list" << endl;
    ll.display();

    ll.deleteAll();
    /// Display either @ or -> @
    cout << "Display after deleting to check if it is deleted" << endl;
    ll.display();


    return 0;

}


