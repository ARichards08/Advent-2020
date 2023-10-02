// Included packages
#include <iostream>
#include <fstream>
#include <vector>

// Program
int main() {

std::vector<int> numbers;
int sum, entries=200, entry;

std::ifstream inputfile;
inputfile.open("input.txt");

for (int i=0; i<entries; i++){
    inputfile >> entry;
    numbers.push_back(entry);
};

inputfile.close();

for (int i=0; i<numbers.size(); i++){
    for (int j=0; j<numbers.size(); j++){
        for (int k=0; k<numbers.size(); k++){
            sum=0;
            sum=numbers[i]+numbers[j]+numbers[k];
            if (sum == 2020) {
                std::cout << numbers[i] << " " << numbers[j] << " " << numbers[k] << std::endl;
                std::cout << numbers[i]*numbers[j]*numbers[k] << std::endl;
                goto endloop1; // goto used to break nested loop
            };
        };
    };
};
endloop1:

}