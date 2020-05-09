//
//  CommonFunctions.cpp
//  Exercise_2
//
//  Created by Yaozeng Wang on 2/28/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int n) {
//    int f = 1;
//
//    for (int i = 1; i <= n; i ++ ){
//        f = f * i;
//    }
//
//    return f;
    if (n <= 1){
        return 1;
    }
    cout << "hello" << endl;
    int ret = n * factorial(n - 1);
    cout << "world" << endl;
    return ret;
}

vector<int> mergeSortedVectors(vector<int> &a, vector<int> &b) {
    vector<int> ret;
    int i , j ;
    for ( i = 0, j = 0 ; i < a.size()&& j < b.size() ; ){
        if (a[i] < b[j]){
            ret.push_back(a[i]);
            i++;
        }
        else {
            ret.push_back(b[j]);
            j++;
        }
    }
    if (i == a.size()){
        for (; j < b.size(); j++){
            ret.push_back(b[j]);
        }
    }
    else {
        for (;i < a.size(); i++){
            ret.push_back(a[i]);
        }
    }
    return ret;
}

// number return array


