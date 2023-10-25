// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

// Classes
class answer_freq{
public:
    char answer;
    int freq;

    // Default constructor
    answer_freq(char canswer, int cfreq=1){
        answer=canswer;
        freq=cfreq;
    };
};


// Functions
int group_count(std::vector<std::string> group_answers){
    int count, group_size=group_answers.size();
    std::vector<answer_freq> answers;
    std::string person;
    char letter;
    
    for (int i=0; i<group_answers.size(); i++){
        person=group_answers[i];

        // https://stackoverflow.com/questions/15517991/search-a-vector-of-objects-by-object-attribute
        for (int j=0; j<person.length(); j++){  
            letter=person[j];          
            auto search=std::find_if(answers.begin(), answers.end(), [&letter] (const answer_freq& obj) {return obj.answer == letter;});

            if (search==answers.end()){
                answers.push_back(person[j]);
            } else{
                auto index=std::distance(answers.begin(), search);
                answers[index].freq++;
            };
        };
    };

    for (int i=0; i<answers.size(); i++){
        if (answers[i].freq==group_size) count++;
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