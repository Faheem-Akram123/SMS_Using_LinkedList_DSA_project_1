#include "LL.h"

class myLL : public LL
{
public:
    void insertAtHead(const int &rn, const string &name, int *marks, const int &size);
    void insertAtTail(const int &rn, const string &name, int *marks, const int &size);
    void insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR, const int &size);
    Student *deleteFromHead();
    Student *deleteFromTail();
    Student *deleteFromPos(const int &rn);
    Student *searchValue(const int &rn);
    void updateStudentValue(const int &rn, const int *m, const string &n);
    bool isEmpty();
    void display(const int &size);
    int countList();
    int highMarks(const int &nfm);
    float avgMarks(const int &nfm);
    int lowMarks(const int &nfm);
};

bool myLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

void myLL::insertAtHead(const int &rn, const string &name, int *marks, const int &size)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < size; i++)
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
void myLL::insertAtTail(const int &rn, const string &name, int *marks, const int &size)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < size; i++)
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

void myLL::insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR, const int &size)
{
    Student *nn = new Student;
    nn->name = name;
    nn->rollNu = rn;
    for (int i = 0; i < size; i++)
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
            if (t->next == tail)
            {
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
                break;
            }
            else if (t->rollNu == posR)
            {
                Student *tn = t->next;
                t->next = nn;
                nn->next = tn;
                break;
            }
            t = t->next;
        }
    }
}

void myLL::display(const int &size)
{
    if (!isEmpty())
    {
        Student *t = head;
        while (true)
        {
            t->displayStudentInfo(size);
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

int myLL::countList()
{
    int count = 0;
    if (!isEmpty())
    {
        Student *t = head;
        while (true)
        {
            count++;
            if (t->next == nullptr)
            {
                break;
            }
            t = t->next;
        }
    }
    return count;
}

Student *myLL::deleteFromHead()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return nullptr;
    }
    else
    {
        if (head == tail)
        {
            Student *rv = head;
            delete head;
            head = nullptr;
            tail = nullptr;
            return rv;
        }
        else
        {
            Student *rv = head;
            Student *t = head->next;
            delete head;
            head = t;
            return rv;
        }
    }
}

Student *myLL::deleteFromTail()
{
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return nullptr;
    }
    else
    {
        if (head == tail)
        {
            Student *rv = head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return rv;
        }
        else
        {
            Student *rv = head;
            Student *t = head;
            while (true)
            {
                if (t->next == tail)
                {
                    t = t->next;
                    break;
                }
            }
            delete tail;
            tail = t;
            tail->next = nullptr;
            return rv;
        }
    }
}

Student *myLL::deleteFromPos(const int &pos)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return nullptr;
    }
    else if (pos <= 0 || pos > countList())
    {
        cout << "Element not removed because Invalid position" << endl;
        return nullptr;
    }
    else if (pos == 1)
    {
        return deleteFromHead();
    }
    else if (pos == countList())
    {
        return deleteFromTail();
    }
    else
    {
        Student *t = head;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        Student *tn = t->next;
        Student *rv = tn;
        t->next = tn->next;
        delete tn;
        return rv;
    }
}

Student *myLL::searchValue(const int &value)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return nullptr;
    }
    else
    {
        Student *t = head;
        while (true)
        {
            if (t->rollNu == value)
            {
                return t;
                break;
            }
            if (t->next == nullptr)
            {
                cout << "value not exit in linked list" << endl;
                return nullptr;
            }
            t = t->next;
        }
    }
}

void myLL::updateStudentValue(const int &rn, const int *m, const string &n)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
    }
    else
    {
        Student *t = head;
        bool flag = false;
        while (true)
        {
            if (t->rollNu == rn)
            {
                for (int i = 0; i < 3; i++)
                {
                    t->marks[i] = m[i];
                }
                t->name = n;
                flag = true;
                break;
            }
            t = t->next;
        }
        if (flag == false)
        {
            cout << "roll No do not exist in LinkedList" << endl;
        }
    }
}

int totalMarks(int *marks, const int &size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += marks[i];
    }
    return sum;
}

int myLL::highMarks(const int &nfm)
{
    if (!isEmpty())
    {
        Student *t = head;
        int total = 0;
        while (true)
        {
            if (t == nullptr)
            {
                break;
            }
            int temp = totalMarks(t->marks, nfm);
            if (total < temp)
            {
                total = temp;
            }
            t = t->next;
        }
        return total;
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
        return -1;
    }
}

float myLL::avgMarks(const int &nfm)
{
    if (!isEmpty())
    {
        Student *t = head;
        float total = 0;
        while (true)
        {
            if (t == nullptr)
            {
                break;
            }
            total += totalMarks(t->marks, nfm);
            t = t->next;
        }
        return total / nfm;
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
        return -1;
    }
}

int myLL::lowMarks(const int &nfm)
{
    if (!isEmpty())
    {
        Student *t = head;
        int total = 100 * nfm;
        while (true)
        {
            if (t == nullptr)
            {
                break;
            }
            int temp = totalMarks(t->marks, nfm);
            if (total > temp)
            {
                total = temp;
            }
            t = t->next;
        }
        return total;
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
        return -1;
    }
}