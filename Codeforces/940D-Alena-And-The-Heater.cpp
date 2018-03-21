// 940D-Alena-And-The-Heater.cpp : Defines the entry point for the console application.
//
// Reference: 1. Problem Link: http://codeforces.com/problemset/problem/940/D
//            2. Contest Problem Set Link: http://codeforces.com/contest/940
//            3. Contest Solution Link: http://codeforces.com/contest/940/submission/35622633
//            4. One solution Link: http://codeforces.com/contest/940/submission/35623181

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[100100];

int findMin(int idx)
{
   int min = a[idx - 4];
   for (int i = idx - 3; i <= idx; ++i)
   {
      if (a[i] < min)
         min = a[i];
   }
   return min;
}

int findMax(int idx)
{
   int max = a[idx - 4];
   for (int i = idx - 3; i <= idx; ++i)
   {
      if (a[i] > max)
         max = a[i];
   }
   return max;
}


int main()
{
   int n;
   cin >> n;

   //std::memset(a, 0, 100100);

   for (int i = 0; i < n; ++i)
   {
      cin >> a[i];
   }

   string str;
   cin >> str;

   int b0Counter = 4, b1Counter = 0, l = -1e9, r = 1e9;

   for (int i = 4; i < n; ++i)
   {
      if (str[i] == '0')
      {
         if (i == 4)
         {
            b0Counter = 5;
            b1Counter = 0;
         }
         else
         {
            if (b1Counter >= 4)
            {
               r = min(r,findMin(i) - 1);
               b0Counter++;
               b1Counter = 0;
            }
            else
            {
               b0Counter++;
               b1Counter = 0;
            }
         }
      }
      else
      {
         if (b0Counter >= 4)
         {
            l = max(l, findMax(i) + 1);
            b1Counter++;
            b0Counter = 0;
         }
         else
         {
            b1Counter++;
            b0Counter = 0;
         }
      }
   }
   if(l <= r) cout << l << " " << r;
   else
   {
      r = l + 1;
      cout << l << " " << r;
   }
   return 0;
}

