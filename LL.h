#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNu;
    string name;
    int marks[50];
    Student *next;

    void displayStudentInfo(const int &size)
    {
        cout << rollNu << " ---> " << name << " --> [ ";
        for (int i = 0; i < size; i++)
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
    virtual void insertAtHead(const int &rn, const string &name, int *marks, const int &size) = 0;
    virtual void insertAtTail(const int &rn, const string &name, int *marks, const int &size) = 0;
    virtual void insertAfterRollNo(const int &rn, const string &name, int *marks, const int &posR, const int &size) = 0;
    virtual Student *deleteFromHead() = 0;
    virtual Student *deleteFromTail() = 0;
    virtual Student *deleteFromPos(const int &rn) = 0;
    virtual Student *searchValue(const int &rn) = 0;
    virtual void updateStudentValue(const int &rn, const int *m, const string &n) = 0;
    virtual bool isEmpty() = 0;
    virtual void display(const int &size) = 0;
    ~LL()
    {
        delete head;
        delete tail;
    }
};