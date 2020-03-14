//
// Created by 14394 on 2020/3/14.
//

#ifndef CPP_MINIDB_TABLE_H
#define CPP_MINIDB_TABLE_H

#include <iostream>
#include <string>
#include "../file/files_processing.h"

using namespace std;

class Table {
public:
    Table();
    ~Table();

    void createTable(vector<string>& parameter);

    void useTable(string name);

    void insert(vector<string>& parameter);

    void update(vector<string>& parameter);

    void ddelete(vector<string>& arameter);

    void select(vector<string>& parameter);

    void add(vector<string>& parameter);

    void save();

protected:
    Files_processing mFP_util;

private:
    int mKeyWordNum;
    int mRecordNum;
    vector<vector<string>> mTable;
    vector<string> mDataType;
    vector<int> mPosList;
};


#endif //CPP_MINIDB_TABLE_H
