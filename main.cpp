#include "myLL.h"
#include <string>

void menu()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "1 --> Enter a Student At start" << endl;
    cout << "2 --> Enter a Student At end" << endl;
    cout << "3 --> Enter a Student After a roll No" << endl;
    cout << "4 --> delete a student from start" << endl;
    cout << "5 --> delete a student from end" << endl;
    cout << "6 --> delete a student from specific position" << endl;
    cout << "7 --> Search Student" << endl;
    cout << "8 --> update Student Info" << endl;
    cout << "9 --> Highest Marks Student " << endl;
    cout << "10 --> Lowest Marks " << endl;
    cout << "11 --> Average Marks " << endl;
    cout << "12 --> display all Student's Info" << endl;
    cout << "13 --> exit" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void inputStudentInfo(string &n, int *arr, const int &size)
{
    cout << "Enter name : ";
    cin.ignore();
    getline(cin, n);
    cout << "Enter marks of all books : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    myLL obj;
    int nfm = 0;
    cout << "How many marks are upload : ";
    cin >> nfm;

    int choice = 0;
    string n;
    int rn;
    int *m = new int[nfm];

    while (true)
    {
        menu();
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter roll No : ";
            cin >> rn;
            inputStudentInfo(n, m, nfm);
            obj.insertAtHead(rn, n, m, nfm);
        }
        else if (choice == 2)
        {
            cout << "Enter roll No : ";
            cin >> rn;
            inputStudentInfo(n, m, nfm);
            obj.insertAtTail(rn, n, m, nfm);
        }
        else if (choice == 3)
        {
            int posR;
            cout << "Enter roll No from After insert : ";
            cin >> posR;
            cout << "Enter roll No : ";
            cin >> rn;
            inputStudentInfo(n, m, nfm);
            obj.insertAfterRollNo(rn, n, m, posR, nfm);
        }
        else if (choice == 4)
        {
            obj.deleteFromHead();
        }
        else if (choice == 5)
        {
            obj.deleteFromTail();
        }
        else if (choice == 6)
        {
            int p;
            cout << "Enter position where from delete student : ";
            cin >> p;
            obj.deleteFromPos(p);
        }
        else if (choice == 7)
        {
            int R;
            cout << "Enter roll No of student : ";
            cin >> R;

            obj.searchValue(R)->displayStudentInfo(nfm);
        }
        else if (choice == 8)
        {
            int R;
            cout << "Enter roll No of student : ";
            cin >> R;

            inputStudentInfo(n, m, nfm);
            obj.updateStudentValue(R, m, n);
        }

        else if (choice == 9)
        {
            cout << "Highest marks of Student : " << obj.highMarks(nfm) << endl;
        }
        else if (choice == 10)
        {
            cout << "lowest marks of Student : " << obj.lowMarks(nfm) << endl;
        }
        else if (choice == 11)
        {
            cout << "Average marks of Student : " << obj.avgMarks(nfm) << endl;
        }
        else if (choice == 12)
        {
            obj.display(nfm);
        }
        else if (choice == 13)
        {
            cout << "Program end !" << endl;
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}