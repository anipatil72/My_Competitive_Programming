#include <iostream>
#include <cstring>
using namespace std;

class student
{

public:
    int data;
    string id;

    student(int a, string c)
    {

        this->data = a;
        this->id = c;
    }
    //  student()
    //  {

    //  }
};

int main()
{

    student s1(1, "u7io");
    student *s2 = new student(20, "yyv48");

    //   s2->data = 12;

    cout << "The data for student S1 is " << s1.data << endl;
    cout << "The Id for student S1 is " << s1.id << endl;

    cout << "The data for student S2 is " << s2->data << endl;
    cout << "The Id for student S2 is " << s2->id << endl;

    return 0;
}