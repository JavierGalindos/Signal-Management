//
//  FileManagement.hpp
//  Project
//
//  Created by Javier Galindos on 28/11/20.
//

#ifndef FileManagement_hpp
#define FileManagement_hpp

#include <iostream>
#include <fstream>
#include "Eigen/Dense"
#include "Eigen/LU"

#define COMMA ','

using Eigen::MatrixXd;
using namespace std;

int csvRead(MatrixXd& outputMatrix, const string& fileName, const streamsize dPrec);
int csvWrite(const MatrixXd& inputMatrix,const string& fileName, const streamsize dPrec);

#endif /* FileManagement_hpp */
