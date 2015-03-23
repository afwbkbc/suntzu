#ifndef SUNTZU_HH_
#define SUNTZU_HH_

#include "Utils/ArgumentParser.hh"
#include "UI/UI.hh"

/*
 * Eternity lies ahead of us, and behind. Have you drunk your fill?
 */
class SunTzu {
public:
	SunTzu(int argc, char *argv[]);
	virtual ~SunTzu();

	int Run();

private:

	utils::ArgumentParser *mArgumentParser;
	UI *mUI;

};

#endif /* SUNTZU_HH_ */
