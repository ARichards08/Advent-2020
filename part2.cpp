// Included packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Classes

// Functions
//bool is_af(char letter){
//    if (letter=='a'){
//        return true;
//    } else if (letter=='b'){
//        return true;
//    } else if (letter=='c'){
//        return true;
//    } else if (letter=='d'){
//        return true;
//    } else if (letter=='e'){
//        return true;
//    } else if (letter=='f'){
//        return true;
//    } else {
//        return false;
//    };
//};

//bool byr_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("byr:");
//
//    if (pos!=std::string::npos){
//        std::string byr=passport.substr(pos+4, 4);
//
//        int byr_int=stoi(byr);
//
//        if (byr_int>1920 && byr_int<2002) result=true;
//    };
//
//    return result;
//};

//bool iyr_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("iyr:");
//
//    if (pos!=std::string::npos){
//        std::string iyr=passport.substr(pos+4, 4);
//        int iyr_int=stoi(iyr);
//
//        if (iyr_int>2010 && iyr_int<2020) result=true;
//    };    
//
//    return result;
//};

//bool eyr_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("eyr:");
//
//    if (pos!=std::string::npos){
//        std::string eyr=passport.substr(pos+4, 4);
//        int eyr_int=stoi(eyr);
//
//        if (eyr_int>2020 && eyr_int<2030) result=true;
//    };
//
//    return result;
//};

//bool hgt_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("hgt:");
//
//    if (pos!=std::string::npos){
//
//        std::string hgt, short_str;
//        int hgt_int;
//        char letter;
//
//        pos+=4;
//
//        while (true){
//
//            letter=passport[pos];
//
//            if (isdigit(letter)==true){
//                hgt+=letter;
//                pos++;
//            } else if (isdigit(letter)==false){
//                short_str=passport.substr(pos, 2);
//                hgt_int=stoi(hgt);
//
//                if ((short_str=="cm" && (hgt_int>150 && hgt_int<193)) || (short_str=="in" && (hgt_int>59 && hgt_int<76))) {
//                    result=true;
//                    break;
//                } else {
//                    break;
//                };
//            };
//        };
//    };
//
//    return result;
//
//};

//bool hcl_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("hcl:");
//
//    if (pos!=std::string::npos){
//
//        std::string hcl;
//        pos+=4;
//
//        hcl=passport.substr(pos, 7);
//
//        while (true){
//
//            if (hcl[0]!='#') break;
//
//            for (int i=1; i<7; i++){
//                if (isdigit(hcl[i])==false && is_af(hcl[i])==false) break;
//            };
//
//            result=true;
//            break;
//        };
//    };
//
//    return result;
//
//};

//bool ecl_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("ecl:");
//
//    if (pos!=std::string::npos){
//
//        std::string ecl;
//        pos+=4;
//
//        ecl=passport.substr(pos, 3);
//
//        if (ecl=="amb" || ecl=="blu" || ecl=="brn" || ecl=="gry" || ecl=="grn" || ecl=="hzl" || ecl=="oth"){
//            result=true;
//        };
//    };
//
//    return result;
//
//};

//bool pid_test(std::string passport){
//    bool result=false;
//    int pos=passport.find("pid:");
//
//    if(pos!=std::string::npos){
//        std::string pid;
//        int counter=0;
//
//        pos+=+4;
//
//        pid=passport.substr(pos, 9);
//
//        for (int i=0; i<pid.length(); i++){
//            if (isdigit(pid[i])==true){
//                counter++;
//            };
//        };
//
//        if (counter==pid.length()) result=true;
//    };
//
//    return result;
//
//};

//bool passport_validity(std::string passport_str){
//    int fields=0;

    // Birth year field
//    if (byr_test(passport_str)==true) fields++;

    // Issue year field
//    if (iyr_test(passport_str)==true) fields++; 

    // Expiration year field
//    if (eyr_test(passport_str)==true) fields++;

    // Height field
//    if (hgt_test(passport_str)==true) fields++;

    // Hair colour field
//    if (hcl_test(passport_str)==true) fields++;

    // Eye colour field
//    if (ecl_test(passport_str)==true) fields++;

    // Passport ID field
//    if (pid_test(passport_str)==true) fields++;

    // Checking number of fields that are valid
//    if(fields==7){
//        return true;
//    } else {
//        return false;
//    };
//};

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

//if (byr_test(entries[0])==true){
//    std::cout << "byr yep" << std::endl;
//} else {
//    std::cout << "byr nope" << std::endl;
//};

//if (iyr_test(entries[0])==true){
//    std::cout << "iyr yep" << std::endl;
//} else {
//    std::cout << "iyr nope" << std::endl;
//};

//if (eyr_test(entries[0])==true){
//    std::cout << "eyr yep" << std::endl;
//} else {
//    std::cout << "eyr nope" << std::endl;
//};

//if (hgt_test(entries[0])==true){
//    std::cout << "hgt yep" << std::endl;
//} else {
//    std::cout << "hgt nope" << std::endl;
//};

//if (hcl_test(entries[0])==true){
//    std::cout << "hcl yep" << std::endl;
//} else {
//    std::cout << "hcl nope" << std::endl;
//};

//if (ecl_test(entries[0])==true){
//    std::cout << "ecl yep" << std::endl;
//} else {
//    std::cout << "ecl nope" << std::endl;
//};

//if (byr_test(entries[0])==true){
//    std::cout << "byr yep" << std::endl;
//} else {
//    std::cout << "byr nope" << std::endl;
//};

//if (pid_test(entries[0])==true){
//    std::cout << "pid yep" << std::endl;
//} else {
//    std::cout << "pid nope" << std::endl;
//};

//int pos=entries[0].find("byr:");
//std::cout << pos << std::endl;
}