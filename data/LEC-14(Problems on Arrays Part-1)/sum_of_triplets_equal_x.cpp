#include <iostream>
using namespace std;

int main()
{
    int array[] = {1,2,6,5,4,8,3,7,4,9};
    int x, triplets=0;
    cout<<"Enter x: ";
    cin>>x;
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            for (int k = j+1; k < 10; k++){
                if (array[i]+array[j]+array[k]==x){
                    triplets++;
                    cout<<array[i]<<" "<<array[j]<<" "<<array[k]<<endl;
                }
            }
        }
    }
    cout<<"Total No. of triplets is: "<<triplets;
    return 0;
} 