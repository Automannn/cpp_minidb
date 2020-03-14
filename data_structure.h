//
// Created by 14394 on 2020/3/14.
//

#ifndef CPP_MINIDB_DATA_STRUCTURE_H
#define CPP_MINIDB_DATA_STRUCTURE_H

#include <iostream>
#include <vector>

using namespace std;

class Table {
public:
    int mkeyWordNum;
    int mRecordNm;
    vector<vector<string>> mTable;
    vector<string> mDataType;
    vector<bool> mPosList;
};


#endif //CPP_MINIDB_DATA_STRUCTURE_H
