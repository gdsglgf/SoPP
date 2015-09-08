#include "function.h"

/** 输入一维数组数据 */
void inputData(ifstream &in, int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		in >> array[i] ;
	}
}

/** 输入二维数组数据 */
void inputData(ifstream &in, int array[][MAX_SIZE], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		inputData(in, array[i], column);
	}
}

/** 设置数组的默认值为0 */
void setZero(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

/** first oper= second */
void computeArray(int *first, int *second, int size, char oper)
{
    switch(oper)
    {
    case '+':
        for (int i = 0; i < size; i++)
        {
            first[i] += second[i];
        }
        break;

    case '-':
        for (int i = 0; i < size; i++)
        {
            first[i] -= second[i];
        }
        break;
    }
}

/** 二维数组计算 */
void computeArray(int result[][MAX_SIZE], int first[][MAX_SIZE], int second[][MAX_SIZE],
                  int row, int column, char oper)
{
    switch(oper)
    {
    case '+':
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result[i][j] = first[i][j] + second[i][j];
            }
        }
        break;

    case '-':
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result[i][j] = first[i][j] - second[i][j];
            }
        }
        break;
    }
}

/** 比较两个一维数组的大小 */
bool isNotGreater(int *first, int *second, int size)
{
    bool result = true;
    for (int i = 0; i < size; i++)
    {
        if (first[i] > second[i])
        {
            result = false;
            break;
        }
    }
    return result;
}

/** 输入某一个进程的请求向量 */
int inputRequest(int Request[][MAX_SIZE], int row, int column)
{
    cout << "Enter the ID of the process [0 - " << row - 1 << "]: ";
    int process_id;
    cin >> process_id;
    cout << "Enter Request" << process_id << "(" << column << " positive integer(s)): ";
    for (int i = 0; i < column; i++)
    {
        cin >> Request[process_id][i];
    }

    return process_id;
}

/** 安全性算法 */
bool isSafe(int *Available, int Need[][MAX_SIZE], int *Finish, int Allocation[][MAX_SIZE],
            int process_num, int resources_num)
{
    int order = 1;
    while (true)
    {
        int tmp = order;
        // 从第一个进程开始查找可以分配资源且可以执行的进程
        for (int i = 0; i < process_num; i++)
        {
            // 进程i没有执行
            if (Finish[i] == 0)
            {
                // 需求资源向量小于或等于可利用资源向量
                if (isNotGreater(Need[i], Available, resources_num))
                {
                    computeArray(Available, Allocation[i], resources_num, '+');
                    Finish[i] = order++;
                }
            }
        }
        if (tmp == order)
            break;
    }
    return (order - 1 == process_num);
}

/** 打印安全序列 */
void printSafeList(int *Finish, int process_num)
{
    cout << "\nThe order of the process executing" << endl;
    cout << "process  |  order" << endl;
    for (int i = 0; i < process_num; i++)
    {
        cout << "p" << i << "\t |\t" << Finish[i] << endl;
    }
}
