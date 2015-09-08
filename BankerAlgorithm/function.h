#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 10;

void inputData(ifstream &in, int *array, int size);
void inputData(ifstream &in, int array[][MAX_SIZE], int row, int column);
void setZero(int *array, int size);
void computeArray(int *first, int *second, int size, char oper);
void computeArray(int result[][MAX_SIZE], int first[][MAX_SIZE], int second[][MAX_SIZE],
                  int row, int column, char oper);
bool isNotGreater(int *first, int *second, int size);
int inputRequest(int Request[][MAX_SIZE], int row, int column);
bool isSafe(int *Available, int Need[][MAX_SIZE], int *Finish, int Allocation[][MAX_SIZE],
            int process_num, int resources_num);
void printSafeList(int *Finish, int process_num);

#endif // FUNCTION_H_INCLUDED
