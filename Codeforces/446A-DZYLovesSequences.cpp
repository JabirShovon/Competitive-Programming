// 446A-DZYLovesSequences.cpp : Defines the entry point for the console application.
//
// Reference: 1. http://codeforces.com/problemset/problem/446/A
//            2. http://codeforces.com/contest/447/submission/7149106

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cstring>
#include<algorithm>
using namespace std;

#define REP(a,n) for((a) = 0; (a) < n; a++)
#define pb push_back
#define RESET(c,v) memset(c, v, sizeof(c))

int n, a;
vector<int> Data;
int forward1[100005], backward[100005];

//#-----Method1-----------
// Method 1: create index pairs of separate individual sequences.

//while (start < n)
//{
//   int i = end;
//   while (i + 1 < n && v[i + 1] > v[i])
//      i++;
//   end = i;
//   
//   //m.insert(make_pair(start, end));
//   p[j] = make_pair(start, end);
//   j++;
//   start = i + 1;
//   end = start;

//}

//int count = 1;
//while (count <= j)
//{
//   if (v[p[count].first] < v[p[count - 1].second] && (v[p[count - 1].second] - v[p[count].first] > 1))
//   {
//      if (res < p[count].second - p[count - 1].first)
//      {
//         res = p[count].second - p[count - 1].first + 1;
//         count += 1;
//      }
//      
//   }
//   else count++;
//}

// #----Method 2----------

//forward1 will keep track of indeces upto which subsequences are ended. e.g. forward1[2] = 3 means, at position 2, the length of the 
// sequence ended in position 2 is 3. so the sequence is in postion 0,1,2.

//backward will keep track of indeces starting from which subsequences have started. e.g. forward1[2] = 3 means, at position 2, the length of the 
// sequence started is 3. so the sequence is in position 2,3,4.

int backwardCheck(int a)
{
   int ret;
   if (Data[a] < Data[a + 1])
   {
      ret = backward[a + 1] + 1;
   }

   else
   {
      ret = 1;
   }

   return ret;
}

int forwardCheck(int a)
{
   int ret;
   if (Data[a] > Data[a - 1])
   {
      ret = forward1[a - 1] + 1;
   }

   else
   {
      ret = 1;
   }

   return ret;
}

int main()
{
   int temp;
   scanf("%d", &n);

   RESET(forward1, 0);
   RESET(backward, 0);

   REP(a, n)
   {
      scanf("%d", &temp);
      Data.pb(temp);
   }

   // Cari yang kiri[0] - kiri[n-1]
   REP(a, n)
   {
      if (!a)	forward1[a] = 1;
      else	forward1[a] = forwardCheck(a);
   }

   // Cari yang kanan[0] - kanan[n-1]
   for (a = n - 1; a >= 0; a--)
   {
      if (a == n - 1)	backward[a] = 1;
      else  	backward[a] = backwardCheck(a);
   }

   // Debugging
   int maks = 0;
   REP(a, n)
   {
      //printf("Kiri[%d] : %d\n",a,kiri[a]);
      //printf("Kanan[%d] : %d\n",a,kanan[a]);

      // ---- Corner Case Kiri ----
      if (!a)
      {
         if (Data[a] < Data[a + 1]) maks = max(maks, backward[a]);
         else maks = max(maks, (backward[a + 1] + 1));
      }

      // ---- Corner Case Kanan ----
      else if (a == n - 1)
      {
         if (Data[a] > Data[a - 1]) maks = max(maks, forward1[a]);
         else maks = max(maks, (forward1[a - 1] + 1));
      }

      else
      {
         int changeVar = 0;
         if (Data[a + 1] - Data[a - 1] > 1) changeVar = 1, maks = max(maks, forward1[a - 1] + backward[a + 1] + 1);

         maks = max(max(maks, forward1[a - 1] + 1), backward[a + 1] + 1);
      }

      //printf("Maks[%d] : %d\n",a,maks);
   }

   printf("%d\n", maks);
   return 0;
}
