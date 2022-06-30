#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void print(node *head)
{
    node *temp = head;
    cout << "Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n\n";
}

node *takeInput()
{

    node *head = nullptr;
    int data;
    cout << "Enter first node data:" << endl;
    cin >> data;
    node *n = new node(data);
    head = n;
    node *temp = head;
    char c, c1;
    cout << "type y to add next node:" << endl;
    cin >> c;
    while (c == 'y')
    {
        cout << "enter data:" << endl;
        cin >> data;
        node *n1 = new node(data);
        temp->next = n1;
        temp = n1;
        cout << "type y to add next node:" << endl;
        cin >> c1;
        c = c1;
    }
    return head;
}

void addNodes(node *head)
{
    int n, data;
    node *temp = head;
    cout << "Enter number of nodes to be added:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter data:" << endl;
        cin >> data;
        node *n = new node(data);
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

node *insertNode(node *head)
{
    node *temp = head;
    int data, pos;
    cout << "Enter position at which data to be added:" << endl;
    cin >> pos;
    if (pos == 1)
    {
        cout << "Enter data:" << endl;
        cin >> data;
        node *n = new node(data);
        n->next = head;
        head = n;
    }
    else
    {
        int count = 1;
        cout << "Enter data:" << endl;
        cin >> data;
        while (count < pos - 1 && temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        if (temp != nullptr)
        {
            node *n = new node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }
    return head;
}

node *deleteNode(node *head)
{
    int pos;
    cout << "Enter the position of node to be deleted:" << endl;
    cin >> pos;
    node *a = head;
    node *b = nullptr;
    if (pos == 1)
    {
        head = a->next;
    }
    else
    {
        int count = 1;
        while (count < pos - 1 && a != nullptr)
        {
            a = a->next;
            count++;
        }
        if (a != nullptr)
        {
            b = a->next;
            a->next = b->next;
            delete b;
        }
        else
        {
            cout << "position of node is out of linked list" << endl;
        }
    }
    return head;
}

node* midpoint(node *head)
{
    node *slow = head;
    node *fast = head->next;
    node*mid=nullptr;
    while (fast != nullptr)
    {
        if (fast->next == nullptr)
        {
            mid=slow;
            break;
        }
        if (fast->next->next == nullptr)
        {
            mid=slow->next;
            break;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    return mid;
}

node *merge2LL(node *h1, node *h2)
{

    node *fh = nullptr; //final head
    node *tail = nullptr;
    if (h1->data > h2->data)
    {
        fh = h2;
        tail = h2;
        h2 = h2->next;
    }
    else
    {
        fh = h1;
        tail = h1;
        h1 = h1->next;
    }
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data > h2->data)
        {   
            tail->next=h2;
            tail = h2;
            h2 = h2->next;
        }
        else
        {
            tail->next=h1;
            tail = h1;
            h1 = h1->next;
        }
    }
    if(h1==nullptr){
        while (h2!=nullptr)
        {
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
     }
    if(h2==nullptr){
        while (h1!=nullptr)
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
     }
    return fh;
}


node*sortByMergeSort(node*h1){
    if(h1->next==nullptr){
        return h1;
    }
    node*mid=midpoint(h1);
    node*h2=mid->next;
    mid->next=nullptr;
    h1=sortByMergeSort(h1);
    h2=sortByMergeSort(h2);
    return merge2LL(h1,h2);
}


node*ReverseLLRecursion(node*head){
    if(head==nullptr){
            return nullptr;
        }
    if(head->next==nullptr){
        return head;
    }
    node*temp=head->next;
    node*head1=ReverseLLRecursion(head->next);
    
    temp->next=head;
    head->next=nullptr;
    return head1;
}


node*ReverseByIteration(node*head){

node*current=head->next;
node*prev=head;
node*nextnode=head->next->next;
head->next=nullptr;
while (nextnode!=nullptr)
{
    
    current->next=prev;
    prev=current;
    current=nextnode;
    nextnode=nextnode->next;
    
}
current->next=prev;
return current;

}