#include <iostream>
#include <fstream>
#include <dirent.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    DIR *d;
    struct dirent *dir;
    d = opendir("D:\\Github Repo\\Programs\\OOPs-Code\\Assignment answers\\File Handling\\Files");

    // node*tail=NULL;
    cout << "copying file";
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_name == "midQues.txt")
                continue;
            int l = strlen(dir->d_name);
            ofstream fout;
            fout.open("midQues.txt", ios::app);

            if (dir->d_name[l - 1] == 't' && dir->d_name[l - 2] == 'x')
            {

                fstream fin;
                string line;
                fin.open(dir->d_name);

                getline(fin, line);
                fstream fout;
                cout << ". ";
                fout.open("midQues.txt", ios::app);

                fout << line << endl;

                fin.close();
            }

            // printf("%s\n",dir->d_name);
        }

        closedir(d);
        cout << endl
             << "file copied succesfully" << endl;
    }
    return 0;
}