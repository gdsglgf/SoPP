/**
  time: 2013-7-16 14:09 - 17:02
        ��������ת���ࡣ
        ��������Ĳ��������ļ����ͱ�����������ļ�����
        ����һ������Ȼ����ú���show�Ϳɵó������

  time: 2013-7-16 8:52
        ����������ļ����������Զ��ó�����ļ�����
        ʡȥ�ֶ�����Ҫ������ļ���

  time: 2013-7-18 8:40
        ������ͼ�ޱ�ʱ����ʾ"No solution"������ɾ���յ�����ļ���

  time: 2013-7-18 8:55
        �������ı����ݵĴ��룬ʹ��loadData���������������١�

  time: 2013-7-18 9:58
        ����ʼ����ʱɾ����ǰ�Ļ����ļ�������ļ����ڣ����������浱ǰ�Ļ����ļ���

  time: 2013-7-18 11:17
        ������Ļ���ͼ�ṹ��ʹ���ʽ����

  time: 2013-7-18 11:29
        ɾ���յĻ����ļ���

  time: 2013-7-18 14:57
        �ж������ļ��Ƿ���"-1  -1"������

  time: 2013-7-18 15:47
        ����system����򿪻򴴽������ļ��Լ�������ļ���

  time: 2013-7-18 16:34
        ����������ļ���Bug����������ļ�ʱ��˵���޽����

  time: 2013-7-19 am
        �����ļ����Ĵ���

  time: 2013-7-19 16:42
        ����������Ľ������档


  �������������Ч�ʲ����Ǻܺá������Խ�һ����ߡ�
  �����������Ҫʹ�û����ļ��������ж�������������һ����¼��ǰ��������
      ���������ƥ���������ʼ��Ϊ0������һ����¼�м��ַ��ϵ�ƥ���
      ������ʼ��Ϊ0������ÿ�ַ��ϵ�ƥ��ֱֵ��д�뵽����ļ��С�����
      �����ƥ������Ƿ�Ϊ0��������Ҫ��Ҫɾ������ļ�����Ϊ�����ƥ��
      ����Ϊ0ʱ������ļ�Ϊ�գ�����ɾ��������ļ���
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

    int data[MAX_SIZE][MAX_SIZE];   /// �洢����ͼ�Ķ�ά����
    int row;   /// �����ʵ������
    int column;   /// �����ʵ������
    bool isLoadData;     /// �ļ�����״̬
    bool found;
    string inputFileName;   /// �����ļ���
    string outputFileName;   /// ����ļ���
};

#endif // BIGRAPH_H
