//
//  SquareWave.hpp
//  Project
//
//  Created by Javier Galindos on 29/11/20.
//

#ifndef SquareWave_hpp
#define SquareWave_hpp

#include <iostream>
#include <vector>
#include <iomanip>
#include "Eigen/Dense"
#include "Eigen/LU"
#include "matplotlibcpp.h"

using Eigen::MatrixXd;
namespace plt = matplotlibcpp;
using namespace std;


class SquareWave{
private:
    double Amplitude;
    double frequency;
    double dutyCycle;
public:
    SquareWave();
    SquareWave(double Amplitude, double frequency, double dutyCycle);
    ~SquareWave();
    void setAmplitude(double Amplitude);
    void setFrequency(double frequency);
    void setDutyCycle(double dutyCycle);
    double getAmplitude() const;
    double getFrequency() const;
    double getDutyCycle() const;
};


void Matrix2Classes(MatrixXd& inputMatrix, vector<SquareWave> &Signals);
void Classes2Matrix(vector<SquareWave> &Signals, MatrixXd& outputMatrix);
void addSignal(vector<SquareWave> &Signals);
void printSignals(const vector<SquareWave> &Signals);
void plotSignals(const vector<SquareWave> &Signals);


#endif /* SquareWave_hpp */
