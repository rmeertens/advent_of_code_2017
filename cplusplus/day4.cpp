
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

int get_count_valid_passphrases(string filename, bool allow_anagrams){

    ifstream myfile (filename);

    int total_valid = 0;

    string line;
    string var;
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            stringstream ss(line);
            unordered_set<string> seen_passwords;

           bool is_valid = true;
            while(ss >> var){
                if (!allow_anagrams){
                    sort(var.begin(), var.end());
                }
                if (seen_passwords.count(var) > 0){
                    is_valid = false;
                    break;
                }
                seen_passwords.insert(var);
            }
            if (is_valid){
                total_valid ++;
            }
        }
        myfile.close();
    }
  return total_valid;

}

int main()
{
    cout << "valid passphrases part 1: " << get_count_valid_passphrases("input_day4.txt", true) << endl;
    cout << "valid passphrases part 2: " << get_count_valid_passphrases("input_day4.txt", false) << endl;

    return 0;
}
