#include "Bigraph.h"
#include <stdlib.h>    /// include the system command
#include <iomanip>
using namespace std;

int counter = 0;    /// 全局变量，记录搜索的次数

int Bigraph::MAX_SIZE = 100;

/** public member function */

/** 默认构造函数 */
Bigraph::Bigraph()
{
    initialValue("input.txt", "output.txt");
}

/** 带参数的构造函数，参数为输入、输出文件名 */
Bigraph::Bigraph(const string fin, const string fout)
{
    initialValue(fin, fout);
}

void Bigraph::initialValue(const string fin, const string fout)
{
    data = NULL;
    inputFileName = fin;
    outputFileName = fout;
    isLoadData = loadData();
    found = false;
    maxMatchingNum = 0;
    numberOfMax = 0;
}


Bigraph::~Bigraph()
{
    if(data != NULL)
    {
        for(int i = 0; i < row; ++i)
        {
            delete [] data[i];
            //cout << "delete [] data[" << i << "]" << endl;
        }
        delete [] data;
        //cout << "delete [] data" << endl;
    }
}

/** 屏幕显示二分图的结构 */
void Bigraph::displayArray()
{
    if(!isLoadData)
    {
        cout << "Not load the data" << endl;
        return;
    }
    int i, j;
    cout << "   | ";
    for(i = row + 1; i <= row + column; ++i)
    {
        cout << setw(2) << i << " ";
    }
    cout << endl;
    for(j = 0; j < column * 3 + 4; ++j)
    {
        cout << "-";
    }
    cout << endl;

    for(i = 0; i < row; ++i)
    {
        cout << setw(2) << i + 1 << " | ";
        for(j = 0; j < column; ++j)
        {
            cout << setw(2) << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/** 从输出文件中读取数据，在屏幕显示最大匹配的结果 */
void Bigraph::displayResult()
{
    fstream input;
    input.open(outputFileName.c_str(), ios::in);
    if(!openFile(input, outputFileName))
    {
        return;
    }

    bool hasResult = false;

    string str;
    input >> str;
    string sign;
    input >> sign;
    int count;
    input >> count;
    while(!input.eof())
    {
        hasResult = true;
        cout << str;
        cout << " " << sign << endl;
        int a, b;
        cout << count << endl;
        for(int i = 0; i < count; ++i)
        {
            input >> a >> b;
            cout << a << " " << b << endl;
        }
        cout << endl;

        input >> str;
        input >> sign;
        input >> count;
    }

    input.close();

    if(!hasResult)    /// 删除空输出文件
    {
        cout << "No Solution!\n" << endl;
        string command = "del " + outputFileName;
        system(command.c_str());
    }
}

/** 屏幕显示图结构和最大匹配结果 */
void Bigraph::show()
{
    if(isLoadData)
    {
        cout << "\nrow = " << row << ", column = " << column << endl;
        cout << endl;
        displayArray();

        execute();
        displayResult();
    }
    else
    {
        cout << "No Solution!\n" << endl;
    }
}

/** 返回对象是否创建成功 */
bool Bigraph::isValidObject()
{
    return isLoadData;
}

/** 使用记事本打开输入文件 */
void Bigraph::openInputFile()
{
    string com = "notepad " + inputFileName;
    system(com.c_str());
}

/** 使用记事本打开输出文件 */
void Bigraph::openOutputFile()
{
    execute();
    //cout << "found = " << (found ? "true" : "false") << endl;
    if(found)
    {
        string com = "notepad " + outputFileName;
        system(com.c_str());
    }
    else
    {
        cout << "No Solution!" << endl;
        cout << "There is not output file.\n" << endl;
    }
}

/** 判断输入文件是否为空 */
bool Bigraph::isEmptyInputFile()
{
    fstream input;
    input.open(inputFileName.c_str(), ios::in);
    bool isEmpty = true;
    while(!input.eof())
    {
        int i;
        input >> i;
        if(input.tellg() > 0)
        {
            isEmpty = false;
            input.close();
            break;
        }
    }
    return isEmpty;
}


/** private member function */


void Bigraph::createSpace()
{
    data = new int*[row];
    for(int i = 0; i < row; ++i)
    {
        data[i] = new int[column];
        //cout << "data[" << i << "] = new int[" << column << "]" << endl;
    }
}

/** 判断文件是否能够打开 */
bool Bigraph::openFile(fstream &ioFile, const string &fileName)
{
    bool isOpen = true;
    if(ioFile.fail())
    {
        cout << "file: " << fileName << " does not exist\n" << endl;
        isOpen = false;
    }
    return isOpen;
}

/** 检查文件的第一行数据 */
bool Bigraph::isValidData(int first, int second)
{
    if(first <= 0 || second >= MAX_SIZE || first >= second || second <= 0 || second >= MAX_SIZE)
    {
        if(first <= 0)
        {
            cout << "first data error: " << first << " <= 0" << endl;
        }
        if(first >= MAX_SIZE)
        {
            cout << "first data error: " << first << " >= " << MAX_SIZE << endl;
        }
        if(second <= 0)
        {
            cout << "second data error: " << second << " <= 0" << endl;
        }
        if(second >= MAX_SIZE)
        {
            cout << "second data error: " << second << " >= " << MAX_SIZE << endl;
        }
        if(first >= second)
        {
            cout << "first data >= second data error: " << first << " >= " << second << endl;
        }

        cout << "at line #1 in file: " << inputFileName << endl;
        return false;
    }
    return true;
}

/** 检查文件中表示边的数据（第二行开始到倒数第二行） */
bool Bigraph::isValidData(int first, int second, int max, int lineNumber)
{
    if(first > 0 && first <= row && second > row && second <= max)
    {
        if(data[first - 1][second - row - 1] == 1)
        {
            cout << "Duplicate data at line #" << lineNumber
                 << " in file: " << inputFileName << endl;
            return false;
        }
        return true;
    }
    else
    {
        if(first <= 0)
        {
            cout << "first data error: " << first << " <= 0" << endl;
        }
        if(first > row)
        {
            cout << "first data error: " << first << " > " << row << endl;
        }
        if(second <= row)
        {
            cout << "second data error: " << second << " <= " << row << endl;
        }
        if(second > max)
        {
            cout << "second data error: " << second << " > " << max << endl;
        }

        cout << "at line #" << lineNumber << " in file: "
             << inputFileName <<  endl;
        return false;
    }
}

/** 从文件中装载数据 */
bool Bigraph::loadData()
{
    row = 0;
    column = 0;

    fstream input;
    input.open(inputFileName.c_str(), ios::in);

    if(!openFile(input, inputFileName))     /// 文件不存在
    {
        openInputFile();
        return false;
    }

    if(isEmptyInputFile())
    {
        cout << "the input file: " << inputFileName << " is empty" << endl;
        return false;
    }

    int max;
    input >> row >> max;
    int line = 1;
    if(!isValidData(row, max))
    {
        return false;
    }

    column = max - row;
    createSpace();
    setZero();

    int i, j;
    int isValidEnd = false;
    while(!input.eof())
    {
        input >> i >> j;
        ++line;
        if(i == -1 && j == -1)
        {
            isValidEnd = true;
            break;  /// end of file
        }

        if(isValidData(i, j, max, line))
        {
            data[i - 1][j - row - 1] = 1;
        }
        else
        {
            return false;
        }
    }
    input.close();      /// 记得关闭文件 time: 2013/7/16 9:45

    if(!isValidEnd)
    {
        cout << "file: " << inputFileName << " is not end with \"-1  -1\"" << endl;
    }

    return isValidEnd;
}

/** 设置二分图为孤立的图（无边图） */
void Bigraph::setZero()
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < column; ++j)
        {
            data[i][j] = 0;
        }
    }
}

