//
// Created by 14394 on 2020/3/14.
//

#include "files_processing.h"

void FilesProcessing::changePath(string path_name) {
    if(path_name.empty()){
        char path[_MAX_DIR];
        _getcwd(path,_MAX_DIR);

        string path0 = path;
        int tmp = path0.find_last_of("/\\");
        path_name = path0.substr(0,tmp);
    }
    if(_chdir(path_name.c_str()))
        cout<<"不存在该目录"<<endl;
}

void FilesProcessing::createFolder(string dir_name) {
    _mkdir(dir_name.c_str());
}

void FilesProcessing::deleteFolder(string dir_name) {
    _rmdir(dir_name.c_str());
}

void FilesProcessing::rename(string pre_name, string new_name) {
    rename(pre_name.c_str(),new_name.c_str());
}

void FilesProcessing::showAllFiles() {
    char path[_MAX_DIR];
    _getcwd(path,_MAX_DIR);
    strcat(path,"\\*");

    long handle;  //用于查找的句柄
    vector<string> files;  //保存文件名
    struct _finddata_t fileinfo;  //文件信息的结构体
    handle = _findfirst(path,&fileinfo);  //第一次查找
    if(-1 == handle)
        cout <<"不存在查找的目录"<<endl;
    files.push_back(fileinfo.name);
    while(!_findnext(handle,&fileinfo)){
        files.push_back(fileinfo.name);
    }
    _findclose(handle);
    if(files.size()<=2)
        cout <<"不存在文件"<<endl;
    else{
        cout<<"存在以下文件:"<<endl;
        for(int i=2;i<files.size();i++)
            cout<<files[i]<<endl;
    }
}

void FilesProcessing::writeTableHeader(int keywordnum, int recordnum, vector<vector<string> > &table, vector<string> &datatype) {
    ofstream header("表头.txt", ios::out);
    if (!header.is_open())
        cout << "表头文件写入出错!!" << endl;
    else {
        header << keywordnum << " " << recordnum << endl;
        for (int i = 0; i < keywordnum; i++)
            header << table[i][0] << " " << datatype[i] << endl;
        header.close();
    }
}

void FilesProcessing::writeTableRecord(int keywordnum, vector<vector<string> > &table, vector<int> &poslist) {
    ofstream record("数据.txt",ios::out);
    if(!record.is_open())
        cout<<"数据文件写入出错!!"<<endl;
    else{
        int len = poslist.size();
        for(int i=1;i<len&&poslist[i];i++){
            for(int j=0;j<keywordnum-1;j++)
                record<<table[j][i]<<" ";
            record<<table[keywordnum-1][i]<<endl;
        }
        record.close();
    }
}

void FilesProcessing::writeTableIndexes() {

}

void FilesProcessing::readTableHeader(int &keywordnum, int &recordnum, vector<vector<string> > &table, vector<string> &datatype) {
    ifstream header("表头.txt",ios::in);
    if(!header.is_open())
        cout<<"表头文件读取出错!!"<<endl;
    else{
        char str[300];
        header>>keywordnum>>recordnum;
        header.getline(str,300);
        for(int i=0; i<keywordnum;i++){
            header.getline(str,300);
            char* tmp;
            tmp = strtok(str," ");
            table[i].push_back(tmp);
            tmp= strtok(NULL," ");
            datatype.push_back(tmp);
        }
    }
}

void FilesProcessing::readTableRecord(int keywordnum, int recordnum, vector<vector<string>> &table,
                                      vector<int> &poslist) {
    ifstream record("数据.txt",ios::in);
    if(!record.is_open())
        cout<<"数据文件读取出错!!"<<endl;
    else{
        char str[2560];
        poslist.push_back(0);
        for(int i=1;i<=recordnum;i++){
            poslist.push_back(i);
            record.getline(str,2560);
            char* tmp;
            tmp = strtok(str," ");
            for(int j=0;j<keywordnum;j++){
                table[j].push_back(tmp);
                tmp =strtok(NULL," ");
            }
        }
    }
}

void FilesProcessing::readTableIndexes() {

}