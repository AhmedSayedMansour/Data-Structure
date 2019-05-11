/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019
/// Version: 3.0


#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

template <class T>
class matrix
{
private:
	T** data;       // Pointer to 2-D array that will simulate matrix
	int row, col;
public:

	//A constructor that create a matrix non initialized.
	matrix();

	// Constructor that creates a matrix from an array
	matrix(int row, int col, T num[]);

	// Constructor that creates an empty matrix
	matrix(int row, int col);

    // a copy constructor
	matrix(const matrix<T>& old);

	//Two functions to the rows and columns of a matrix
	int getrow();
	int getcol();

	//Input Function
	template<class T2>
	friend istream& operator>> (istream& in, matrix<T2>& mat);

	//iostream for input and output
	template <class T2>
	friend ostream& operator<< (ostream& out, const matrix<T2>& mat);

	// A function to get the sum of two matrices
	matrix<T> operator+(matrix<T> & mat2);

	// A function to remove the value of another matrix from it
	matrix<T> operator-(matrix<T> &mat2);

	//  A function to produce two matrices
	matrix<T> operator*(matrix<T> &mat2);

	// A function to add a value to A matrix
	matrix<T> operator+(T scalar);

	//A matrix to remove a value from a matrix
	matrix<T> operator-(T scalar);

	// A function to produce a value in  a matrix
	matrix<T> operator*(T scalar);

	// A function to rotate a matrix;
	template <class T2>
	friend matrix<T2>& transpose(matrix<T2>& mat);

	virtual ~matrix();
};


//A constructor that creates a matrix non initialized
template <class T>
matrix<T>::matrix() {}

// Constructor that create a matrix from an array
template <class T>
matrix<T>::matrix(int row, int col, T num[])
{
    this->row = row;
    this->col = col;
    data = new T*[row];

    for (int i = 0; i < row; i++)
        data[i] = new T[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = num[i * col + j];
}

// Constructor that create an empty matrix
template <class T>
matrix<T>::matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    data = new T*[row];
    for (int i = 0; i < row; i++)
        data[i] = new T[col];
}

//Two functions to the rows and column of a matrix
template<class T>
matrix<T>::getrow()
{
    return row;
}

template<class T>
matrix<T>::getcol()
{
    return col;
}

//Input Function
template<class T2>
istream& operator>> (istream& in, matrix<T2>& mat)
{
    cin >> mat.row >> mat.col;  // Take rows and cols from the user

    mat.data = new T2*[mat.row];

    for (int i = 0; i < mat.row; i++)
        mat.data[i] = new T2[mat.col];

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            in >> mat.data[i][j]; // Enter Elements Gradually

    return in;
}

//ostream for output.
template<class T2>
ostream& operator<< (ostream& out, const matrix<T2>& mat)
{
    for (int i = 0; i < mat.row; i++)
    {
        out << endl;
        for (int j = 0; j < mat.col; j++)
            out << mat.data[i][j] << "  ";
    }
    out << endl << endl;

    return out;
}


//A copy constructor
template<class T>
matrix<T>::matrix(const matrix<T>& old)
{
    this->col = old.col;
    this->row = old.row;
    this->data = new T*[row];

    for (int i = 0; i < row; i++)
        this->data[i] = new T[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->data[i][j] = old.data[i][j];
}


// A function to get the sum of two matrices
template<class T>
matrix<T> matrix<T>::operator+( matrix<T> & mat2)
{
    matrix<T> mat(row, col);				//setting number of rows and cols in object mat
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = 0;                // initialize all values equal 0

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] = (data[i][j] + mat2.data[i][j]);    //get the sum(all values mat1+ all values in mat2) and put it in mat
        }
    }
    return mat;
}

// A function to remove the value of another matrix from it
template<class T>
matrix<T> matrix<T>::operator-(matrix<T> &mat2)
{
    matrix<T> mat(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = 0;                 //initialize all values to 0


    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] = (data[i][j] - mat2.data[i][j]);    //remove values
        }
    }
    return mat;
}

//  A function to produce two matrices
template<class T>
matrix<T> matrix<T>::operator*(matrix<T> &mat2)
{
    matrix<T> mat(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat.data[i][j] = 0;         // initialize all values to 0

    for (int i = 0; i < row; i++)
        for (int j = 0; j < mat2.col; j++)
            for (int k = 0; k <col; k++)
            {
                mat.data[i][j] += data[i][k] * mat2.data[k][j];   //get the production
            }
    return mat;
}

// A function to add a value to A
template <class T>
matrix<T> matrix<T>::operator+(T scalar)
{
    matrix<T> mat(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = 0;    //initialize all values to 0


    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] = (data[i][j] + scalar);   //get the sum
        }
    }
    return mat;
}

//A matrix to remove a value from a matrix
template <class T>
matrix<T> matrix<T>::operator-(T scalar)
{
    matrix<T> mat(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = 0;          //initialize all values to 0


    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] = (data[i][j] - scalar);  //the equation
        }
    }
    return mat;
}

// A function to produce a value in  a matrix
template <class T>
matrix<T> matrix<T>::operator*(T scalar)
{

    matrix<T> mat(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = 0;            //initialize all values to 0


    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.data[i][j] = (data[i][j] * scalar);    //The equation
        }
    }
    return mat;
}

// A function to rotate a matrix;
template<class T2>
matrix<T2>& transpose(matrix<T2>& mat)
{
    matrix<T2> mat1(mat.col, mat.row);

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat1.data[i][j] = mat.data[j][i];     //put all values in the rotated matrix

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.data[i][j] = mat1.data[i][j];

    return mat;
}

template<class T>
matrix<T>::~matrix()
{
//    for (int i = 0; i < row; i++){
//        delete [] data[i];
//    }
//    delete[] data;
//    data = NULL;
}


