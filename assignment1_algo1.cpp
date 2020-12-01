/* Name - Amar Singh
   Roll No. - 20CS60R67 */

// c++ program to find maximal common subpath using dynamic programming.
/* program takes as input two paths in the format 
<User No. 1>: <vertex id 1>, <vertex id 2>, ... , <vertex id m>
<User No. 2>: <vertex id 1>, <vertex id 2>, ... , <vertex id n>
from an input text file */

#include <iostream>
#include <fstream> //header file for fstream classes

using namespace std;

int l[1000][1000];

int string_to_array(string u, int a[])
{
   int i = 0,j = 0;
    string s;

    while(u[i++] != ':');
    
    for( ; i< u.length() ; i++)
    {
      if(u[i] != ',')
      {
        s += u[i];
      }
      if(u[i] == ',')
      {
        int x = (s[0] - '0');
        for(int k=1 ; k < s.length() ; k++)
          x = x*10 + (s[k] -'0');
        a[j++] = x; 
        s = {};
      }
    }
    int x = (s[0] - '0');
    for(int k=1 ; k < s.length() ; k++)
    x = x*10 + (s[k] -'0');
    a[j++] = x; 

return j;
}

void longest_common_subpath(int a[], int b[], int m, int n)
{
  int l[m+1][n+1], length = 0, row = 0, column = 0 ;

    for(int i=0 ; i<=m ; i++)
    {
      for( int j=0 ; j<=n ; j++)
      {
        if(i == 0 || j == 0)
          l[i][j] = 0;
        else if(a[i-1] == b[j-1])
        {
          l[i][j] = 1 + l[i-1][j-1]; 
      
          if(length < l[i][j])
          {
            length = l[i][j];
            row = i;
            column = j;
          }
        }
        else
          l[i][j] = 0;
      }    
    }  

    if(length == 0)
    {
      cout<<"No common subpath"<<"\n";
      return;
    }
    
    cout<<"length of longest common subpath : "<<length<<"\n";
    cout<<"longest common subpath : ";
    int path[length], x = length;
    while(l[row][column] != 0)
    { 
        path[--x] = a[row - 1];
        row--;
        column--;
    }
    for(int i=0 ; i<length ; i++)
      cout<<path[i]<<",";
}

int main () 
{
    fstream input_file; // creating ifstream class object
    input_file.open("input1.txt"); 

    if(!input_file)  // checking if file input_file exists or not
    {
      cout<<"file not opened";
      return 0;
    }

    string u,v; 
    getline(input_file,u); // reading first line in file and storing it in a string variable u
    getline(input_file,v); // reading secong line in file and storing it in a string variable v
    

int a[1000], b[1000];  

int m = string_to_array(u,a); //calling function string_to_array and storing return value to m
int n = string_to_array(v,b); //calling function string_to_array and storing return value to n

longest_common_subpath(a, b, m, n); //calling function longest_common_subpath;

 return 0;
}
