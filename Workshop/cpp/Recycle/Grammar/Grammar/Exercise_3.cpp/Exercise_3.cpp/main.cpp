//
//  main.cpp
//  Exercise_3.cpp
//
//  Created by Yaozeng Wang on 2/9/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "MyStack.h"
using namespace std;

class Solution{
public:
    bool isValid(string s) {
        MyStack newstack;
        for (int i = 0; i < s.size(); i ++){
            if (s[i] == '{' || s[i] == '[' || s[i] ==  '('){
                newstack.push(s[i]);
            }
            else{
                if (s[i] == '}'){
                    if (newstack.top() != '{'){
                        return false;
                    }
                }
                if (s[i] == ']'){
                    if (newstack.top() != '['){
                        return false;
                    }
                }
                if (s[i] == ')'){
                    if (newstack.top() != '('){
                        return false;
                    }
                }
                newstack.pop();
            }
        }
        return newstack.empty();
    }
};

class RecentCounter {
    queue<int> queue_1;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        queue_1.push(t);
        while (queue_1.front() < t - 3000)
            queue_1.pop();
        return queue_1.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution a;
    cout<< a.isValid("{}(})()") << endl; // 0
    cout<< a.isValid("") << endl; // 1
    cout<< a.isValid("()[]")<< endl;
    cout<< a.isValid("({[}])")<< endl;
    cout<< a.isValid("[]{}()") << endl;
    cout<< a.isValid("[][]{}()") << endl;
    cout<< a.isValid("{}([})") << endl;
    cout<< a.isValid("{({{[]}})}") << endl;
    cout<< a.isValid("{}[]({}})") << endl;
    
//    RecentCounter a;
//    cout << a.ping(1) <<endl;
//    cout << a.ping(100) <<endl;
//    cout << a.ping(3001) <<endl;
//    cout << a.ping(3002) <<endl;
    return 0;
}
