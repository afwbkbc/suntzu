#include "SunTzu.hh"

#include <iostream>

#include <cstdlib>

#include "UI/Console/Console.hh"

SunTzu::SunTzu(int argc, char *argv[]) {

	mArgumentParser = new utils::ArgumentParser(argc, argv);
	mUI = new ui::Console;

}

SunTzu::~SunTzu() {

	delete mUI;
	delete mArgumentParser;

}

int SunTzu::Run() {

	if (mArgumentParser->getBool(utils::ArgumentParser::ARG::HOST))
		return mUI->FatalError("Game hosting not supported yet.");

	std::string ip = mArgumentParser->getString(utils::ArgumentParser::ARG::SEARCH);
	std::cout << ip << std::endl;

	return EXIT_SUCCESS;
}
