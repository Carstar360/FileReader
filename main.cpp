#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
        string fileName; //to get the name of the file to open
        string line; //to store a single line of a text file
        fstream fileStream; //to open a file for reading
        int lineAmount = ' ';
        int characters = ' ';
        characters = line.length();
        int counter = 0;
        char answer = ' ';

        do
        {
                cout<<"What file do you want to open? ";
                getline(cin, fileName);

                //STEP 1: open the fileStream for input, using the fileName specified

                fileStream.open (fileName.c_str(), ios::in);


                if(fileStream.is_open())
                {
                        cout<<fileName<<" opened.\nFILE CONTENTS:\n";


                        while(!fileStream.eof())
                        {
                                getline(fileStream, line);
                                line.length();
                                lineAmount++;

                                if (!line.empty())
                                {
                                        counter = counter + 1;
                                        characters = line.length() + characters;
                                        cout<<line<<endl;
                                }

                        }
                        fileStream.close();
                }
                else
                {
                        cout<<fileName<<" could not be opened.\n";
                }



                cout<<"METADATA"<<endl;
                cout<<"File: "<<fileName<<endl;
                cout<<"Lines: "<<counter<<endl;
                cout<<"Characters: "<<characters<<endl;

                cout<<"Analyze another file (y/n)?"<<endl;
                cin>>answer;
        }
        while(answer == 'y');

        //STEP 3: repeat the following until the end-of-file (eof) has been reached...

        // 3A: read a line from fileStream into the variable line


        // 3B: display the line, followed by an endline


        //STEP 4: close the fileStream




        return 0;
}
