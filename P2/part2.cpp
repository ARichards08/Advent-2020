// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Classes
class passentry{
public:
    int min;
    int max;
    char letter;
    std::string password;
    bool valid;

    // Constructors
    passentry(int cmin, int cmax, char cletter, std::string cpassword, bool cvalid=false){
        min=cmin;
        max=cmax;
        letter=cletter;
        password=cpassword;
        valid=cvalid;
    };
};

// Functions
int countFreq(std::string& letter, std::string& password){
    int freq=0;
    std::string::size_type pos=0;
    while ((pos=password.find(letter, pos)) != std::string::npos){
        freq++;
        pos+=1;
    };
    return freq;
};

// Program
int main() {

std::string line, password;
char letter;

int min, max;

std::vector<passentry> passwords;

std::ifstream inputfile;
inputfile.open("input.txt", std::ios::in);

while(true){
    std::getline(inputfile, line);
    if(!inputfile) break; // test eof to break

    std::replace(line.begin(), line.end(), '-', ' ');
    std::replace(line.begin(), line.end(), ':', ' ');

    std::string entry1=line.substr(0, line.find(" "));
    line.erase(0, entry1.length()+1);

    std::string entry2=line.substr(0, line.find(" "));
    line.erase(0, entry2.length()+1);

    letter=line.at(0);
    line.erase(0, 3);

    password=line.substr(0, line.find(" "));

    min=std::stoi(entry1);
    max=std::stoi(entry2);

    passwords.push_back(passentry(min, max, letter, password));
};

inputfile.close();

std::string passcode;
for(int i=0; i<passwords.size(); i++){
    passcode=passwords[i].password;
    if((passcode.at(passwords[i].min-1) == passwords[i].letter) || (passcode.at(passwords[i].max-1)==passwords[i].letter)){
        if((passcode.at(passwords[i].min-1) == passwords[i].letter) && (passcode.at(passwords[i].max-1)==passwords[i].letter)){
            continue;
        }else{
            passwords[i].valid=true;
        };
    };
};

int countValid=0;
for (int i=0; i<passwords.size(); i++){
    if (passwords[i].valid == true) countValid++;
};

std::cout << countValid << std::endl;
}