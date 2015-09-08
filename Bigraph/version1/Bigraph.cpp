#include "Bigraph.h"
#include <iomanip>
#include <stdlib.h>
using namespace std;



/** public member function */

/** Ĭ�Ϲ��캯�� */
Bigraph::Bigraph()
{
    initialValue("input.txt", "output.txt");
}

/** �������Ĺ��캯��������Ϊ���롢����ļ��� */
Bigraph::Bigraph(const string fin, const string fout)
{
    initialValue(fin, fout);
}

void Bigraph::initialValue(const string fin, const string fout)
{
    inputFileName = fin;
    outputFileName = fout;
    isLoadData = loadData();
    found = false;
    deleteTempFile();    /// ɾ�������ļ�
}

/** ��Ļ��ʾ����ͼ�Ľṹ */
void Bigraph::displayArray()
{
    if(!isLoadData)
    {
        cout << "Not load the data" << endl;
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

/** ������ļ��ж�ȡ���ݣ�����Ļ��ʾ���ƥ��Ľ�� */
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

    if(!hasResult)    /// ɾ��������ļ�
    {
        cout << "No Solution!\n" << endl;
        string command = "del " + outputFileName;
        system(command.c_str());
        deleteTempFile();    /// ɾ���ջ����ļ�
    }
}

/** ��Ļ��ʾͼ�ṹ�����ƥ���� */
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

/** ���ض����Ƿ񴴽��ɹ� */
bool Bigraph::isValidObject()
{
    return isLoadData;
}

/** ʹ�ü��±��������ļ� */
void Bigraph::openInputFile()
{
    string com = "notepad " + inputFileName;
    system(com.c_str());
}

/** ʹ�ü��±�������ļ� */
void Bigraph::openOutputFile()
{
    execute();
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

/** �ж������ļ��Ƿ�Ϊ�� */
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



/** �ж��ļ��Ƿ��ܹ��� */
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

/** ����ļ��ĵ�һ������ */
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

/** ����ļ��б�ʾ�ߵ����ݣ��ڶ��п�ʼ�������ڶ��У� */
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

/** ���ļ���װ������ */
bool Bigraph::loadData()
{
    row = 0;
    column = 0;

    fstream input;
    input.open(inputFileName.c_str(), ios::in);

    if(!openFile(input, inputFileName))     /// �ļ�������
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
    input.close();      /// �ǵùر��ļ� time: 2013/7/16 9:45

    if(!isValidEnd)
    {
        cout << "file: " << inputFileName << " is not end with \"-1  -1\"" << endl;
    }

    return isValidEnd;
}

/** ���ö���ͼΪ������ͼ���ޱ�ͼ�� */
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

/** ����ĳһ�����Ƿ���ƥ�� */
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

/** ��ȡͬһ����һ��δƥ��ĵ� */
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

/** �ݹ飨����������ȣ�����ƥ�䣬�����д�뻺���ļ� */
void Bigraph::findMaxMatching(int currentRow, map<int, int> &resultMap)
{
    map<int, int> tempMap = resultMap;
    if(currentRow < row)
    {
        int j = getNext(currentRow, 0, resultMap);
        while(j != -1)
        {
            resultMap.insert(map<int, int>::value_type(currentRow + 1, j + row + 1));
            findMaxMatching(currentRow + 1, resultMap);    /// ������������ƥ��ֵ������������һ��
            j = getNext(currentRow, ++j, resultMap);
            resultMap = tempMap;    /// ��������ͬһ�е���һ��ƥ��ֵ
        }
        findMaxMatching(currentRow + 1, tempMap);      /// ��ǰ��û��ƥ��ֵ��������һ��
    }
    else
    {
        saveResult(resultMap);      /// ������������������ļ���
    }
}

/** �����ҵ���ƥ����д�뻺���ļ� */
void Bigraph::saveResult(map<int, int> &resultMap)
{
    fstream output;
    output.open(TEMP_FILE_NAME.c_str(), ios::out | ios::app);

    if(!Bigraph::openFile(output, TEMP_FILE_NAME))
    {
        return;
    }

    int size = resultMap.size();
    if(size > 0)
    {
        /// ��֪���������ʱд���ļ�������ȫ���������
        output << resultMap.size() << endl;
        map<int, int>::iterator p;
        for(p = resultMap.begin(); p != resultMap.end(); ++p)
        {
            output << p->first << " " << p->second << endl;
        }
        output << endl;
    }
    output.close();
}

/** ���������ļ�����ȡ����ƥ������ͽ�������� */
bool Bigraph::getMaxMatchingNumber(int &max, int &total)
{
    max = total = 0;
    fstream input;
    input.open(TEMP_FILE_NAME.c_str(), ios::in);

    if(!openFile(input, TEMP_FILE_NAME))
    {
        return false;
    }

    int tempMax = 0;
    input >> tempMax;

    while(!input.eof())
    {
        if(tempMax == max)
        {
            ++total;
        }
        if(tempMax > max)
        {
            max = tempMax;
            total = 1;
        }

        for(int k = 0; k < tempMax; ++k)
        {
            int i, j;
            input >> i >> j;
        }
        input >> tempMax;
    }
    input.close();

    return true;
}


/** �������ļ��е����ƥ����д�뵽����ļ��� */
void Bigraph::writeFile()
{
    int maxMatchingNum, count;
    bool isGet = getMaxMatchingNumber(maxMatchingNum, count);   /// ��ȡ����ƥ������ͽ��������

    fstream input;
    input.open(TEMP_FILE_NAME.c_str(), ios::in);    /// �򿪻����ļ�
    if(!openFile(input, TEMP_FILE_NAME))
    {
        return;
    }

    fstream output;
    output.open(outputFileName.c_str(), ios::out);    /// ������ļ�
    if(!openFile(input, outputFileName))
    {
        return;
    }

    if(isGet)
    {
        int tempMax = 0;
        input >> tempMax;
        int i, j;       /// ��¼�ļ���ƥ��ֵ
        int set = 0;    /// �Խ���ĸ�������
        while(!input.eof())
        {
            if(tempMax == maxMatchingNum)
            {
                found = true;       /// �ҵ����ƥ��
                output << "result #" << ++set << endl;
                output << maxMatchingNum << endl;   /// д�����ƥ����
                for(int k = 0; k < tempMax; ++k)
                {
                    input >> i >> j;
                    output << i << " " << j << endl;   /// д��ƥ��ֵ
                }
                output << endl;
            }
            else
            {
                for(int k = 0; k < tempMax; ++k)
                {
                    input >> i >> j;
                }
            }
            input >> tempMax;
        }
    }

    input.close();
    output.close();

    /// deleteTempFile();    /// ɾ�������ļ�
}

/** ɾ�������ļ�������ļ����� */
void Bigraph::deleteTempFile()
{
    fstream input;
    input.open(TEMP_FILE_NAME.c_str(), ios::in);
    if(!input.fail())
    {
        input.close();
        string command = "del " + TEMP_FILE_NAME;
        system(command.c_str());    /// ɾ�������ļ�
    }
}

/** ִ�������������� */
void Bigraph::execute()
{
    if(isLoadData)
    {
        map<int, int> newMap;
        findMaxMatching(0, newMap);
        writeFile();

        if(!found) {
            deleteTempFile();
            string command = "del " + outputFileName;
            system(command.c_str());    /// ɾ������ļ�
        }
    }
}
