/* 

*********************** LINK :- https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/

 It processes the pattern and creates different arrays for each of the two heuristics. At every step, it slides the pattern by the max of the slides suggested by each of the two heuristics. Boyer Moore algorithm starts matching from the last character of the pattern.
Boyer Moore is a combination of the following two approaches. 

1. Bad Character Heuristic 

    bad match array fill formulae = length of pattern -index of character in pattern -1 or as given in bellow code

2. Good Suffix Heuristic 

*/

#include<bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic(string pat,int m,int badchar[]){
    int i;
 
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < m; i++)
        badchar[(int) pat[i]] = i;
}

void search(string txt , string pat){
    int n = txt.size();
    int m = pat.size();

    int badChar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badChar);

    int s =0;

    while(s<(n-m)){
        int j = m-1;

        while(j >= 0 && pat[j] == txt[s + j])
            j--;

        if(j<0){
            cout << "pattern occurs at shift = " <<  s << endl;
            s += (s + m < n)? m-badChar[txt[s + m]] : 1;
        }
        else{
             s += max(1, j - badChar[txt[s + j]]);
        }
    }
}

int main(){
    string txt= "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
    return 0;
}