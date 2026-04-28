#include"myLL.h"
#include<string>

int main(){
    myLL obj;
    int m[3] = {1,2,3};
    obj.insertAtHead(1,"Faheem Akram",m);
    obj.insertAtTail(2,"Akram",m);
    cout<<endl;
    obj.display();
    cout<<endl;
    obj.insertAfterRollNo(3,"Faheem",m,1);
    obj.display();

    cout<<endl;
    obj.insertAfterRollNo(4,"FA",m,2);
    obj.display();
}