#include <iostream>
#include <exception>
using namespace std;

class Matrix{
    int num_lin;
    int num_col;
    double **M;
    
    public:

    Matrix(int lines, int collums){
        num_lin = lines;
        num_col = collums;
        M = new double* [num_lin];
        for(int l = 0; l < num_lin; ++l){
            *(M+l) = new double[num_col];
            // We can, also, use: M[l] = new double[num_col];
        }
    }

    ~Matrix(){
        //To begin, we have to delete the lines:
        for (int l = 0; l < num_lin; ++l){
            delete[] *(M+l); //Or: delete[] M[l];
        }

        //Now, we have to delete the array of pointers:
        delete[] M;

        void attribute(int l, int c, double value){
            
        }
    }
};

int main(){
    try{
        int l; cout << "#lines: "; cin >> l;
        int c; cout << "##collums"; cin >> c;

        Matrix M(l, c);

        int i=0;
        int j=0;
        double value = 3.14;

        //How to attribute the value to the position M[i][j]?



    }
    catch(const exception &e){
        cerr << "Excepion: " << e.what() << '\n';
        return 1;
    }
}