//
//  UI.hpp
//  Project v3
//
//  Created by Javier Galindos on 6/12/20.
//

#ifndef UI_hpp
#define UI_hpp

#include <iostream>
#include "FileManagement.hpp"
#include "SquareWave.hpp"
#include <stdlib.h>

using namespace std;

void init();
int getUserOption();

void readFromCSV(vector<SquareWave> &Signals);
void printDataSignals(const vector<SquareWave> &Signals);
void plotSignalsUI(const vector<SquareWave> &Signals);
void addNewSignal(vector<SquareWave> &Signals);
void save2CSVFile(vector<SquareWave> &Signals);
void Menu(vector<SquareWave> &Signals);
#endif /* UI_hpp */
