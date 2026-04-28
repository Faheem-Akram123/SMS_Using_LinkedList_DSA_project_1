#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNu;
    string name;
    int marks[3];
    Student *next;

    void displayStudentInfo()
    {
        cout << rollNu << " ---> " << name << " --> [ ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "]" << endl;
    }
};

class LL
{
protected:
    Student *head;
    Student *tail;

public:
    LL()
    {
        head = nullptr;
        tail = nullptr;
    }
    virtual void insertAtHead(const int &rn, const string &name, int *marks) = 0;
    virtual void insertAtTail(const int &rn, const string &name, int *marks) = 0;
    virtual void insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR) = 0;
    // virtual int deleteFromHead() = 0;
    // virtual int deleteFromTail() = 0;
    // virtual int deleteFromPos(const int &rn) = 0;
    // virtual int searchValue(const int &rn) = 0;
    // virtual void updateStudentValue(const int &rn) = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    ~LL()
    {
        delete head;
        delete tail;
    }
};