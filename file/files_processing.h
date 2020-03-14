//
// Created by 14394 on 2020/3/14.
//

#ifndef CPP_MINIDB_FILES_PROCESSING_H
#define CPP_MINIDB_FILES_PROCESSING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <direct.h>

using namespace std;

class FilesProcessing {
public:
    static void changePath(string path_name = "");

    static void createFolder(string dir_name);

    static void deleteFolder(string dir_name);

    static void rename(string pre_name,string new_name);

    static void showAllFiles();

    static void writeTableHeader(int keywordnum,int recordnum,vector<vector<string>>& table,vector<string>& datatype);

    static void writeTableRecord(int keywordnum,vector<vector<string>>& table,vector<int>& poslist);

    static void writeTableIndexes();

    static void readTableHeader(int& keywordnum,int& recordnum,vector<vector<string>>& table,vector<string>& datatype);

    static void readTableRecord(int keywordnum,int recordnum,vector<vector<string>>& table,vector<int>& poslist);

    static void readTableIndexes();
};


#endif //CPP_MINIDB_FILES_PROCESSING_H
