#include <iostream>

using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::string;
// vector behind the scene uses DMA to scale up and down
int main()
{
    int scores[]{1, 2, 3, 4, -1};
    int *scoresPtr{scores};
    while (*scoresPtr != -1)
    {
        cout << *scoresPtr << endl;
        scoresPtr++;
    }
    //! OR
    /*
    scoresPtr = scores;
    while (*scoresPtr != -1)
    {
        cout << *scoresPtr++ << endl;
    }
    */
    string s1{"Frank"};
    string s2{"Frank"};
    string s3{"James"};

    string *p1 = &s1;
    string *p2 = &s2;
    string *p3 = &s1;

    cout << boolalpha;
    cout << (p1 == p2) << endl;
    cout << (p1 == p3) << endl;

    cout << (*p1 == *p2) << endl;
    cout << (*p1 == *p3) << endl;
    cout << endl;

    char name[] = {"rank"};    // c style string
    char *charPtr1 = &name[0]; // or name
    char *charPtr2 = &name[3];
    cout << (charPtr1 - charPtr2) << endl; // difference is 3 characters

    return 0;
}