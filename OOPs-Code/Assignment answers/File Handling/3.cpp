// ****************NOTE  THIS CODE IS NOT WORKING ********************************************

#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sys/types.h>
#include <string>
#include <cstring>
using namespace std;

bool checkTXTfile(string fn)
{
    if (fn.substr(fn.find_last_of(".") + 1) == "txt")
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main(void)
{
    fstream mainFile;
    mainFile.open("mainFile.txt" , ios::out | ios::app);
    DIR *d;
    struct dirent *dir;
    d = opendir("D:\\Github Repo\\Programs\\OOPs-Code\\Assignment answers\\File Handling\\Files");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(checkTXTfile(dir->d_name)){
                ifstream file;
                string str;
                file.open( dir->d_name , ios::in);
                if(!file){
                    cout<<"Unable to open :-"<<dir->d_name<<endl;
                    continue;
                }
                while (file)
                {
                    char c;
                    file.get(c);
                    mainFile.put(c);
                }
                cout<<"Succesfully copied :- "<<dir->d_name<<endl;
                file.close();
            }
        }
        closedir(d);
    }

    mainFile.close();
 

    return 0;
}

// ****************NOTE  THIS CODE IS NOT WORKING ********************************************
