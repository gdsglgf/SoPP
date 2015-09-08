#include <iostream>
#include "Bigraph.h"

using namespace std;

void showMessage();
string getInputFileName();
string getOutputFileName(string fin);
bool hasFilePostfix(string s);

int main()
{
    int choice;
    string inName;
    string outName;
    string com = "";
    Bigraph *g = NULL;
    while(true)
    {
        showMessage();
        cin >> choice;

        switch(choice)
        {
        case 0:
            cout << "program exit" << endl;
            return 0;

        case 1:
        {
            inName = getInputFileName();
            outName = getOutputFileName(inName);
            Bigraph graph(inName, outName);
            g = &graph;
            if(graph.isValidObject())
            {
                graph.displayArray();
            }
            break;
        }

        case 2:
            if(g != NULL)
            {
                (*g).openInputFile();
            }
            else
            {
                cout << "There is not last input file.\n" << endl;
            }
            break;

        case 3:
            if(g != NULL)
            {
                cout << endl;
                (*g).openOutputFile();
            }
            else
            {
                cout << "There is not last output file.\n" << endl;
            }
            break;

        default:
            cout << "error input: enter 0 or 1!\n" << endl;
        }
    }

    return 0;
}

/** 打印提示信息 */
void showMessage()
{
    cout << "**********Enter************************\n"
         << "*     0     *          exit           *\n"
         << "***************************************\n"
         << "*     1     *     new input file      *\n"
         << "***************************************\n"
         << "*     2     *  open last input file   *\n"
         << "***************************************\n"
         << "*     3     *  open last output file  *\n"
         << "***************************************\n" << endl;
}

/** 获取输入文件名 */
string getInputFileName()
{
    string name;
    cout << "Enter input file name: ";
    cin >> name;
    if(!hasFilePostfix(name))
    {
        name = name + ".txt";
    }
    return name;
}

/** 根据输入文件名得出输出文件名 */
string getOutputFileName(string fin)
{
    if(fin.compare("input") == 0 ||
            fin.compare("input.txt") == 0)
    {
        return "output.txt";
    }

    string fout = "outputOf" + fin;
    if(!hasFilePostfix(fin))
    {
        fout = fout + ".txt";
    }

    return fout;
}

/** 判断文件名是否有后缀名 */
bool hasFilePostfix(string s)
{
    int size = s.size();
    if(size < 5)
        return false;

    string temp = s.substr(size - 4);
    return (temp.compare(".txt") == 0);
}
