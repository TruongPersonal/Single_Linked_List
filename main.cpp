#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

class SingleLinkedList
{
private:
    Node *head;
    int capacity;

public:
    SingleLinkedList()
    {
        head = NULL;
        capacity = 0;
    }

    int size()
    {
        return capacity;
    }

    void insertFirst(int new_data)
    {
        Node *new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
        ++capacity;
    }

    void insertLast(int new_data)
    {
        Node *new_node = new Node(new_data);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        ++capacity;
    }

    void insert(int new_data, int pos)
    {
        if (pos < 0 || pos > capacity)
        {
            return;
        }
        if (pos == 0)
        {
            insertFirst(new_data);
            return;
        }
        Node *new_node = new Node(new_data);
        Node *temp = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        ++capacity;
    }

    void removeFirst()
    {
        if (head == NULL)
        {
            return;
        }
        Node *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
        --capacity;
    }

    void removeLast()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            removeFirst();
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;
        --capacity;
    }

    void remove(int pos)
    {
        if (pos < 0 || pos >= capacity) {
            return;
        }
        if (pos == 0) {
            removeFirst();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->next;
        }
        Node *node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;
        --capacity;
    }

    Node *find() {
        
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    SingleLinkedList A;
    A.insertLast(2);
    A.insertLast(6);
    A.insertLast(3);
    A.insertLast(9);
    A.insertLast(0);
    A.insertLast(12);
    A.insertLast(5);
    A.insertLast(7);
    A.insertLast(9);
    A.remove(3);
    A.display();

    return 0;
}