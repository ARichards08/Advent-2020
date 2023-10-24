// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

// Classes

// Functions

int row_id(std::string seat){
    std::string row_str;
    int row;

    row_str=seat.substr(0, 7);

    row=0;
    for (int i=0; i<row_str.length(); i++){
        if(row_str[i] == 'B') row+=pow(2, row_str.length()-1-i);
    };

    return row;
};

int column_id(std::string seat){
    std::string column_str;
    int column;

    column_str=seat.substr(7, 3);

    column=0;
    for (int i=0; i<column_str.length(); i++){
        if(column_str[i] == 'R') column+=pow(2, column_str.length()-1-i);
    };
    return column;
};


// Program
int main() {


/////////////
// File input


std::string line;
std::vector<std::string> seats;

// Open input file
std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

// Read file into array
while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    seats.push_back(line);
};

// Close input file
inputfile.close();

//////////////
// Calculation

int id, top_id=0;

for (int i=0; i<seats.size(); i++){
    id=row_id(seats[i])*8 + column_id(seats[i]);
    if (id > top_id) top_id=id;
};

std::cout << top_id <<std::endl;

}