// Football-43A.cpp : Defines the entry point for the console application.
//
// Reference: 1. http://codeforces.com/problemset/problem/43/A
//            2. https://github.com/jackiehluo/practice/blob/master/codeforces/000s/43a-football.cpp

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int MAX = 1e5 + 1;
typedef vector<int> vi;
typedef pair<int, int> pii;

pii p[200050];
vi v;

int main()
{
   int n;
   cin >> n;
   map<string, int> g;
   string t, a, b;

   for (int i = 0; i < n; i++)
   {
      cin >> t;
      g[t]++;
      if (a.empty()) a = t;
      else if (b.empty() && t != a) b = t;
   }

   if (g[a] > g[b]) cout << a << endl;
   else cout << b << endl;
   return 0;
}


