/*
Problem 5

Programmers:
        Ahmed Sayed Mansour   20170022
        Fatma Ashraf Ramadan  20170192
        Ibrahim Ramadan Abdou 20170002

*/
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

void writetocsv(double arrlength[20],double arrmerge[20],double arrquick[20]);
int get_rand(int Max);
void printArray(int arr[], int size);

///MergeSort
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

///QuickSort
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    double arrlength[20],arrmerge[20],arrquick[20];
    int pos = 0;
    srand(time(0));
    for (int length=5000 ; length<=100000;length +=5000){
        arrlength[pos]=length;

        int arr[length];
        for (int i=0; i<length ;++i)  arr[i]=get_rand(10210);

        double start = clock();
        mergeSort(arr, 0, length-1);
        double finish = clock();
        double elapsed = (double)(finish - start)/CLOCKS_PER_SEC;
        arrmerge[pos]=elapsed;

        start =clock();
        quickSort(arr, 0, length-1);
        finish = clock();
        elapsed = (double)(finish - start)/CLOCKS_PER_SEC;
        arrquick[pos]=elapsed;
        ++pos;
    }

    writetocsv( arrlength,arrmerge,arrquick);
    return 0;

}

void writetocsv(double arrlength[20],double arrmerge[20],double arrquick[20]){
    ofstream file;
    file.open("P5 Data.csv",ios::binary);

    file<<"Size"<<","<<"Merge"<<","<<"Quick"<<"\n";
    for(int i =0;i<20;++i){
        file<<arrlength[i]<<","<<arrmerge[i]<<","<<arrquick[i]<<"\n";
    }

}

///mergeSort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)    L[i] = arr[l + i];
    for (j = 0; j < n2; j++)    R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

///QuickSort
int partition (int arr[], int low, int high)
{
    int pivot = arr[(low+high)/2];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int get_rand(int Max){
    int random=0;
    random = (rand() % Max )+1;
    return random;
}
