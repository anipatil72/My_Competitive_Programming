#include <iostream>
using namespace std;

class student
{

public:
    int age;
    int roll_Number;

    static int totalStudents;

    student(int a, int r)
    {

        age = a;
        roll_Number = r;
        totalStudents++;
    }
};

int student ::totalStudents = 0;

int main()
{

    student s1(20, 34);
    cout << "The age of s1 is : " << s1.age << endl;
    cout << "The roll number of s1 is : " << s1.roll_Number << endl;
    cout << "The total number of students as of now are " << student ::totalStudents << endl;

    student s2(20, 72);

    cout << "The age of s2 is : " << s2.age << endl;
    cout << "The roll number of s2 is : " << s2.roll_Number << endl;

    cout << "The total number of students as of now are " << student ::totalStudents << endl;


    student s3(20, 66);

    cout << "The age of s2 is : " << s3.age << endl;
    cout << "The roll number of s2 is : " << s3.roll_Number << endl;

    cout << "The total number of students as of now are " << student ::totalStudents << endl;

    return 0;
}