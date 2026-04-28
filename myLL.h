#include "LL.h"

class myLL : public LL
{
public:
    void insertAtHead(const int &rn, const string &name, int *marks);
    void insertAtTail(const int &rn, const string &name, int *marks);
    void insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR);
    //     int deleteFromHead();
    //     int deleteFromTail();
    //     int deleteFromPos(const int &rn);
    //     int searchValue(const int &rn);
    //     void updateStudentValue(const int &rn);
    bool isEmpty();
    void display();
    //     int countList();
};

bool myLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

void myLL::insertAtHead(const int &rn, const string &name, int *marks)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < 3; i++)
    {
        nn->marks[i] = marks[i];
    }
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
}
void myLL::insertAtTail(const int &rn, const string &name, int *marks)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < 3; i++)
    {
        nn->marks[i] = marks[i];
    }
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->next = nn;
        tail = nn;
    }
}

void myLL::insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < 3; i++)
    {
        nn->marks[i] = marks[i];
    }
    nn->next = nullptr;

    if (isEmpty())
    {
        cout << "Linked list is empty therefore you can add after Roll No" << endl;
        return;
    }
    else
    {
        Student *t = head;
        while (true)
        {
            if (t->rollNu == posR)
            {
                break;
            }
            t = t->next;
        }

        Student *tn = t->next;
        t->next = nn;
        nn->next = tn;
    }
}

void myLL::display()
{
    if (!isEmpty())
    {
        Student *t = head;
        while (true)
        {
            t->displayStudentInfo();
            if (t->next == nullptr)
            {
                break;
            }
            t = t->next;
        }
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
    }
}

// int myLL::countList()
// {
//     int count = 0;
//     if (!isEmpty())
//     {
//         Student *t = head;
//         while (true)
//         {
//             count++;
//             if (t->next == nullptr)
//             {
//                 break;
//             }
//             t = t->next;
//         }
//     }
//     return count;
// }

// int myLL::deleteFromHead()
// {
//     if (isEmpty())
//     {
//         cout << "Linked List is Empty" << endl;
//         return -1;
//     }
//     else
//     {
//         if (head == tail)
//         {
//             int rv = head->data;
//             delete head;
//             head = nullptr;
//             tail = nullptr;
//             return rv;
//         }
//         else
//         {
//             int rv = head->data;
//             Student *t = head->next;
//             delete head;
//             head = t;
//             return rv;
//         }
//     }
// }

// int myLL::deleteFromTail()
// {
//     if (isEmpty())
//     {
//         cout << "Linked List is Empty" << endl;
//         return -1;
//     }
//     else
//     {
//         if (head == tail)
//         {
//             int rv = tail->data;
//             delete tail;
//             head = nullptr;
//             tail = nullptr;
//             return rv;
//         }
//         else
//         {
//             int rv = tail->data;
//             Student *t = head;
//             while (true)
//             {
//                 if (t->next == tail)
//                 {
//                     break;
//                 }
//                 t = t->next;
//             }
//             delete tail;
//             tail = t;
//             tail->next = nullptr;
//             return rv;
//         }
//     }
// }

// int myLL::deleteFromPos(const int &pos)
// {
//     if (isEmpty())
//     {
//         cout << "Element not removed because Linked list is Empty" << endl;
//         return -1;
//     }
//     else if (pos <= 0 || pos > countList())
//     {
//         cout << "Element not removed because Invalid position" << endl;
//         return -1;
//     }
//     else if (pos == 1)
//     {
//         return deleteFromHead();
//     }
//     else if (pos == countList())
//     {
//         return deleteFromTail();
//     }
//     else
//     {
//         Student *t = head;
//         for (int i = 1; i < pos - 1; i++)
//         {
//             t = t->next;
//         }
//         Student *tn = t->next;
//         int rv = tn->data;
//         t->next = tn->next;
//         delete tn;
//         return rv;
//     }
// }

// int myLL::searchValue(const int &value)
// {
//     if (isEmpty())
//     {
//         cout << "Element not removed because Linked list is Empty" << endl;
//         return -1;
//     }
//     else
//     {
//         int pos = 0;
//         Student *t = head;
//         while (true)
//         {
//             if (t->data == value)
//             {
//                 pos++;
//                 return pos;
//                 break;
//             }
//             if (t->next == nullptr)
//             {
//                 cout << "value not exit in linked list" << endl;
//                 return -1;
//             }
//             t = t->next;
//         }
//     }
// }

// void myLL::updateStudentValue(const int &rn)
// {
//     if (isEmpty())
//     {
//         cout << "Element not removed because Linked list is Empty" << endl;
//     }
//     else
//     {
//         Student *t = head;
//         if (pos < 1 || pos > countList())
//         {
//             cout << "Invalid position" << endl;
//         }
//         else
//         {
//             for (int i = 1; i < pos; i++)
//             {
//                 t = t->next;
//             }
//             t->data = value;
//         }
//     }
// }
