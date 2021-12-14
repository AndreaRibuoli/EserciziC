#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i1 { -3};
    int i2 { 22};
    int i3 { -9};
    int i4 { 12};
    vector<int> v {i1, i2, i3, i4};
    cout << v[0] << " , " << v[1] << " , " << v[2] << " , " << v[3];
}
