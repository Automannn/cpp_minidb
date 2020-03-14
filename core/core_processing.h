//
// Created by 14394 on 2020/3/14.
//

#ifndef CPP_MINIDB_CORE_PROCESSING_H
#define CPP_MINIDB_CORE_PROCESSING_H

#include <iostream>
#include "ctime"
#include "../table/table.h"
#include "../lexical/lexical_analysis.h"

using namespace std;

class CoreProcessing: public Table {
public:
    CoreProcessing();

    ~CoreProcessing();

    void analysis(string& cmd);

    void useDataBase(string name);

    void back();

    void createDatabase(string name);

    void readLog(string name);

private:
    LexicalAnalysis mLA_util;
    string mStartTime;
    ofstream mLog;

};


#endif //CPP_MINIDB_CORE_PROCESSING_H
