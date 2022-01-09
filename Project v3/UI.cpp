//
//  UI.cpp
//  Project v3
//
//  Created by Javier Galindos on 6/12/20.
//

#include "UI.hpp"

using namespace std;

void init(){
    cout<<"\n\t\t    ========================================="<< endl;
    cout<<"\t\t    ========================================="<< endl;
    cout<<"\t\t      ||   WELCOME TO SIGNAL MANAGEMENT   ||"<< endl;
    cout<<"\t\t      ||   Design by: Javier Galindos     ||"<< endl;
    cout<<"\t\t    ========================================="<< endl;
    cout<<"\t\t    =========================================\n\n"<< endl;
}


int getUserOption(){
    int option;
    cout<<"     MAIN SCREEN    \n";
    cout<<"[1] Read data from file \n";
    cout<<"[2] Print data from Signals \n";
    cout<<"[3] Plot Signals \n";
    cout<<"[4] Add new signal \n";
    cout<<"[5] Save signals within a file \n";
    cout<<"[6] EXIT \n";
    cout<<"\n";
    cout<<"Enter Option:";
    cin>>option;
    
    return option;
}

void readFromCSV(vector<SquareWave> &Signals){
    system("clear"); // For UNIX systems
    cout << "\n\t READ FROM CSV FILE \n\n";
    // Read data from .csv file
    int error;
    MatrixXd A;
    error = csvRead(A,"myData.csv", 20);
    if(error){
        cout << "Error reading the file"<<endl;
    }else{
    // Save the data from the matrix to objets (Signals)
    Matrix2Classes(A, Signals);
    cout << "Read successful"<<endl;
    }
    fflush(stdin); // Flush stdin.
    cout << "Press ENTER to continue";
    cin.get();
}

void printDataSignals(const vector<SquareWave> &Signals){
    system("clear"); // For UNIX systems
    cout << "\n\t PRINT DATA FROM SIGNALS \n\n";
    if(!Signals.empty())
        printSignals(Signals);
    else
        cout << "No signals avaliable";
    fflush(stdin);
    cout << "Press ENTER to continue";
    cin.get();
}

void plotSignalsUI(const vector<SquareWave> &Signals){
    system("clear"); // For UNIX systems
    cout << "\n\tPLOTING GRAPHS FROM SIGNALS \n\n";
    if(!Signals.empty())
        plotSignals(Signals);
    else
        cout << "No signals avaliable";
    fflush(stdin);
    cout << "Press ENTER to continue";
    cin.get();
}

void addNewSignal(vector<SquareWave> &Signals){
    system("clear"); // For UNIX systems
    cout << "\n\t ADD NEW SIGNAL \n\n";
    addSignal(Signals);
    fflush(stdin);
    cout << "Press ENTER to continue";
    cin.get();
}

void save2CSVFile(vector<SquareWave> &Signals){
    system("clear"); // For UNIX systems
    cout << "\n\tSAVE DATA INTO CSV FILE \n\n";
    int error;
    MatrixXd A;
    Classes2Matrix(Signals, A);
    error = csvWrite(A,"dataOut.csv", 20);
    if(error){
        cout << "Error writing within the file"<<endl;
    }else
        cout << "File succesfully saved" << endl;
    fflush(stdin);
    cout << "Press ENTER to continue";
    cin.get();
}

void Menu(vector<SquareWave> &Signals){
    bool exit = false;

    do {
        switch (getUserOption()) {
            case 1:
                readFromCSV(Signals);
                break;
            case 2:
                printDataSignals(Signals);
                break;
            case 3:
                plotSignalsUI(Signals);
                break;
            case 4:
                addNewSignal(Signals);
                break;
            case 5:
                save2CSVFile(Signals);
                break;
            case 6:
                exit = true;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
                break;
        }

    } while (!exit);
}