/** 查找某一个点是否已匹配 */
bool Bigraph::isInMap(int value, map<int, int> &resultMap)
{
    map<int, int>::iterator p;
    bool hasValue = false;
    for(p = resultMap.begin(); p != resultMap.end(); ++p)
    {
        if(value == p->second)
        {
            return true;    //hasValue = true;  //break;
        }
    }
    return hasValue;
}

/** 获取同一行下一个未匹配的点 */
int Bigraph::getNext(int currentRow, int currentColumn, map<int, int> &resultMap)
{
    for(int j = currentColumn; j < column; ++j)
    {
        if(data[currentRow][j] == 1)
        {
            if(isInMap(j + row + 1, resultMap) == false)
            {
                return j;
            }
        }
    }
    return -1;
}

/** 递归（必须深度优先）查找匹配，将结果写入缓存文件 */
void Bigraph::findMaxMatching(int currentRow, map<int, int> &resultMap)
{
    map<int, int> tempMap = resultMap;
    if(currentRow < row)
    {
        int j = getNext(currentRow, 0, resultMap);
        while(j != -1)
        {
            resultMap.insert(map<int, int>::value_type(currentRow + 1, j + row + 1));
            findMaxMatching(currentRow + 1, resultMap);    /// 插入搜索到的匹配值，继续搜索下一行
            j = getNext(currentRow, ++j, resultMap);
            resultMap = tempMap;    /// 继续搜索同一行的下一个匹配值
        }
        findMaxMatching(currentRow + 1, tempMap);      /// 当前行没有匹配值，搜索下一行
    }
    else
    {
        ++counter;      /// 统计搜索的次数
        saveResult(resultMap);      /// 保存搜索结果到缓存文件中
    }
}

/** 将查找到的匹配结果写入输出文件 */
void Bigraph::saveResult(map<int, int> &resultMap)
{
    int size = resultMap.size();
    if(size == 0)
    {
        return;
    }

    fstream output;
    if(size > maxMatchingNum)
    {
        /// 写入当前搜素到最大匹配到输出文件,删除先前的输出文件(覆盖掉之前数据)
        maxMatchingNum = size;
        output.open(outputFileName.c_str(), ios::out);
        numberOfMax = 1;
    }
    else if(size == maxMatchingNum)
    {
        output.open(outputFileName.c_str(), ios::out | ios::app);
        ++numberOfMax;
    }
    writeFile(output, resultMap);
}

void Bigraph::writeFile(fstream &output, map<int, int> &resultMap)
{
    found = true;
    output << "result #" << numberOfMax << endl;
    output << resultMap.size() << endl;
    map<int, int>::iterator p;
    for(p = resultMap.begin(); p != resultMap.end(); ++p)
    {
        output << p->first << " " << p->second << endl;
    }
    output << endl;
    output.close();
}

/** 执行搜索，保存结果 */
void Bigraph::execute()
{
    if(isLoadData)
    {
        map<int, int> newMap;
        findMaxMatching(0, newMap);
    }
}
