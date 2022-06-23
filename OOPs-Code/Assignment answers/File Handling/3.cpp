#include <iostream>
#include <fstream>
#include <dirent.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir("D:\\Github Repo\\Programs\\OOPs-Code\\Assignment answers\\File Handling\\Files");

    // node*tail=NULL;
    cout << "copying file";
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {

            int l = strlen(dir->d_name);

            if (dir->d_name[l - 1] == 't' && dir->d_name[l - 2] == 'x')
            {

                ifstream ifiles1;
                fstream ifilet;

                char ch, fname1[100];

                strcpy(fname1, dir->d_name);
                cout<<fname1<<dir->d_name;

                ifiles1.open(fname1);
                // ifiles2.open(fname2);

                if (!ifiles1)
                {
                    perror("\nError Message in file1111 ");
                    cout << "\nPress any key to exit...\n";

                    exit(EXIT_FAILURE);
                }

                ifilet.open("lol.txt",  ios::out);

                if (!ifilet)
                {
                    perror("\nError Message ");
                    cout << "\nPress any key to exit...\n";

                    exit(EXIT_FAILURE);
                }

                while (ifiles1.eof() == 0)
                {
                    ifiles1.get(ch);
                    ifilet.put(ch);
                }

                ifilet << endl;


                ifiles1.close();
                ifilet.close();

            }
        }
        closedir(d);
        cout << endl
             << "file copied succesfully" << endl;
    }
    return 0;
}