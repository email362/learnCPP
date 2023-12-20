#include <iostream>
using namespace std;
#include <vector>
using namespace std;
#include <string>

enum Command {
    ADD,
    SUB,
    MUL,
    DIV,
    UNDEFINED
};

int add(vector<int> nums) {
    int sum = 0;
    auto it = nums.begin(); // Iterator to the start of the vector
    while (it != nums.end()) {
        sum += *it; // Access the element
        ++it; // Move to the next element
    }
    return sum;
}

bool isNum(char *str) {
    int i = 0;
    while( str[i] != '\0' ) {
        if(!isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
    // return isdigit(str[0]) != 0;
}

Command getCommand(char *str) {
    if(strcmp(str, "add") == 0) {
        return ADD;
    } else if(strcmp(str, "sub") == 0) {
        return SUB;
    } else if(strcmp(str, "mul") == 0) {
        return MUL;
    } else if(strcmp(str, "div") == 0) {
        return DIV;
    } else {
        return UNDEFINED;
    }
}

vector<int> parseNums(int size, char** inputArr) {
    vector<int> nums;
    for(int i = 0; i < size; ++i) {
        if(isNum(inputArr[i])) {
            nums.push_back(std::stoi(inputArr[i]));
        }
    }
    return nums;
}

int runCalculator(int argc, char** argv) {

    vector<int> nums; // Vector of integers
    char *command;

    if(argc == 1) {
        cout << "No inputs found, please run the program followed by arguments for the calculator \n";
        return 0;
    }
    if(argc == 2) {
        cout << "No numbers found, please run the program followed by arguments for the calculator \n";
        return 0;
    }

    command = argv[1];
    nums = parseNums(argc, argv);

    switch(getCommand(command)) {
        case ADD:
            cout << "Sum: " << add(nums) << endl;
            break;
        default:
            cout << "Command not found \n";
            break;
    }

    return 0;
}

int main(int argc, char** argv) {
    return runCalculator(argc, argv);
}