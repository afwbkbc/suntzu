#ifndef ARGUMENTPARSER_HH_
#define ARGUMENTPARSER_HH_

#include <string>

namespace utils {

class ArgumentParser {
public:
	ArgumentParser(int argc, char *argv[]);
	virtual ~ArgumentParser();

	enum ARG {
		LOCAL,
		SEARCH,
		HOST,

		_MAX,
	};
	bool getBool(ARG argid);
	std::string getString(ARG argid);

private:
	enum TYPE {
		BOOL,
		STRING,
	};
	struct ArgMap {
		ARG id;
		TYPE type;
		std::string key;
		std::string name;
		std::string description;
		bool mandatory;
		void *value;
	} mArguments[ARG::_MAX] = {
		{ ARG::LOCAL, TYPE::BOOL, "local", "", "Search game on localhost", true, new bool(true) },
		{ ARG::SEARCH, TYPE::STRING, "search", "IP Address", "IP Address to search game on", true, new std::string("127.0.0.1") },
		{ ARG::HOST, TYPE::BOOL, "host", "", "Host the game", true, new bool(false) },
	};
};

} /* namespace utils */
#endif /* ARGUMENTPARSER_HH_ */
