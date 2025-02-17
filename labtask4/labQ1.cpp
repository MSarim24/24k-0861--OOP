#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows;
        int cols;
        int **elements;
    public:
        Matrix(int r, int c) {
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

        void Setelements(int i, int j, int val) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                elements[i][j] = val;
            } else {
                cout << "Invalid index!" << endl;
            }
        }

        void display() {
            for (int i = 0; i < rows; i++) {
                cout << "|";
                for (int j = 0; j < cols; j++) {
                    cout << elements[i][j] << "|";
                }
                cout << endl;
            }
        }

        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] elements[i];
            }
            delete[] elements;
        }
};

void MatrixTest() {
    Matrix mat(3, 3);
    mat.Setelements(0, 0, 1);
    mat.Setelements(0, 1, 2);
    mat.Setelements(0, 2, 3);
    mat.Setelements(1, 0, 4);
    mat.Setelements(1, 1, 5);
    mat.Setelements(1, 2, 6);
    mat.Setelements(2, 0, 7);
    mat.Setelements(2, 1, 8);
    mat.Setelements(2, 2, 9);
    mat.display();
}

int main() {
    MatrixTest();
    return 0;
}
