// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Classes

// Functions
void read_row(std::vector<bool>& row, std::string& line){
    for (int i=0; i<row.size(); i++){
        if (line.at(i)=='.'){
            row[i]=false;
        }else if(line.at(i)=='#'){
            row[i]=true;
        };
    };
};

// Planning on making a vector of pointers that point to vectors of each row 
// Use remainder of column numbers to wrap around
// Program
int main() {

std::string line;
char letter;

int num_trees, max_column;

std::vector<bool> Tree_row;
std::vector<std::vector<bool>> Trees;

// Open input file
std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

// Get the maximum number of columns from the first line
std::getline(inputfile, line);

max_column=line.length();
Tree_row.resize(max_column);

// Put first line into the vectors
read_row(Tree_row, line);
Trees.push_back(Tree_row);

// Put rest of the lines into the 2d vector
while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    read_row(Tree_row, line);
    Trees.push_back(Tree_row);
};

// Close input file
inputfile.close();

// Setup slopes
std::vector<std::vector<int>> slopes;

slopes={{1, 1, 0}, {3, 1, 0}, {5, 1, 0}, {7, 1, 0}, {1, 2, 0}};

// Iterate through the woods
int max_row, column, row, right_step, down_step, tree_count=0;
max_row=Trees.size();

for(int i=0; i<slopes.size(); i++){
    right_step=slopes[i][0];
    down_step=slopes[i][1];
    tree_count=0;

    for (int row=0; row<max_row; row+=down_step){
        column=((row/down_step)*right_step) % max_column;

        if(Trees[row][column]==true) tree_count++;
    };

    slopes[i][2]=tree_count;
};

long long int total=1;

for (int i=0; i<slopes.size(); i++){
    total*=slopes[i][2];
};

std::cout << total << std::endl;

}