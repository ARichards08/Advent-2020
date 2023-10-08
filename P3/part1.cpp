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

// Iterate through the woods
int max_row, column, row, tree_count=0;
max_row=Trees.size();

for (int row=0; row<max_row; row++){
    column=(row*3) % max_column;

    if(Trees[row][column]==true) tree_count++;
};

std::cout << tree_count << std::endl;

}