#include<iostream>
#include <fstream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file;
    float x;
    float y;
    float arr[10];
    file.open("InputFile.txt");
    if(!file)
    {
        cout<<"File could be not open";
        exit(1);
    }
     int p=0;
     
    if(file.is_open())
    {
         int i =0;
          while(!file.eof())
        {
            p++;
                file>>x;
                arr[i] = x;
                i++;
        }
        int q = p/2;
        float arr2D[q][2];
        int t = 0;
        
        for(int i = 0;i<q;i++)
        {
            for (int j = 0; j < 2; j++)
            {
                arr2D[i][j] = arr[t]; 
                t++;
            }
            
        }
        for(int i = 0;i<q;i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout<<" "<<arr2D[i][j];
            }
            cout<<endl;
        }
        float distArr[q];
        int s = 0;
        for (int i = 0; i < q; i++)
        {
                 float g = arr2D[i][0];
                 float h = arr2D[i][1];
                 distArr[s] = sqrt(((g-0)*(g-0))+((h-0)*(h-0)));
                
                 s++;
        }
     sort(distArr,distArr+q);
        float check;
        int l = 0;
        float arr2Dcopy[q][2];
        for(int i=0;i<q;i++)
        {
            for(int j = 0;j<2;j++)
            {
                arr2Dcopy[i][j] = arr2D[i][j];
            }
        }
        float sortedPoints[p];
        int m = 0;
        for (int j = 0; j < q; j++)
        {
            for (int i = 0; i < q; i++)
            {
                 float g = arr2Dcopy[i][0];
                 float h = arr2Dcopy[i][1];
                 check = sqrt(((g-0)*(g-0))+((h-0)*(h-0)));
                if(distArr[l] == check)
                {
                    sortedPoints[m] = arr2Dcopy[i][0];
                    m++;
                    sortedPoints[m] = arr2Dcopy[i][1];
                    m++;
                    l++;
                }   
            }
        }
        for (int i = 0; i < p; i+=2)
        {
            cout<< "(" <<sortedPoints[i]<<","<<sortedPoints[i+1]<<")"<<"  ";
          
        }
        ofstream outputfile;
    outputfile.open("sorted_2D_points.txt");

    for (int i = 0; i < p; i+=2)
        {
           outputfile<< "(" <<sortedPoints[i]<<","<<sortedPoints[i+1]<<")"<<"  ";
          
        }
    }
    file.close();
    

}

