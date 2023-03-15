#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
int option;
FILE *fl;
string line, word, f_word, r_word, filename, str, test = "C:/Users/kkaym/OneDrive/Desktop/Codeblocks Projects/Excel File Handling/data/excel file data/test", csv = ".csv";
vector<vector<string>> content;
vector<string> row;
struct test_data
{
    string name;
    long unsigned int number, age, salary;
};
struct test_data obj[30];
struct logic
{
    int c = 0;
};
struct logic obj1;

int main()
{
    do
    {
        int k = 0;
        cout<<"\n"<<endl;
        cout<<"                              Data Warehouse\n\n"<<endl;
        cout<<"\t   [1]Store Data in Excel                   [2]View Data in Excel                     [999]Exit\n"<<endl;
        cout<<"\t   <<Enter choice>>"<<endl;
        cin>>option;
        if(option == 1)
        {
            system("CLS");
            cout<<"\n"<<endl;
            fl=fopen("C:/Users/kkaym/OneDrive/Desktop/Codeblocks Projects/Excel File Handling/data/text file data/test_logic.txt", "rb");//open and read logic text file
            while(fread(&obj1, sizeof(obj1), 1, fl))
            {
                k = obj1.c;
            }
            fclose(fl);//close logic text file
            fl=fopen("C:/Users/kkaym/OneDrive/Desktop/Codeblocks Projects/Excel File Handling/data/text file data/test_memory.txt", "ab"); //Open and write data text File
            if(fl)
            {
                cout<<"  "<<k<<" Enter Your Full Name"<<endl;
                cin>>f_word;
                getline(cin, r_word);
                obj[k].name = f_word + r_word;
                cout<<"\n  "<<k<<" Enter Your Age"<<endl;
                cin>>obj[k].age;
                cout<<"\n  "<<k<<" Enter Your Salary"<<endl;
                cin>>obj[k].salary;

                obj[k].number = k;
                stringstream ss;
                ss << k;
                str = ss.str();
                filename = test + str + csv;
                cout<< filename <<endl;
                ofstream MyExcelFile;
                MyExcelFile.open(filename);//open and write csv data file
                MyExcelFile << "Id, Name, Age, Salary" <<endl;
                MyExcelFile << obj[k].number << ", " << obj[k].name << ", " << obj[k].age << ", " << obj[k].salary <<endl;
                MyExcelFile.close();//close csv data file

                fl=fopen("C:/Users/kkaym/OneDrive/Desktop/Codeblocks Projects/Excel File Handling/data/text file data/test_logic.txt", "ab");//open and write logic text file
                obj1.c++;
                fflush(stdin);
                fwrite(&obj1, sizeof(obj1), 1, fl);
                fclose(fl);//close logic text file
            }
            else
            {
                system("color 6");
                cout<<"\n\n\t\t\t<<<<<<<<<<<<<< PROGRAM DID NOT OPEN PROPERLY --------- RESTARTING >>>>>>>>>>>>>>>\n";
                Sleep(2000);
                system("CLS");
                fclose(fl);//close data text file
            }
        }
        else if(option == 2)
        {
            system("CLS");
            fstream file("C:/Users/kkaym/OneDrive/Desktop/Codeblocks Projects/Excel File Handling/data/Data Source/Test Original.csv", ios::in); //Open and read data text File
            if(file.is_open())
            {
                while(getline(file, line))
                {
                    row.clear();
                    stringstream str(line);
                    while(getline(str, word, ','))
                    {
                        row.push_back(word);
                    }
                    content.push_back(row);
                }
                for(unsigned int i = 1; i < content.size(); i++)
                {
                    for(unsigned int j = 0; j < content[i].size(); j++)
                    {
                        cout<<content[i][j]<<"\n";
                    }
                }
            }
            else
            {
                system("color 6");
                cout<<"\n\n\t\t\t<<<<<<<<<<<<<< PROGRAM DID NOT OPEN PROPERLY --------- RESTARTING >>>>>>>>>>>>>>>\n";
                Sleep(2000);
                system("CLS");
                file.close();
            }
        }
        else if(option == 999)
        {
            system("PAUSE");
            system("CLS");
            break;
        }
        else
        {
            system("color 6");
            cout<<"\n"<<endl;
            cout<<"\t   Sorry Invalid.....Try Again....."<<endl;
        }
        system("PAUSE");
        system("CLS");
    }while(1);
    return 0;
}
