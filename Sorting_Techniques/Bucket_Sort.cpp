#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucket_sort(float array[], int size)
{
    vector<float> bucket[size];
    int bucket_index;

    //Insert elements at proper bucket
    for(int i=0; i<size; i++)
    {
        bucket_index = size*array[i];
        bucket[bucket_index].push_back(array[i]);
    }

    //Sort individual buckets
    for(int j=0; j<size; j++)
    {
        sort(bucket[j].begin(), bucket[j].end());
    }

    //Merge all buckets into the output array
    int index=0;
    for(bucket_index = 0; bucket_index<size; bucket_index++)
    {
        for(int i = 0; i < bucket[bucket_index].size(); i++)
        {
            array[index] = bucket[bucket_index][i];
            index++;
        }
    }
}

int main()
{
    float array[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(array)/sizeof(array[0]);

    bucket_sort(array,n);

    cout<<"Sorted array is:"<<endl;
    for(int i=0; i<n; i++)
        cout<<array[i]<<endl;
}
