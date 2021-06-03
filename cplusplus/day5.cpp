
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> read_file(string filename){

    ifstream myfile (filename);

    int total_valid = 0;

    string line;

    vector<int> program_instructions;

    if (myfile.is_open()){
        while ( getline (myfile,line) ){
           program_instructions.push_back(stoi(line));
        }
        myfile.close();
    }
    return program_instructions;
}

int get_steps_till_exit(vector<int>instructions){
    int index = 0;
    int steps_taken = 0;
    cout << "length list: " << instructions.size() << endl;
    while (index < instructions.size()){
        int to_jump = instructions[index];
        instructions[index]++;
        steps_taken++;
        index += to_jump;
    }
    return steps_taken;
}


int get_steps_till_exit_part2(vector<int>instructions){
    int index = 0;
    int steps_taken = 0;
    cout << "length list: " << instructions.size() << endl;
    while (index < instructions.size()){
        int to_jump = instructions[index];
        if (to_jump >= 3){
            instructions[index]--;
        }
        else{
            instructions[index]++;
        }

        steps_taken++;
        index += to_jump;
    }
    return steps_taken;
}
int main(){
    vector<int> instructions = read_file("input_day5.txt");
    cout << "Part 1: " << get_steps_till_exit(instructions) << endl;

    instructions = read_file("input_day5.txt");
    cout << "Part 2: " << get_steps_till_exit_part2(instructions) << endl;

    return 0;
}
