#include <iostream>
#include <string>
#include <set>

using namespace std;

void addStrToSet(string str, set<char>& st)
{
	size_t i = 0;
	for(i=0; i<str.length();i++)
	{
		st.insert(str[i]);
	}
}

void set_strings(void)
{
   string str1 = "abab";
   cout << str1 << endl;
   
   set<char> setStr;
   set<char>::iterator it;;
   
   addStrToSet("abab", setStr);

   it = setStr.begin();
   while(it != setStr.end())
   {
       cout << *it << endl;
       it++;       
   }
    
}

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
    
    set_strings();

    return 0;
}
