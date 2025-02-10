#include <iostream>
using namespace std;
class Matrix{
    private:
        int rows;
        int cols;
        int **elements;
    public:
        Matrix(int r,int c){
            rows = r;
            cols = c;
            elements = new int*[rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new int[cols]();
        }
        }
        int getrows() { 
            return rows; 
        }
        int getcols() { 
            return cols; 
        }
        void Setelements(int i, int j, int val){
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                elements[i][j] = val;
            } 
            else {
                cout<<"Invalid index!"<<endl;
            }
        }
        Matrix Addmatrix(Matrix m){
            if (rows != m.getrows() || cols != m.getcols()){
                cout<<"Matrices can not be added!"<<endl;
                return Matrix(0,0);
            }
            Matrix add(rows,cols);
            for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                    add.Setelements(i,j,elements[i][j]+m.elements[i][j]);
                }
            }
            return add;
        }
        Matrix multiply(Matrix m){
            if(cols != m.getrows()){
                cout << "Matrices cannot be multiplied" << endl;
                return Matrix(0,0);
            }
            Matrix mul(rows,m.getcols());
            int val = 0;
            for(int i = 0; i<rows; i++){
                for(int j = 0; j<m.getcols(); j++){
                    val = 0;
                    for(int k = 0;k<cols; k++){
                        val += elements[i][k]*m.elements[k][j];
                    }
                    mul.Setelements(i,j,val);
                }
            }
            return mul;
        }
        void display(){
            for(int i = 0; i<rows; i++){
                cout<<"|";
                for(int j = 0; j<cols; j++){
                    cout<<elements[i][j]<<"|";
                }
                cout<<endl;
            }
        }

};
void MatrixTest(){
    int choice = 0;
        int r,c;
        cout<<"Matrix 1: \n\tEnter Rows: ";
        cin>>r;
        cout<<"\tEnter Coloumns: ";
        cin>>c;
        Matrix m1(r,c);
        cout << "Enter elements for first matrix:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val;
                cout<<"Value: ";
                cin >> val;
                m1.Setelements(i, j, val);
                m1.display();
            }
        }
        cout<<"\nMatrix 2: \n\tEnter Rows: ";
        cin>>r;
        cout<<"\tEnter Coloumns: ";
        cin>>c;
        Matrix m2(r,c);
        cout << "Enter elements for second matrix:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val;
                cout<<"Value: ";
                cin >> val;
                m2.Setelements(i, j, val);
                m2.display();
            }
        }
    while(choice != 3){
        cout<<"1----Add Matrix\n2----multiply Matrix\n3----Exit"<<endl;
        cout<<"choice:"; 
        cin>>choice;
        switch (choice)
        {
        case 1:
            
            cout<<"\nResult: \n";
            m1.Addmatrix(m2).display();
            break;
        
        case 2:
            cout<<"\nResult: \n";
            m1.multiply(m2).display();
            break;
        default:
            break;
        }
    }
}
int main()
{
    MatrixTest();
    return 0;
}