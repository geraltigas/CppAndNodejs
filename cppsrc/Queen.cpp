//
// Created by 浆布 on 17/11/2021.
//

#include "Queen.h"
#include <iostream>
#include <deque>
using namespace std;

QueenAns::QueenAns(int *ans, int layer) {
    this->ans = new int[8];
    for (int i = 0; i < 8; ++i) {
        if (i <= layer) {
            (this->ans)[i] = ans[i];
        } else{
            (this->ans)[i] = -1;
        }
    }
    this->layer = layer;
}

vector<QueenAns*> &QueenAns::generate() {
    vector<QueenAns*>& temp = *(new vector<QueenAns*>());
    int tLayer = this->layer+1;
    QueenAns* tempAns = nullptr;
    for(int i = 0 ; i < 8 ; ++i) {
        int* ansArray = new int[8];
        for (int j = 0; j < tLayer; ++j) {
            ansArray[j] = (this->ans)[j];
        }
        ansArray[tLayer] = i;
        tempAns = new QueenAns(ansArray,tLayer);
        if (check(*tempAns)) temp.push_back(tempAns);
        delete[] ansArray;
    }
    return temp;
}

QueenAns::~QueenAns() {
    delete [] this->ans;
}

string QueenAns::print() {
    long temp = 0;
    for (int i = 0; i < 8; ++i) {
        temp = temp*10 + this->ans[i];
    }
    string* temps = new string(to_string(temp));
    if(temps->length() <= 7) {
        temps = new string("0"+*temps);
    }
    return *(temps);
}

bool check(QueenAns& ans) {
    if (ans.layer == 0) {
        return true;
    }else {
        for (int i = 0; i < ans.layer; ++i) {
            bool a = ans.ans[i] == ans.ans[ans.layer];
            float spur = abs((float )(ans.ans[i] - ans.ans[ans.layer])/(ans.layer - i));
//            cout <<"(" << ans.ans[i] <<" " << ans.ans[ans.layer]<<  " "<< i <<" " << ans.layer <<")" << a << " " << spur << endl;
            if (a || spur == 1) return false;
        }
    }
    return true;
}

string dfs() {
    int originA[] = {0,0,0,0,0,0,0,0};
    QueenAns* origin = new QueenAns(originA,-1);
    auto ansStorage = vector<QueenAns*>();
    auto midDeque = deque<QueenAns*>();
    midDeque.push_front(origin);
    while(!midDeque.empty()) {
        QueenAns* temp = midDeque.front();
        midDeque.pop_front();
        auto tempArray = temp->generate();
        for (int i = 0; i < tempArray.size(); ++i) {
            if (tempArray[i]->layer == 7) {
                ansStorage.push_back(tempArray[i]);
            }else {
                midDeque.push_front(tempArray[i]);
            }
        }
    }
    string answer = "";
    for (int i = 0; i < ansStorage.size(); ++i) {
        answer = answer + " " + ansStorage[i]->print();
    }
    return answer;
}

string bfs() {
    int originA[] = {0,0,0,0,0,0,0,0};
    QueenAns* origin = new QueenAns(originA,-1);
    auto ansStorage = vector<QueenAns*>();
    auto midDeque = deque<QueenAns*>();
    midDeque.push_front(origin);
    while(!midDeque.empty()) {
        QueenAns* temp = midDeque.front();
        midDeque.pop_front();
        auto tempArray = temp->generate();
        for (int i = 0; i < tempArray.size(); ++i) {
            if (tempArray[i]->layer == 7) {
                ansStorage.push_back(tempArray[i]);
            }else {
                midDeque.push_back(tempArray[i]);
            }
        }
    }
    string answer = "";
    for (int i = 0; i < ansStorage.size(); ++i) {
        answer = answer + " " + ansStorage[i]->print();
    }
    return answer;
}

void a_star() {

}
