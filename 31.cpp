#include <iostream>
#include <cstring>
using namespace std;

class student
{

public:
    int age;
    char *name;

    student()
    {
    }

    student(const student &s)
    {
        this->age = s.age;
        // this->name = s.name;

        this->name = new char[strlen(s.name) + 1];

        strcpy(this->name, s.name);
    }
};

int main()
{

    char name[] = "abcd";

    student s1;

    s1.age = 20;
    s1.name = name;

    student s2(s1);

    name[2] = 'r';

    cout << s1.age << endl;
    cout << s2.age << endl;

    cout << s1.name << endl;
    cout << s2.name << endl;

    return 0;
}