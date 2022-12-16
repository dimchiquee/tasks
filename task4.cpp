#include <iostream>
using namespace std;
class List final
{

    struct Element
    {
        int data;
        Element* next;
    };

private:

    Element* head;
    Element* tmp;

public:

    List()
    {
        head = NULL;
        tmp = head;
    };

    void init(int length)
    {
        head = new Element;
        tmp = head;
        Element* current = head;
        for (int i = 0; i < length - 1; i++)
        {
            current->next = new Element;
            current = current->next;
        }
        current->next = head;
    };

    void print()
    {
        Element* current = head;
        do
        {
            if (current->data != -842150451)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        } while (current != head);
    };

    void add(char x)
    {
        tmp->data = x;
        tmp = tmp->next;
    };

};

int main()
{
    List testing;
    testing.init(5);
    testing.add(1);
    testing.add(2);
    testing.add(3);
    testing.add(4);
    testing.add(5);
    testing.add(6);
    testing.add(7);
    testing.print();
}
