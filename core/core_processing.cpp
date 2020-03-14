//
// Created by 14394 on 2020/3/14.
//

#include "core_processing.h"

CoreProcessing::CoreProcessing(){
    time_t t = time(NULL);
    char a[64];
    strftime(a, sizeof(a),"%Y_%m_%d",localtime(&t));
    strcat(a,".txt");
    mStartTime = a;
    mFP_util.changePath("logs");
    mLog.open(mStartTime,ios::app);
    if(!mLog.is_open())
        cout<<"日志文件创建失败"<<endl;

    mFP_util.changePath();
    mFP_util.changePath("workplace");

    cout<<"工作空间下";
    mFP_util.showAllFiles();
};

CoreProcessing::~CoreProcessing() {
    mLog.close();
}

void CoreProcessing::analysis(string &cmd) {
    mLog<<cmd<<endl;
    mLA_util.setStr(cmd);
    mLA_util.analysis();

    if(mLA_util.correct()){
        string tmp = mLA_util.getKeyWord();
        if("USE DATABASE" == tmp) useDataBase(mLA_util.getParameter()[0]);
        else if("USE TABLE"==tmp) useTable(mLA_util.getParameter()[0]);
        else if("BACK"==tmp) back();
        else if("CREATE DATABASE"==tmp) createDatabase(mLA_util.getParameter()[0]);
        else if("CREATE TABLE"==tmp) createTable(mLA_util.getParameter());
        else if("INSERT"==tmp) insert(mLA_util.getParameter());
        else if("UPDATE"==tmp) update(mLA_util.getParameter());
        else if("DELETE"==tmp) ddelete(mLA_util.getParameter());
        else if("SELECT"==tmp) select(mLA_util.getParameter());
        else if("ADD"==tmp) add(mLA_util.getParameter());
        else if("SAVE"==tmp) save();
    }
}

void CoreProcessing::useDataBase(string name) {
    mFP_util.changePath(name);
    cout<<"数据库"<<name;
    mFP_util.showAllFiles();
}

void CoreProcessing::back() {
    mFP_util.changePath();
    mFP_util.showAllFiles();
}

void CoreProcessing::createDatabase(string name) {
    mFP_util.createFolder(name);
    mFP_util.showAllFiles();
}

void CoreProcessing::readLog(string name) {

}