/**
  time: 2013-7-16 14:09 - 17:02
        将函数封转成类。
        跟据输入的测试数据文件名和保存结果的输出文件名，
        定义一个对象，然后调用函数show就可得出结果。

  time: 2013-7-16 8:52
        根据输入的文件名，程序自动得出输出文件名，
        省去手动输入要输出的文件。

  time: 2013-7-18 8:40
        当二分图无边时，提示"No solution"，而且删除空的输出文件。

  time: 2013-7-18 8:55
        分离检查文本数据的代码，使得loadData函数代码行数减少。

  time: 2013-7-18 9:58
        程序开始运行时删除先前的缓存文件（如果文件存在），结束保存当前的缓存文件。

  time: 2013-7-18 11:17
        调整屏幕输出图结构，使其格式化。

  time: 2013-7-18 11:29
        删除空的缓存文件。

  time: 2013-7-18 14:57
        判断输入文件是否以"-1  -1"结束。

  time: 2013-7-18 15:47
        调用system命令打开或创建输入文件以及打开输出文件。

  time: 2013-7-18 16:34
        修正打开输出文件的Bug，当无输出文件时，说明无结果。

  time: 2013-7-19 am
        修正文件名的处理。

  time: 2013-7-19 16:42
        调整主程序的交互界面。


  声明：本程序的效率并不是很好。还可以进一步提高。
  具体操作：不要使用缓存文件，在类中定义两个变量，一个记录当前搜索到的
      结果中最大的匹配对数（初始化为0），另一个记录有几种符合的匹配对
      数（初始化为0），将每种符合的匹配值直接写入到输出文件中。最后根
      据最大匹配对数是否为0，来决定要不要删除输出文件。因为当最大匹配
      对数为0时，输出文件为空，所以删除掉输出文件。
 */


#ifndef BIGRAPH_H
#define BIGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;

const int MAX_SIZE = 100;
const string TEMP_FILE_NAME = "temp.txt";

class Bigraph
{
public:
    Bigraph();
    Bigraph(const string fin,const string fout);
    void initialValue(const string fin,const string fout);
    void displayArray();
    void displayResult();
    void show();
    bool isValidObject();
    void openInputFile();
    void openOutputFile();
    bool isEmptyInputFile();


private:
    bool openFile(fstream &ioFile, const string &fileName);
    bool isValidData(int first, int second);
    bool isValidData(int first, int second, int max, int lineNumber);
    bool loadData();
    void setZero();
    bool isInMap(int value, map<int, int> &resultMap);
    int getNext(int currentRow, int currentColumn, map<int, int> &resultMap);
    void findMaxMatching(int currentRow, map<int, int> &resultMap);
    void saveResult(map<int, int> &resultMap);
    bool getMaxMatchingNumber(int &max, int &total);
    void writeFile();
    void deleteTempFile();
    void execute();

    int data[MAX_SIZE][MAX_SIZE];   /// 存储二分图的二维数组
    int row;   /// 数组的实际行数
    int column;   /// 数组的实际列数
    bool isLoadData;     /// 文件可用状态
    bool found;
    string inputFileName;   /// 输入文件名
    string outputFileName;   /// 输出文件名
};

#endif // BIGRAPH_H
