#include <iostream>
using namespace std;

class Matrix{
public:
    int rows,cols;
    int** matrix;
public:
    void setMatrix(){
        int r,c;
        cout<<"Enter number of rows:"<<endl;
        cin>>r;
        cout<<"Enter number of columns:"<<endl;
        cin>>c;
        this->rows=r;
        this->cols=c;
        matrix=new int*[rows];
    }
    void allocateColMatrix(){
        for(int row=0;row<rows;row++){
            matrix[row]=new int[cols];
        }
    }

    void createMatrix(){
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                cin>>matrix[row][col];
            }
        }
    }

    void printMatrix(){
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                cout<<matrix[row][col]<<" ";
            }
            cout<<endl;
        }
    }

    ~Matrix(){
        delete[] matrix;
    }

};

class AdditionOfMatrix:public Matrix{
public:
    int** result;
public:
    AdditionOfMatrix(){
        result=new int*[rows];
    }

    void addition(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                AdditionOfMatrix operator+(const AdditionOfMatrix& matrix2){
                    result=new int* [rows];
                    for(int i=0;i<rows;i++){
                        result[i]=new int[cols];
                    }
                    result[i][j]=
                }
            }
        }
    }

    void printAdditionMatrix(){

    }
};

class Substraction:public Matrix{

};

class Multiplication:public Matrix{

};

int main(){
    int NumberOfMatrix;
    cout<<"Enter number of Matrix:";
    cin>>NumberOfMatrix;
    Matrix* matrix=new Matrix[NumberOfMatrix];
    for(int i=0;i<NumberOfMatrix;i++){
        matrix[i].setMatrix(); 
        matrix[i].allocateColMatrix();
        matrix[i].createMatrix();
        matrix[i].printMatrix();
    }

    delete[] matrix;
}