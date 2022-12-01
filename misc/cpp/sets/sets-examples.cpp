#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    pair<set<int>::iterator, bool> ret;

    set<int>::iterator it;

    set<int> mySet;

    ret = mySet.insert(100); // This will be success

    if(ret.second)
    {
        cout << "inserted " << *(ret.first) <<endl;
    }


    ret = mySet.insert(100); // This will be success

    if(ret.second)
    {
        cout << "[again] inserted " << *(ret.first) <<endl;
    }

    ret = mySet.insert(300); // This will be success
    ret = mySet.insert(200); // This will be success
    ret = mySet.insert(500); // This will be success

    for(it = mySet.begin(); it != mySet.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}