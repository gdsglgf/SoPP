#include "function.h"

/** ����һά�������� */
void inputData(ifstream &in, int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		in >> array[i] ;
	}
}

/** �����ά�������� */
void inputData(ifstream &in, int array[][MAX_SIZE], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		inputData(in, array[i], column);
	}
}

/** ���������Ĭ��ֵΪ0 */
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

/** ��ά������� */
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

/** �Ƚ�����һά����Ĵ�С */
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

/** ����ĳһ�����̵��������� */
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

/** ��ȫ���㷨 */
bool isSafe(int *Available, int Need[][MAX_SIZE], int *Finish, int Allocation[][MAX_SIZE],
            int process_num, int resources_num)
{
    int order = 1;
    while (true)
    {
        int tmp = order;
        // �ӵ�һ�����̿�ʼ���ҿ��Է�����Դ�ҿ���ִ�еĽ���
        for (int i = 0; i < process_num; i++)
        {
            // ����iû��ִ��
            if (Finish[i] == 0)
            {
                // ������Դ����С�ڻ���ڿ�������Դ����
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

/** ��ӡ��ȫ���� */
void printSafeList(int *Finish, int process_num)
{
    cout << "\nThe order of the process executing" << endl;
    cout << "process  |  order" << endl;
    for (int i = 0; i < process_num; i++)
    {
        cout << "p" << i << "\t |\t" << Finish[i] << endl;
    }
}
