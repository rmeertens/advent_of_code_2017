#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <vector>
#include <map>

using namespace std;

int global_count = 0;
int my_puzzle_input = 289326;
map<string,int> spiral_map;
bool found_answer_part2 = false;

int manhattan_distance(int x, int y, int x2=0, int y2 = 0){
    return abs(x-x2) + abs(y-y2);
}
void spiral_callback_part2(int x, int y){
    if ((x==0 && y == 0) || found_answer_part2){
        return;
    }
    int sum_here = 0;
    for (int deltax=-1; deltax<=1; deltax++){
        for(int deltay = -1; deltay <= 1; deltay++){
            if(deltax != 0 || deltay != 0){
                string coordinate = to_string(x+deltax) + "," + to_string(y+deltay);
                map<string,int>::iterator it = spiral_map.find(coordinate);
                if (it != spiral_map.end()){
                    sum_here += it -> second;
                }

            }
        }
    }

    string coordinate = to_string(x) + "," + to_string(y);
    spiral_map[coordinate] = sum_here;

    if(sum_here > my_puzzle_input){
        cout << "answer to part 2: " << sum_here <<endl;
        found_answer_part2 = true;

    }
}

void spiral_callback_part1(int x, int y){

    global_count += 1;
    if(global_count == my_puzzle_input){
        cout << "manhattan distance part 1: " << manhattan_distance(x,y) << endl;
    }
}


void generate_spiral(int max_width,void (*spiral_callback)(int, int)){
    spiral_callback(0,0);

    for(int side = 1; side <= max_width; side++){
        // right side
        int xpos = side;
        int ypos;
        for (ypos = -1*side+1; ypos < side; ypos++){
            spiral_callback(xpos, ypos);
        }
        // upper side
        ypos = side;
        for (xpos = side; xpos > -1*side; xpos--){
            spiral_callback(xpos, ypos);
        }
        // left side
        xpos = -1*side;
        for (ypos = side; ypos > -1*side; ypos--){
            spiral_callback(xpos, ypos);
        }
        // bottom side

        ypos = -1*side;
        for (xpos = -1*side; xpos <= side; xpos++){
            spiral_callback(xpos, ypos);
        }
    }
}
int main()
{

    generate_spiral(500, spiral_callback_part1);
    global_count = 0;
    spiral_map["0,0"] = 1;
    generate_spiral(500, spiral_callback_part2);
    return 0;
}
