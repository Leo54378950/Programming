//
//  main.cpp
//  Exercise_2
//
//  Created by Yaozeng Wang on 2/2/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Myvector.h"
#include <random>
#include <cmath>
#include "CommonFunctions.h"

using namespace std;

int MyMax(int *pa, int *pb){
    if (*pa > *pb){
        return *pa;
    }
    return *pb;
}

int MyMin(int *pa, int *pb){
    if (*pa < *pb){
        return *pa;
    }
    return *pb;
}

void MySwap(int *pa, int *pb){
    int a = *pa;
    *pa = *pb;
    *pb = a;
}

int MyMax(int &a, int &b){
    if (a > b){
        return a;
    }
    return b;
}

int MyMin(int &a, int &b){
    if  (a < b){
        return a;
    }
    return b;
}

void MySwap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}


int *MySum(int *arr1, int *arr2, int n){
    int *a = new int[n];
    for (int i = 0; i < n; i ++){
         a[i] = arr1[i] + arr2[i];
    }
    return a;
}
int *MyMultiply(int *arr1, int *arr2, int n){
    int *a = new int[n];
    for (int i = 0; i < n; i ++){
         a[i] = arr1[i] * arr2[i];
    }
    return a;
}
int *MyMax(int *arr1, int *arr2, int n){
    int *a = new int[n];
    for (int i =0; i < n; i ++){
        a[i] = MyMax(arr1[i], arr2[i]);
    }
    return a;
}
int *MyMin(int *arr1, int *arr2, int n){
    int *a = new int[n];
    for (int i =0; i < n; i ++){
        a[i] = MyMin(arr1[i], arr2[i]);
    }
    return a;
}

void display(vector<int> a){
    for (int i = 0; i <a.size(); i ++){
        cout << a[i]<< " ";
    }
    cout << endl;
}

void test1(){
    MyVector b;
    for (int i = 0; i < 10; i ++){
        int a = rand()%100;
        b.push_back(a);
    }
    b.display();
    b.quickSort();
    b.display();
}

double funct(double a){
    double ans = -a * a + 0.7 * a;
    return ans;
}
int bisection(double begin, double end, double &x){
    if (funct(begin) * funct(end) > 0) {
        return 0;
    }
    double target = 0.00001;
    int i = 0;
    if (funct(begin) < funct(end)){
        while (true) {
            x = begin/2 + end/2;
            if (funct(x) > target){
                end = x;
                i++;
            }
            else if (funct(x) < -target){
                begin = x;
                i++;
            }
            else{
                return i;
            }
        }
    }
    else{
        while (true) {
            x = begin/2 + end/2;
            if (funct(x) < -target){
                end = x;
                i++;
            }
            else if (funct(x) > target){
                begin = x;
                i++;
            }
            else{
                return i;
            }
        }
    }
}


int main(){
    double x;
    int a = bisection(0.5,1,x);
    cout << a << endl;
    cout << x << endl;
}
