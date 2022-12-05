#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define SIZE 26

using namespace std;

typedef pair<char, int> pair_char_int_t;
typedef unordered_map<char, pair_char_int_t> the_pairMap_t;

typedef vector<pair_char_int_t> the_pair_vector_t;

void put_random_char_in_map(the_pairMap_t& map){

    char c = (char)((rand() % (SIZE)) + 'a');
    the_pairMap_t::iterator it; 
    it = map.find(c);

    if(it == map.end())
    {
        map[c] = {c,1};

    }
    else
    {
        map[c].second++;

    }
}


void put_random_char_in_list( the_pair_vector_t& list){ 

    char c = (char)((rand() % (SIZE)) + 'a');
    list[c-'a'].first = c;
    list[c-'a'].second++;

}

bool comparePair(pair_char_int_t& p1, pair_char_int_t& p2)
{
    return p1.second < p2.second;
} 

void vector_test(void){

    the_pair_vector_t list = {26, {'-',0}}; // create a vector with 26 pairs

    the_pair_vector_t::iterator it;

    for(int i = 0; i<1000;i++)
    {
        put_random_char_in_list(list);
    }

    for(it=list.begin(); it!= list.end(); it++)
    {
        cout<< (*it).first << " : " << (*it).second << endl;
    }

    sort(list.begin(), list.end(), comparePair);

    printf("Sorted List ");

    for(it=list.begin(); it!= list.end(); it++)
    {
        cout<< (*it).first << " : " << (*it).second << endl;
    }

    string str;
    for(it=list.end(); it!= list.begin(); it--)
    {
        char c = (*it).first;
        int count =  (*it).second;

        for(int i = 0; i < count; i++)
        {
            str.append(c);
        }

    }
    printf(str);


}



int main()
{
   the_pairMap_t map;
   int i = 0;
   for(i=0;i<1000;i++)
   {
        put_random_char_in_map(map);
   }


    
    the_pairMap_t::iterator it; 
    for(it = map.begin(); it!= map.end();it++)
    {
        cout << (*it).first << " count: "<< (*it).second.second <<endl; 
    }
    
    vector_test();


    return 0;
}