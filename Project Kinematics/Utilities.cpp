#include "Utilities.h"

bool Utilities::IsInteger(float num)
{
    return std::floor(num) == num;
}

void Utilities::VectorKSimulationUserChangedBoolSort(std::vector<KSimulationUserChangedBool>& arr)
{
    int i, j;
    int n = arr.size();

    KSimulationUserChangedBool temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].tick == arr[j + 1].tick && (arr[j+1].del==0 || arr[j].del == 0))
            {
                arr[j + 1].del = 1;
                arr[j].acc = 1;
                arr[j].vel = 1;

            }
            else if (arr[j].tick > arr[j + 1].tick)
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                //swap(arr[j], arr[j + 1]);
            }
                
}

void Utilities::VectorKSimulationUserChangedBoolSort(std::deque<KSimulationUserChangedBool>& arr)
{
    int i, j;
    int n = arr.size();

    KSimulationUserChangedBool temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].tick == arr[j + 1].tick && (arr[j + 1].del == 0 || arr[j].del == 0))
            {
                arr[j + 1].del = 1;
                arr[j].acc = 1;
                arr[j].vel = 1;

            }
            else if (arr[j].tick > arr[j + 1].tick)
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                //swap(arr[j], arr[j + 1]);
            }

}
