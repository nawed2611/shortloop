#include<iostream>
#include<string>

using namespace std;

string ques(string n)
{
    string directory = "/";
    string files = "abc.txt\ndef.txt\n";

    for(int i = 0; n[i] != '\0'; i++)
    {
        // pwd
        if(n[i] == 'p' && n[i+1] == 'w' && n[i+2] == 'd')
        {   
            if(directory == "")
            cout <<endl;
            else
            cout << directory<<endl;
            i += 2;
        }

        // mkdir
        if(n[i] == 'm' && n[i+1] == 'k' && n[i+2] == 'd' && n[i+3] == 'i' && n[i+4] == 'r')
        {
            string temp = "";
            i += 5;

            while(n[i] != '\n')
            {
                temp += n[i];
                i++;
            }
        }

        // cd
        if(n[i] == 'c' && n[i+1] == 'd')
        {
            string temp = "";
            i += 3;


            // checking if cd .. is given
            if(n[i] == '.' && n[i+1] == '.')
            {   
                int j = directory.length() - 1;

                while(directory[j] != '/')
                {
                    j--;
                }
                directory.erase(j);
            }
            else{
                while(n[i] != '\n')
                {
                    temp += n[i];
                    i++;                
                }
                directory += temp;
                directory += "/";
            }
            
        }

        // ls
        if(n[i] == 'l' && n[i+1] == 's')
       {
            i += 1;
            cout <<files;

       }

       // mv
         if(n[i] == 'm' && n[i+1] == 'v')
         {
              string src = "";
              string dest = "";
              i += 3;
    
              while(n[i] != ' ')
              {
                src += n[i];
                i++;
              }

              while(n[i] != '\n')
              {
                dest += n[i];
                i++;
              }
         }
    }

    return directory;
}

int main()
{
    string s = "pwd\n mkdir abc\n cd abc\n pwd\n ls\n cd ..\n pwd\n mkdir def\n";

    ques(s);
    return 0;
}
