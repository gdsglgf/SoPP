#ifndef BIGRAPH_H
#define BIGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;


class Bigraph
{
public:
    static int MAX_SIZE;

    Bigraph();
    Bigraph(const string fin,const string fout);
    void initialValue(const string fin,const string fout);
    ~Bigraph();
    void displayArray();
    void displayResult();
    void show();
    bool isValidObject();
    void openInputFile();
    void openOutputFile();
    bool isEmptyInputFile();
    void execute();

private:
    void createSpace();
    bool openFile(fstream &ioFile, const string &fileName);
    bool isValidData(int first, int second);
    bool isValidData(int first, int second, int max, int lineNumber);
    bool loadData();
    void setZero();
    bool isInMap(int value, map<int, int> &resultMap);
    int getNext(int currentRow, int currentColumn, map<int, int> &resultMap);
    void findMaxMatching(int currentRow, map<int, int> &resultMap);
    void saveResult(map<int, int> &resultMap);
    void writeFile(fstream &output, map<int, int> &resultMap);
    //void execute();

    int **data;   /// 存储二分图的二维数组
    int row;   /// 数组的实际行数
    int column;   /// 数组的实际列数
    bool isLoadData;     /// 文件可用状态
    bool found;
    string inputFileName;   /// 输入文件名
    string outputFileName;   /// 输出文件名
    int maxMatchingNum;
    int numberOfMax;
};

#endif // BIGRAPH_H
