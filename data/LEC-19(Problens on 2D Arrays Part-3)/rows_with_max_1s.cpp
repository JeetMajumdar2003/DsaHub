#include <bits/stdc++.h>
using namespace std;

// maximum One's row function:
int maxOnesRow(vector<vector<int>>& v)  // used refference for not creating extra vector
{
    int maxidx = -1;
    int maxOnes = INT_MIN;
    int columns = v[0].size();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == 1)
            {
                int numberOfOnes = columns - j;
                if (maxOnes<numberOfOnes)
                {
                    maxOnes = numberOfOnes;
                    maxidx = i;
                }
                break;
            }
        }
    }
    return maxidx;
}

// By finding left most one:
int leftMostOneRow(vector<vector<int>> &v){
    int leftMostOne = -1;
    int maxOnesRow = -1;
    int j = v[0].size()-1;
    // find left most one in 0th row:
    while (j>=0 && v[0][j] == 1)
    {
        leftMostOne = j;
        maxOnesRow=0;
        j--;
    }
    
    // now check in the rest of the rows if we can find a one left to the leftMostOne:
    for (int i = 1; i < v.size(); i++)
    {
        while (j>=0 && v[i][j] == 1)
        {
            leftMostOne = j;
            maxOnesRow=i;
            j--;
        }
        
    }
    
    return maxOnesRow;
}


int main()
{
    int n, m;
    cin >> n >> m;
    // Using First Occurrance of 1's:
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    // finding maximum one's in a row:
    int ansIndex = maxOnesRow(v);
    cout << ansIndex << endl;

    // finding left most one:
    int ans = leftMostOneRow(v);
    cout<<ans<<endl;

    // int array[3][4] = {{0,1,1,1},{0,0,0,1},{0,0,0,1}};
    // int noOf1s[3] = {0};
    // int max = 0;
    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 4; j++){
    //         if (array[i][j]==1){
    //             noOf1s[i]++;
    //         }
    //     }
    //     cout<<noOf1s[i]<<" ";
    //     if (max<noOf1s[i])
    //     {
    //         max=noOf1s[i];
    //     }
    // }cout<<endl;
    // for (int i = 0; i < 3; i++){
    //     if (max==noOf1s[i]){
    //         cout<<i<<endl;
    //     }
    // }

    return 0;
}