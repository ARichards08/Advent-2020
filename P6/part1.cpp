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
int group_count(std::vector<std::string> group_answers){
    int count;
    std::vector<char> answers;
    bool already_answered=false;
    std::string person;
    
    for (int i=0; i<group_answers.size(); i++){
        person=group_answers[i];

        for (int j=0; j<person.length(); j++){            
            already_answered=std::find(std::begin(answers), std::end(answers), person[j]) != std::end(answers);

            if (already_answered==false){
                count++;
                answers.push_back(person[j]);
            };
        };


    };
    return count;
};

// Program
int main() {

/////////////
// File input

std::string line;
std::vector<std::string> entry;
std::vector<std::vector<std::string>> entries;

// Open input file
std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

// Read file into array
while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    if (line.length()==0){
        entries.push_back(entry);
        entry.clear();
    } else{
        entry.push_back(line);
    };
};

// Deal with last line
entries.push_back(entry);

// Close input file
inputfile.close();

//////////////
// Calculation

int count_sum=0;

for (int i=0; i<entries.size(); i++){
    count_sum+=group_count(entries[i]);
};

std::cout << count_sum << std::endl;

}