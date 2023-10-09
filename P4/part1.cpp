// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Classes

// Functions
bool passport_validity(std::string passport){
    int fields=0;

    if(passport.find("byr:")!=std::string::npos) fields++;
    if(passport.find("iyr:")!=std::string::npos) fields++;
    if(passport.find("eyr:")!=std::string::npos) fields++;
    if(passport.find("hgt:")!=std::string::npos) fields++;
    if(passport.find("hcl:")!=std::string::npos) fields++;
    if(passport.find("ecl:")!=std::string::npos) fields++;
    if(passport.find("pid:")!=std::string::npos) fields++;    

    if(fields==7){
        return true;
    } else {
        return false;
    };
};

// Planning on making a vector of pointers that point to vectors of each row 
// Use remainder of column numbers to wrap around
// Program
int main() {

std::string line, entry;
std::vector<std::string> entries;

int line_count=0;

// Open input file
std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

// Read file into array
while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    line_count++;

    if (line.length()==0){
        entries.push_back(entry);
        entry.clear();
        line_count=0;
    } else if (line_count==1){
        entry=entry+line;
    } else if (line_count>1){
        entry=entry+' '+line;
    };
};

// Deal with last line
entries.push_back(entry);

// Close input file
inputfile.close();

int valid_pps=0;

for (int i=0; i<entries.size(); i++){
    if (passport_validity(entries[i])==true) {
        valid_pps++;
    };
};

std::cout << valid_pps << std::endl;

std::cout << entries[0] << std::endl;
}