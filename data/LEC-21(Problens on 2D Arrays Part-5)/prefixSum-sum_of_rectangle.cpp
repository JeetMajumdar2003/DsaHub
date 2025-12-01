 #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter Row: ";
    cin>>n;
    cout<<"Enter Column: ";
    cin>>m;
    // int array[n][m];
    // input array elelemt
    // for (int  i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cin>>array[i][j];
    //     }
    // }
    // Print array
    // for (int  i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // take input coordinates: (l1, r1), (l2, r2)
    int l1, r1, l2, r2, sum = 0;
    cout<<"Enter l1: ";
    cin>>l1;
    cout<<"Enter r1: ";
    cin>>r1;
    cout<<"Enter l2: ";
    cin>>l2;
    cout<<"Enter r2: ";
    cin>>r2;
    // Calculate the sum of elements inside the rectangle: formed by (l1, r1) to (l2, r2)
    // cout<<"Calculating Sum using  Brute Force: "<<endl;
    // for (int  i = l1; i <= l2; i++){
    //     for (int j = r1; j <= r2; j++){
    //         sum += array[i][j];
    //     }
    // }
    // cout<<sum<<endl;


    // Methode-2->Using Prefix Sum:
    // cout<<"Calculating Sum using prefix sum:"<<endl;
    // vector<vector<int>> v(n, vector<int>(m));
    // cout<<"Printing vector:"<<endl;
    // for (int  i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         v[i][j] = array[i][j];
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // Calculating Prefix sum of v[i]:(Row wise)
    // for (int  i = 0; i < n; i++){
    //     for (int j = 1; j < m; j++){
    //         v[i][j] += v[i][j-1];
    //     }
    // }
    // Printing prefix sum vector:(Row wise)
    // cout<<"Printing prefix sum of Row, matrix:"<<endl;
    // for (int  i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int ans = 0;
    // for (int  i = l1; i <= l2; i++){
    //     if (r1==0)
    //         ans += v[i][r2];
    //     else
    //         ans += v[i][r2] - v[i][r1-1];
    // }
    // cout<<ans;

    // Method-3-> Prefix sum over columns of prefixSum Row matrix
    vector<vector<int>> vec(n, vector<int>(m));
    cout<<"Taking Input vector elements:"<<endl;
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>vec[i][j];
        }
    }
    // calculating prefix sum along row wise of vec matrix
    for (int  i = 0; i < n; i++){
        for (int j = 1; j < m; j++){
            vec[i][j] += vec[i][j-1];
        }
    }
    cout<<"Printing prefix sum of Row, matrix:"<<endl;
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    // calculating prefix sum along column wise of prefix sum row, vec matrix
    for (int  i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            vec[i][j] += vec[i-1][j];
        }
    }
    cout<<"Printing prefix sum of columns, of prefix sum row matrix:"<<endl;
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    // Rectangular sum:
    int top_right=0, bottom_left=0, top_left=0;
    if(l1!=0) top_right = vec[l1-1][r2];
    if(r1!=0) bottom_left = vec[l2][r1-1];
    if(l1!=0 && r1!=0) top_left = vec[l1-1][r1-1];

    int recSum = vec[l2][r2] - top_right- bottom_left + top_left;
    cout<<recSum<<endl;
    return 0;
}