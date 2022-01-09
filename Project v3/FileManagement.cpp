//
//  FileManagement.cpp
//  Project
//
//  Created by Javier Galindos on 28/11/20.
//

#include "FileManagement.hpp"

using Eigen::MatrixXd;
using namespace std;

// This Funtion reads a csv file and save it within a dynamic matrix
// It returns 0 whether it works and -1 otherwise
int csvRead(MatrixXd& outputMatrix, const string& fileName, const streamsize dPrec)
{
    ifstream inputData;
    inputData.open(fileName);
    cout.precision(dPrec);
    
    if(!inputData) //Wheter does not work, return -1
        return -1;
    
    string fileline, filecell;
    unsigned int prevNoOfCols = 0; // Previous number of columns
    unsigned int noOfRows = 0;  // Number of rows
    unsigned int noOfCols = 0;  // Number of columns
    
    // Get the number of rows and columns
    while (getline(inputData,fileline)) {
        noOfCols=0;
        stringstream linestream(fileline); // Wraps a string with a stream interface
        
        //  Get the values of the line separated by comma
        while(getline(linestream,filecell,COMMA)) {
            try {                   // See if the content is a valid number
                stod(filecell); // String to double
            } catch (...) {
                return -1;          // Return whether is wrong
            }
            noOfCols++; // Increment number of columns
        }
        if (noOfRows++ == 0)  // Happens for the first line
            prevNoOfCols = noOfCols;
        
        if (prevNoOfCols != noOfCols) // Whether Two rows with different columns, return
            return -1;
    }
    inputData.close();
    outputMatrix.resize(noOfRows,noOfCols); //  Resize the matrix
    
    inputData.open(fileName);
    noOfRows=0;
    
    //Get the data from file
    while(getline(inputData,fileline)){
        noOfCols = 0;
        stringstream linestream(fileline); // Wraps a string with a stream interface
        // Read the elements separated by comma
        while(getline(linestream, filecell,COMMA)){
            outputMatrix(noOfRows, noOfCols++) = stod(filecell);
        }
        noOfRows++;
    }
    return 0;   // Everything works
    
}

// This Funtion writes a dynamic matrix within a csv file
// It returns 0 whether it works and -1 otherwise
int csvWrite(const MatrixXd& inputMatrix,const string& fileName, const streamsize dPrec){
    int i,j;
    
    ofstream outputData;
    outputData.open(fileName);
    if(!outputData)     // Return whether the file can not be opened
        return -1;
    outputData.precision(dPrec);
    
    for(i=0; i < inputMatrix.rows(); i++){
        for(j=0; j < inputMatrix.cols(); j++){
            outputData << inputMatrix(i,j);
            if (j < (inputMatrix.cols() - 1)) // Whether the last column has not been reached
                outputData << COMMA;
        }
        if (i < (inputMatrix.rows() - 1))   //  Whether the last row is not reached
            outputData << endl;
    }
    outputData.close();
    if(!outputData) // Check whether the close was succesful
        return -1;
    return 0; // Everything works
}
