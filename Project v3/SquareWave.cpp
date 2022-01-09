//
//  SquareWave.cpp
//  Project
//
//  Created by Javier Galindos on 29/11/20.
//  This file uses a python wrapper. You have to install python and matplotlibcpp to use it.

#include "SquareWave.hpp"

using Eigen::MatrixXd;
using namespace std;
namespace plt = matplotlibcpp;

// Constructors
SquareWave::SquareWave(){
    Amplitude=0.0;
    frequency=0.0;
    dutyCycle=0.0;
}

SquareWave::SquareWave(double Amplitude, double frequency, double dutyCycle)
{
    this->Amplitude = Amplitude;
    this->frequency = frequency;
    this->dutyCycle = dutyCycle;
}

// Destructor
SquareWave::~SquareWave(){
}

// Setters
void SquareWave::setAmplitude(double Amplitude){
    this->Amplitude = Amplitude;
}

void SquareWave::setFrequency(double frequency){
    this->frequency = frequency;
}

void SquareWave::setDutyCycle(double dutyCycle){
    this->dutyCycle = dutyCycle;
}

// Getters
double SquareWave::getAmplitude() const{
    return Amplitude;
}

double SquareWave::getFrequency() const{
    return frequency;
}

double SquareWave::getDutyCycle() const{
    return dutyCycle;
}

// This function saves the values of a Matrix in objects of the class SquareWave.
// Be carefull: this function deletes the matrix. Data is save within the classes.
void Matrix2Classes(MatrixXd& inputMatrix,vector<SquareWave> &Signals){
    double Amplitude,frequency,dutuCycle;
    // Reseve number of elements of the vector. Speeds things up a bit
    Signals.reserve(inputMatrix.rows());
    
    // Save the values of each rows of a Matrix in objects of the class SquareWave
    for(int i=0; i < inputMatrix.rows(); i++){
        Amplitude = inputMatrix(i,0);
        frequency = inputMatrix(i,1);
        dutuCycle = inputMatrix(i,2);
        Signals.push_back(SquareWave(Amplitude, frequency, dutuCycle));
    }
    
    inputMatrix.resize(0,0); // Free the space for the matrix
}

// This function saves the data of the Signals wthin a dynamic Matrix.
// Be carefull: this function deletes the vector of objests. Data is save within the matrix.
void Classes2Matrix(vector<SquareWave> &Signals, MatrixXd& outputMatrix){
    
    outputMatrix.resize(Signals.size(),3); //  Resize the matrix
    
    // Save the data wthin the Matrix
    for(int i=0; i < Signals.size();i++){
        outputMatrix(i, 0) = Signals[i].getAmplitude();
        outputMatrix(i, 1) = Signals[i].getFrequency();
        outputMatrix(i, 2) = Signals[i].getDutyCycle();
    }
    
    Signals.clear(); // Deletes the vector.
}

// Function to add a new Signal by the user
void addSignal(vector<SquareWave> &Signals){
    double Amplitude,frequency,dutuCycle;
    cout << "New Signal:" <<endl;
    cout << "Amplitude: ";
    cin >> Amplitude;
    cin.clear(); // Flush cin. Prevent some problems
    fflush(stdin); // Flush stdin. Prevent some problems
    do{
        cout <<"Frequency: (positive number)"<<endl;
        cin >> frequency;
        cin.clear(); //Flush cin
        fflush(stdin); // Flush stdin
    }while(frequency < 1); // Repeat untill the user type a correct value
    
    do{
        cout <<"Duty Cycle: (number between 0 < d < 1)"<<endl;
        cin >> dutuCycle;
        cin.clear(); //Flush cin
        fflush(stdin); // Flush stdin
    }while((dutuCycle >= 1) || (dutuCycle <= 0)); // Repeat untill the user type a correct value
    
    Signals.push_back(SquareWave(frequency, frequency, dutuCycle));
    
}

// Print the Sigals
void printSignals(const vector<SquareWave> &Signals)
{
    for(int i=0; i < Signals.size();i++){
        cout <<"Signal "<<i+1<<":\n";
        cout <<"Amplitude: "<< setprecision(5) << Signals[i].getAmplitude() <<" ";
        cout <<"Frequency: "<< setprecision(5) << Signals[i].getFrequency() <<" ";
        cout <<"Duty cycle: "<< setprecision(5)<< Signals[i].getDutyCycle() <<endl;
    }
    
}


// This funtion plots the signal using the library Matplotlib-cpp (Python wrapper)
void plotSignals(const vector<SquareWave> &Signals){
    
    vector <double> x,y;
    double Ts; // Time switching
    double amplitude, frequency, duty;
    
    for(int i=0; i < Signals.size(); i++){
        
        // Get the values from the class
        amplitude = Signals[i].getAmplitude();
        frequency = Signals[i].getFrequency();
        duty = Signals[i].getDutyCycle();
        
        Ts = 1000 / frequency; // In milisecons
        x={0,0,duty*Ts,duty*Ts,Ts,Ts}; // X-axis
        y={0,amplitude,amplitude,0,0,amplitude}; // Y-axis
        
        //Title
        string signalNum= "Signal " + to_string(i+1);
        string Title = signalNum + "\nA=" + to_string(amplitude) + "V  f=" + to_string(frequency) + "Hz  d=" + to_string(duty);
        
        //Plotting
        plt::figure(i+1);
        plt::grid('1');
        plt::plot(x,y,{{"label", signalNum}});
        plt::title(Title);
        plt::xlabel("Time(ms)");
        plt::ylabel("Amplitude(V)");
        plt::legend();
        plt::show();
    }
}

