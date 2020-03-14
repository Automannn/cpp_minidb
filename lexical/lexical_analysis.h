//
// Created by 14394 on 2020/3/14.
//

#ifndef CPP_MINIDB_LEXICAL_ANALYSIS_H
#define CPP_MINIDB_LEXICAL_ANALYSIS_H

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class LexicalAnalysis {
private:
    string mStr;//要处理的字符串
    string mKeyWOrd;//关键字
    vector<string>mParameter; //参数表
    bool mCorrect; //输入是否合法

public:
    LexicalAnalysis();

    LexicalAnalysis(string& str);

    ~LexicalAnalysis();

    void analysis();

    void commandHelp(int n);

    void useDataBase();

    void useTable();

    void back();

    void createDatabase();

    void createTable();

    void insert();

    void update();

    void ddelete();

    void select();

    void add();

    void save();

    void setStr(string& str);

    string& getKeyWord();

    vector<string>& getParameter();

    bool correct();
};


#endif //CPP_MINIDB_LEXICAL_ANALYSIS_H
