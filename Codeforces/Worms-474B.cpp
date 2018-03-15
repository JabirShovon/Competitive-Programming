// Worms-474B.cpp : Defines the entry point for the console application.
//
//Reference: 1. http://codeforces.com/problemset/problem/474/B
//           2. https://github.com/SH-anonta/Competitive-Programming-Solutions/blob/master/Code%20Forces/Code%20forces%20Div%202/Code%20forces%20474B%20-%20Worms.cpp

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1e5 + 1;
typedef vector<int> vi;
typedef pair<int, int> pii;

pii p[200050];

int find(int val, int n)
{
   int l, r, m;
   l = 0;
   r = n;

   while (1)
   {
      m = (l + r) / 2;
      if (p[m].first <= val && p[m].second >= val)
      {
         return m + 1;
      }

      if (p[m].first > val) r = m;
      else l = m;
   }
}

int main()
{
   int n, m, res;
   string str;
   //int num[MAX] = {0};

   int in = 0;

   cin >> n;
   int l = 1;
   for (int i = 0; i < n; i++)
   {
      cin >> in;
      p[i].first = l;
      p[i].second = l + in - 1;

      l = l + in;
   }
   cin >> m;
   int q;
   while (m--)
   {
      cin >> q;

      cout << find(q, n) << "\n";
   }

   return 0;
}


