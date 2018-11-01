#include "Header.h"

int main(int argc, char* argv[]) {
	Parse* parse = new Parse(argv[1]);
	PlayGame* pg = new PlayGame(parse);
	return EXIT_SUCCESS;
}