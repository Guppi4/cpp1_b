#include <iostream>

#include "string.h"
#include "mat.hpp"
#include <iostream>
#include <vector>
using namespace std;
namespace ariel
{
  void paint1(vector<vector<char>> &arr, int col, int row, char s1, char s2, int median)
  {
   for(int j=0;j<row;j++){
          for(int j1=0;j1<col;j1++){
                if(j<=median &&  j%2==0 && j1<(col-j) && j1>=j ){
                    if(arr[j][j1]!=s1){
                    arr[j][j1]=s1;
                   
                   continue;
                    }
                        
                }  
     if(j>median &&  j%2==0 && j1<(col-(row-j-1)) && j1>=(row-j-1) ){
                   if(arr[j][j1]!=s1){
                    arr[j][j1]=s1;
                   
                   continue;
                    }
                 }
                 
                 
                
                  arr[j][j1]=s2;
            }
          // cout<<j/2 <<endl;
          //cout << endl;
           
       }
  }
  void paint2(vector<vector<char>> &arr1, int col, int row, char s1, char s2, int median)
  {

    for (int j = 0; j < col; j++)
    {
      for (int j1 = 0; j1 < row; j1++)
      {
        if (j <= median && j % 2 == 0 && j1 < (row - j) && j1 >= j)
        { // paint reverse carpet
          arr1[j][j1] = s1;
          continue;
        }

        if (j >= median && j % 2 == 0 && j1 < (row - (col - j - 1)) && j1 >= (col - j - 1))
        {
          arr1[j][j1] = s1;
          continue;
        }
        if (arr1[j][j1] != s1)
        {
          arr1[j][j1] = s2;
          continue;
        }
      }   
    }
  }
  string mat(int a, int b, char c, char d)
  {
    int row = b;
    int median = row / 2;
    int col = a;
    char s1 = c;
    char s2 = d;
    string s;
    vector<vector<char>> arr(row, vector<char>(col)); // srtuct 1 for reverse carpet

    if (b % 2 == 0 || a % 2 == 0)
    {
      throw runtime_error("odd");
    }
    if (b < 0 || a < 0)
    {
      throw runtime_error("negative");
    }
    paint1(arr,a,b,c,d,median);
    vector<vector<char>> arr1(col, vector<char>(row)); // vector for reverse 2
    for (int i = 0; i < col; ++i)
    {
      for (int j = 0; j < row; ++j)
      { // loop for reverse carpet
        arr1[i][j] = arr[j][i];
      } //
    }
    paint2(arr1,a,b,c,d,median);
     for (int i = 0; i < row; ++i)// reverse
    { 
      for (int j = 0; j < col; ++j)
      {
        arr[i][j] = arr1[j][i];
      }
    }
    for (int i = 0; i < row; i++)//add to string
    {
      for (int j = 0; j < col; j++)
      {
        s += arr[i][j];
      }
    }
    s += "\n";
    return s;
  }
}
  
