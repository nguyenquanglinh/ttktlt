// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void  bubbleSort(int* array,int n) {
    int  temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << array[i] << "\n";
    }
}
int main()
{
    int * NUMBERS =new int[27]
    { 49 ,  38 ,  65 ,  97 ,  76 ,  13 ,  27 ,  78 ,  34 , 
        12 ,  64 ,  5 ,  4 ,  62 ,  99 ,  98 ,  54 ,  56 , 
        17 ,  18 ,  23 ,  34 ,  15 ,  35 ,  25 ,  53 ,  51 };
    bubbleSort(NUMBERS, 27);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
