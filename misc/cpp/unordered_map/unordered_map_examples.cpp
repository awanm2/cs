#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> umapRGB;
    
    // Add elements to the map
    umapRGB["RED"] = "#FF0000";
    umapRGB["BLUE"]=  "#0000FF";
    umapRGB["GREEN"] = "#00FF00";
    umapRGB.insert({"YELLOW" , "#FFFF00"});
    
    // Declare an iterator
    unordered_map<string, string>::iterator it;
    
    // Now loop through the itreator.
    for(it = umapRGB.begin(); it != umapRGB.end(); it++)
    {
        cout << it->first << " :" << it->second << endl;
    }


    cout << "-----" << endl;
    // Add more  entries to the unordered_map
    umapRGB["BLACK"] = "#000000";
    umapRGB["WHITE"] = "#FFFFFF";
    
    // Now loop through the itreator.
    for(it = umapRGB.begin(); it != umapRGB.end(); it++)
    {
        cout << it->first << " :" << it->second << endl;
    }

    return 0;
}
