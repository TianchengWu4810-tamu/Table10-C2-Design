#include "Layer2.h"
#include "Layer3.h"
using namespace std;

bool Layer2::process() {
    cout << "Layer 2 processing..." << endl;
    
    FilePatcher patcher("path_to_original_file");
    patcher.patchFile("path_to_original_file");
    if(patcher.verifyPatched("path_to_original_file")) {
        cout << "File is patched correctly!" << endl;
        callNextLayer();
        return true;
    } else {
        cout << "File is not patched or was tampered with!" << endl;
        return false;
    }
}

void Layer2::callNextLayer() {
    Layer3 layer3;
    layer3.process();
}
