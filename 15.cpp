#include <iostream>
#include <vector>

using namespace std;

// Sparse Matrix Element structure
struct Element {
    int row;
    int col;
    int val;
};

// Sparse Matrix structure
struct SparseMatrix {
    int rows;
    int cols;
    int numTerms;
    vector<Element> elements;
};

// Function to create a sparse matrix
SparseMatrix createSparseMatrix(int rows, int cols, vector<vector<int>>& matrix) {
    SparseMatrix sparseMat;
    sparseMat.rows = rows;
    sparseMat.cols = cols;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                Element element;
                element.row = i;
                element.col = j;
                element.val = matrix[i][j];
                sparseMat.elements.push_back(element);
            }
        }
    }

    sparseMat.numTerms = sparseMat.elements.size();
    return sparseMat;
}

// Function to display a sparse matrix
void displaySparseMatrix(SparseMatrix& sparseMat) {
    for (int i = 0; i < sparseMat.numTerms; ++i) {
        cout << sparseMat.elements[i].row << " "
             << sparseMat.elements[i].col << " "
             << sparseMat.elements[i].val << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    SparseMatrix sparseMat = createSparseMatrix(rows, cols, matrix);

    cout << "Sparse Matrix Representation:" << endl;
    displaySparseMatrix(sparseMat);

    return 0;
}
