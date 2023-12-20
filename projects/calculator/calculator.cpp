#include <iostream>
using namespace std;
#include <vector>
using namespace std;
#include <string>

int add(vector<int> nums) {
    int sum = 0;
    auto it = nums.begin(); // Iterator to the start of the vector
    while (it != nums.end()) {
        sum += *it; // Access the element
        // cout << *it << " "; Access the element
        ++it; // Move to the next element
    }
    return sum;
}

bool isNum(char *str) {
    int i = 0;
    while( str[i] != '\0' ) {
        cout << "char: " << str[i] << "\n";
        if(!isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
    // return isdigit(str[0]) != 0;
}

vector<int> parseInput(char *str) {
    vector<int> nums;
    int i = 0;
    while( str[i] != '\0' ) {
        cout << "char: " << str[i] << "\n";
        if(isdigit(str[i])) {
            nums.push_back(str[i]);
        }
        i++;
    }
    return nums;
}


int main(int argc, char** argv) {
    // cout << "Test main function \n";
    // int nums[5] = {1,2,3,4,5};
    // int arrSize = sizeof(nums)/sizeof(int);
    // cout << "sum: " << add(nums,arrSize) << "\n";
    // cout << isNum("23") << "\n";
    // cout << isNum("test not a number") << "\n";
    vector<int> nums; // Vector of integers
    char *command = argv[1];

    // cout << "Sum: " << add(nums) << endl;

    cout << endl;

    if(argc == 1) {
        cout << "No inputs found, please run the program followed by arguments for the calculator \n";
        return 0;
    }
    for(int i = 2; i < argc; ++i) {
        cout << argv[i] << "\n";
        if(isNum(argv[i])) {
            cout << "is a number \n";
            nums.push_back(std::stoi(argv[i]));
        } else {
            cout << "is not a number \n";
        }
    }
    if(strcmp(command, "add") == 0) {
        cout << "Sum: " << add(nums) << endl;
    } else {
        cout << "Command not found \n";
    }
    return 0;
}