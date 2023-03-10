#include <iostream>
#include <string.h>
using namespace std;

bool IsPalindrome(char *beg, char *end)
{

    if ((beg == end))
    {
        return 1;
    }
    if ((beg == end - 1) && (*beg == *end))
    {
        return 1;
    }

    if ((*beg == *end) && IsPalindrome(beg + 1, end - 1))
    {
        return 1;
    }

    return 0;
}

int main()
{

    char str[100];

    cin >> str;

    int n = strlen(str);
   // cout << n << endl;

    char *beg = str;
    char *end = &str[n - 1];

    // printf("%d\n", beg);
    // printf("%d\n", end);

    if (IsPalindrome(beg, end))
    {

        printf("The Given string is a Palindrome\n");
    }
    else if (IsPalindrome(beg, end) == 0)
    {

        printf("The Given string is not a Palindrome\n");
    }

    return 0;
}