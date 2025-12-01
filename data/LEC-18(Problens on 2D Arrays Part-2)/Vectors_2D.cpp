#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 2D Vector
    // Declaring 2D Vector:
    vector<vector<int>> vec1;

    // Initializing 2D Vector:
    vector<vector<int>> vec2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // or
    vector<vector<int>> vec3(3, vector<int>(3, 0));

    // Accessing 2D Vector:
    cout << vec2[0][0] << endl;
    cout << vec2[1][1] << endl;
    cout << vec2[2][2] << endl;
    cout<<"Vector 2: "<<endl;
    for (int i = 0; i < vec2.size(); i++){  // Note: use vec2.size() instead of hard-coding the row size
        for (int j = 0; j < vec2[i].size(); j++){   // Note: use vec2[i].size() instead of hard-coding the column size
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }
    

    // Inserting Elements in 2D Vector:
    vec2.push_back({10, 11, 12});
    vec2[1].push_back(13);
    cout<<"After Inserting Vector 2: "<<endl;
    for (int i = 0; i < vec2.size(); i++){
        for (int j = 0; j < vec2[i].size(); j++){
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }

    // Deleting Elements in 2D Vector:
    vec2.pop_back();    // deletes the last row
    vec2[1].erase(vec2[1].begin() + 3); // Note: use erase() instead of pop_back()
    vec2[1].pop_back(); // Note: use erase() instead of pop_back()
    cout<<"After Deleting Vector 2: "<<endl;
    for (int i = 0; i < vec2.size(); i++){
        for (int j = 0; j < vec2[i].size(); j++){
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }

    // // Size of 2D Vector:
    cout << vec2.size() << endl;
    // // size of first row
    cout << vec2[0].size() << endl;

/*
    // // Iterating 2D Vector:
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = 0; j < vec[0].size(); j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // // Using Iterator:
    // for (auto it = vec.begin(); it != vec.end(); it++)
    // {
    //     for (auto it2 = it->begin(); it2 != it->end(); it2++)
    //     {
    //         cout << *it2 << " ";
    //     }
    //     cout << endl;
    // }

    // // Using For Each Loop:
    // for (auto &row : vec)
    // {
    //     for (auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    // // Using For Each Loop with Auto Keyword:
    // for (auto row : vec)
    // {
    //     for (auto col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }
*/    
    return 0;
}