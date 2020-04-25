//
//  main.cpp
//  Exercise_1.cpp
//
//  Created by Yaozeng Wang on 1/31/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//
// Recording of a Class Student
// Copy variables:
// Chinese/Math/English/PE Scores
// Height and Weight

// Functions To realize:
// Score Maxima/ Minima
// Average of academic scores
// Height to weight ratio
// Ratio of PE score and H/W

#include <iostream>
#include <string>
using namespace std;

 

class Student {

public :
    Student(void);
    Student(int Chinese, int Math, int English, int Pe, float Height, float Weight);
    Student(int Chinese, int Math, int English, int Pe, int Height, int Weight);

    virtual ~Student(void);
    
public:
    int Maxima(void);
    int Minima(void);
    float HWR(void);
    float PER(void);
    
public:
    int mChinese;
    int mMath;
    int mEnglish;
    int mPe;
    float mHeight;
    float mWeight;
};

Student::Student(void){
    mChinese = 0;
    mMath = 0;
    mEnglish = 0;
    mPe = 0;
    mHeight = 0;
    mWeight = 0;
}

Student::Student(int Chinese, int Math, int English, int Pe, float Height, float Weight){
    mChinese = Chinese;
    mMath = Math;
    mEnglish = English;
    mHeight = Height;
    mWeight = Weight;
    mPe = Pe;
    cout << "flag" << endl;
}

Student::Student(int Chinese, int Math, int English, int Pe, int Height, int Weight){
    mChinese = Chinese;
    mMath = Math;
    mEnglish = English;
    mHeight = Height;
    mWeight = Weight;
    mPe = Pe;
    cout << "function int" << endl;
}

Student::~Student(void){
    
}

int Student::Maxima(void){
    int a = mChinese;
    int Scores [] = {mChinese, mMath, mEnglish, mPe};
    for (int i = 1; i < 4; i++){
        if (Scores[i] > a){
            a = Scores[i];
        }
    }
    return a;
}

int Student::Minima(void){
    int a = mChinese;
    int Scores [] = {mChinese, mMath, mEnglish, mPe};
    for (int i=0; i <= 3; i++){
        if (Scores[i] <= a){
            a = Scores[i];
        }
    }
    return a;
}

float Student::HWR(void){
    return mHeight / mWeight;
}

float Student::PER(){
//    float a = mPe * mWeight / mHeight;
   float a = mPe / HWR();
   return a;
}


int main() {
    Student Student(76, 77, 78, 79, 1.80, 1.80);
    cout << "The highest score of the student is " << Student.Maxima() << endl;
    cout << "The lowest score of the student is " << Student.Minima() << endl;
    cout << "The student's Height to weight ratio is " << Student.HWR() << endl;
    cout << "The student's PE score to Height to weight ratio is " << Student.PER() << endl;
    return 0;
}
