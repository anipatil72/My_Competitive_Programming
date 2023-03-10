#include <bits/stdc++.h>
using namespace std;

int uniqueMorseRepresentations(vector<string> &words)
{

    int n = words.size();

    vector<string> alpha = {".-",
                            "-...",
                            "-.-.",
                            "-..",
                            ".",
                            "..-.",
                            "--.",
                            "....",
                            "..",
                            ".---",
                            "-.-",
                            ".-..",
                            "--",
                            "-.",
                            "---",
                            ".--.",
                            "--.-",
                            ".-.",
                            "...",
                            "-",
                            "..-",
                            "...-",
                            ".--",
                            "-..-",
                            "-.--",
                            "--.."};

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
            string temp ="";

            for (int j = 0; j < words[i].length(); j++)
            {
                 temp+= alpha[words[i][j]-'a'];


            }


            m[temp]++;
            
    }

    return m.size();
    
}

int main()
{

    return 0;
}