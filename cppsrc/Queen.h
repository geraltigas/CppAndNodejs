//
// Created by 浆布 on 17/11/2021.
//
#include <vector>
#include <string>
using std::vector;
using std::string;

#ifndef DATA_STRUCTURE_LEARN_QUEEN_H
#define DATA_STRUCTURE_LEARN_QUEEN_H

class QueenAns{
public:
    int* ans;
    int layer;
    QueenAns(int* ans,int layer);
    ~QueenAns();
    vector<QueenAns*>& generate();
    string print();
};
bool check(QueenAns& ans);
string dfs();
string bfs();
void a_star();



#endif //DATA_STRUCTURE_LEARN_QUEEN_H
