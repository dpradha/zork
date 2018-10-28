#include "Room.h"
#include <stdlib.h>
#include "Parse.h"

using namespace std;

int main(int argc, char* argv[]) {
	Parse* parse = new Parse(argv[1]);

for (const auto &p : parse->items) {
    std::cout << "m[" << p.first << "] = " << p.second << '\n';
}
	return EXIT_SUCCESS;
}