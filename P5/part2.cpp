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

int seat_num(std::string seat){
    int num;

    num=row_id(seat)*8 + column_id(seat);

    return num;
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

int my_seat, old_my_seat, id, bottom_id=INT_MAX, top_id=0;

// Work out minimum and maximum seats
for (int i=0; i<seats.size(); i++){
    id=seat_num(seats[i]);
    if (id > top_id) top_id=id;
    if (id < bottom_id) bottom_id=id;
};

std::cout << bottom_id << " " << top_id <<std::endl;

my_seat=bottom_id;

bool next_seat;

while (true){
    old_my_seat=my_seat;
    next_seat=false;

    for (int i=0; i<seats.size(); i++){
        if (seat_num(seats[i]) == my_seat+1) next_seat=true;
    };

    if (next_seat==true){
        my_seat++;
    } else{
        my_seat++;
        break;
    };
};

std::cout << "My seat is " << my_seat << std::endl;

// 557

}