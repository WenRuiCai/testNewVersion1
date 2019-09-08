//
// Created by 84443 on 2019/8/28.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int least = 999999;
char array[8];
int flag = 0;
int tempLeast = -1;
int hasBeenVisited[8] = {0};

void work(int place, std::map<char, std::string> map1) {
    if (place == 8) {
        if (!flag) {
            flag = 1;
            least = tempLeast;
        }
        for (int i = 0;i < 8;i++) {
            printf("%c ", array[i]);
        }
        printf("\n");
    } else {
        for (int i = 0;i < 8;i++) {
            if (hasBeenVisited[i] == 0) {
                //Ñ°ÕÒ¿ÉÒÔÌîµÄ×Ö·û
                char node = 'A' + i;
                std::string next_node = map1[node];
                int bandwidth = -1;
                for (int j = 0;j < place;j++) {
                    char node_before = array[j];
                    std::string before;
                    before.push_back(node_before);
                    std::string::size_type idx = next_node.find(before);
                    if (idx != std::string::npos) {
                        int width = place - j;
                        bandwidth = (width > bandwidth) ? width : bandwidth;
                    }
                }
                if (tempLeast < 0 && flag == 0) {
                    tempLeast = bandwidth;
                } else if (flag == 0) {
                  tempLeast = (bandwidth > tempLeast) ? bandwidth : tempLeast;
                }
                if (bandwidth > least) {
                    return;
                }
                array[place] = node;
                hasBeenVisited[i] = 1;
                work(place + 1, map1);
                hasBeenVisited[i] = 0;
            }
        }
    }
}

int main() {
    std::map<char, std::string> map1;
    map1['A'] = (std::string)"BF";
    map1['B'] = (std::string)"AGC";
    map1['C'] = (std::string)"BD";
    map1['D'] = (std::string)"CGE";
    map1['E'] = (std::string)"HD";
    map1['F'] = (std::string)"AGH";
    map1['G'] = (std::string)"BDF";
    map1['H'] = (std::string)"EF";
    work(0, map1);
}