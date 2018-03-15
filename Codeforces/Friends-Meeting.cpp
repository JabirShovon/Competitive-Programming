// Friends-Meeting.cpp : Defines the entry point for the console application.
//
// Reference: 1. http://codeforces.com/problemset/problem/931/A

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int main()
{
   int a, b;
   string str;
   //int num[MAX] = {0};
   vector<int> vi;
   int in = 0, tired = 0;
   bool even = false;

   cin >> a >> b;
   //cin >> str;
   if (abs(a - b) > 1)
   {
      if (abs(a - b) % 2 == 0)
      {
         in = abs(a - b) / 2;
         even = true;
      }
      else
      {
         in = (abs(a - b) - 1) / 2;
         even = false;
      }
   }
   else tired = 1;


   if (in >= 1)
   {

      for (int i = 1; i <= in; ++i)
      {
         tired += i;
      }
      tired = tired * 2;
      if (even == false) tired = tired + (in + 1);
   }

   cout << tired;
   return 0;
}

