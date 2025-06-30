#include "Betatron.h"
#include <cstring>

int main(int argc, char *argv[]) {
    Betatron b;
    b.read_program();
    b.run_program();
    return 0;
}
