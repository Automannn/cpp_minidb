#include "lexical/lexical_analysis.h"
#include "file/files_processing.h"
#include "core/core_processing.h"

int main() {
    string cmd;
    CoreProcessing cp;

    while (getline(cin,cmd)){
        cp.analysis(cmd);
    }

    return 0;
}
