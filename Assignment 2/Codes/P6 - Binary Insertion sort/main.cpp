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

int BinarySearch(int arr[], int l, int r, int x);
void BianryInsertionSort(int arr[], int n);
void InsertionSort(int arr[], int n);
int get_rand(int Max);
void writetocsv(double arrlength[10],double arrBinInsertion[10],double arrInsertion[10]);

int main()
{
double arrlength[10],arrBinInsertion[10],arrInsertion[10];
    int pos = 0;
    srand(time(0));
    for (int length=5000 ; length<=50000;length +=5000){
        arrlength[pos]=length;

        int arr[length],arr2[length];
        for (int i=0; i<length ;++i)  arr[i]=arr2[i]=get_rand(10210);

        double start = clock();
        BianryInsertionSort(arr, length);
        double finish = clock();
        double elapsed = (double)(finish - start)/CLOCKS_PER_SEC;
        arrBinInsertion[pos]=elapsed;

        for (int i=0; i<length ;++i)  arr[i]=get_rand(10210);
        start =clock();
        InsertionSort(arr2, length);
        finish = clock();
        elapsed = (double)(finish - start)/CLOCKS_PER_SEC;
        arrInsertion[pos]=elapsed;
        ++pos;
    }

    writetocsv( arrlength,arrBinInsertion,arrInsertion);
    return 0;
}

void writetocsv(double arrlength[10],double arrBinInsertion[10],double arrInsertion[10]){
    ofstream file;
    file.open("P6 Data.csv",ios::binary);

    file<<"Size"<<","<<"BinaryInsertion"<<","<<"Insertion"<<"\n";
    for(int i =0;i<10;++i){
        file<<arrlength[i]<<","<<arrBinInsertion[i]<<","<<arrInsertion[i]<<"\n";
    }

}

int BinarySearch(int arr[], int l, int r, int x)
{
    if (r <= l)
        return (x> arr[l])?  (l + 1): l ;

    int mid = (l + r)/2;

    if(x == arr[mid])
        return mid+1;

    if(x > arr[mid])
        return BinarySearch(arr,  mid+1, r , x);

    return BinarySearch(arr, l, mid-1 , x);
}

void BianryInsertionSort(int arr[], int n)
{
    int i, key, j,place;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        place = BinarySearch(arr, 0, j, key);

        while (j >= place) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int get_rand(int Max){
    int random=0;
    random = (rand() % Max )+1;
    return random;
}
