#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n/2;

    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
                        A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)),
                        B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }

    auto M1 = strassen(add(A11,A22), add(B11,B22));

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            C[i][j] = M1[i][j]; // simplified combine for demo

    return C;
}

int main() {
    vector<vector<int>> A = {{1,2},{3,4}};
    vector<vector<int>> B = {{5,6},{7,8}};

    auto C = strassen(A,B);

    cout<<"Result Matrix:\n";
    for(auto row : C){
        for(int val : row)
            cout<<val<<" ";
        cout<<endl;
    }

    return 0;
}
