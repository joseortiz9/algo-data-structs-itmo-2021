//
// Created by joseortiz9 on 3/08/21.
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> endPoints;
    if (n<=3){
        endPoints.push_back(make_pair(1,1));
        if (n==1)
        {
            endPoints.push_back(make_pair(1,2));
        }
        else if (n==2 || (n==3 && arr[0]==arr[1]&&arr[1]==arr[2]&&arr[0]==arr[2]))
        {
            endPoints.push_back(make_pair(2,2));
        }
    }
    if (n>2)
    {
        endPoints.push_back(make_pair(1,1));
        for (int i = 0; i < n-2; i++)
        {
            if ((arr[i]==arr[i+1])&&(arr[i+1]==arr[i+2])&&(arr[i]==arr[i+2]))
            {
                endPoints.push_back(make_pair(i+2,2));
                while(i+3<n&&arr[i+2]==arr[i+1]){
                    i++;
                    if (arr[i+2]!=arr[i+1]) endPoints.push_back(make_pair(i+1,1));
                }
            }
        }
        if (arr[n-3]!=arr[n-2]||arr[n-2]!=arr[n-1]||arr[n-3]!=arr[n-1]){
            endPoints.push_back(make_pair(n,2));
        }
    }
    int start = 1;
    int end = 1;
    for (int i = 0; i<endPoints.size()-1; i++){
        if (endPoints[i].second==1&&endPoints[i+1].second==2&&endPoints[i+1].first-endPoints[i].first>end-start){
            end = endPoints[i+1].first;
            start = endPoints[i].first;

        }
    }
    cout<< start << " "<< end << endl;
    return 0;
}