
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <vector>
using namespace std;

int get_checksum_part1(string filename){

    ifstream myfile (filename);

    int total_checksum = 0;

    string line;
    string var;
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            stringstream ss(line);

            int minfound = INT_MAX;
            int maxfound = INT_MIN;

            while(ss >> var){
                int value = stoi(var);
                minfound = min(value, minfound);
                maxfound = max(value, maxfound);
            }
            total_checksum += maxfound - minfound;
        }
        myfile.close();
    }
  return total_checksum;

}


int get_checksum_part2(string filename){

    ifstream myfile (filename);

    int total_checksum = 0;

    string line;
    string var;
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            stringstream ss(line);
            vector<int> numbers;

            while(ss >> var){
                int value = stoi(var);
                numbers.push_back(value);

            }

            for(int first_index = 0; first_index < numbers.size(); first_index++){
                for(int second_index = first_index+1; second_index < numbers.size(); second_index++){
                    int num1 = numbers[first_index];
                    int num2 = numbers[second_index];

                    int divver1 = max(num1, num2);
                    int devver2 = min(num1, num2);
                    if(divver1 % devver2 == 0){
                        total_checksum += divver1 / devver2;
                    }
                }
            }
        }
        myfile.close();
    }
  return total_checksum;

}
int main()
{

    cout << "Day 2 part 1: " << get_checksum_part1("input_day2.txt") << endl;
    cout << "Day 2 part 2: " << get_checksum_part2("input_day2.txt") << endl;
    return 0;
}
