#include "Layer1.h"
#include "Layer2.h"
using namespace std;
bool Layer1::process() {
    cout << "Layer 1 processing..." << endl;
    return true;
}

void Layer1::callNextLayer() {
    Layer2 layer2;
    if (process()) {
        layer2.process();
    }
}