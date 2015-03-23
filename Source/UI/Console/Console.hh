#ifndef CONSOLE_HH_
#define CONSOLE_HH_

#include "UI/UI.hh"

namespace ui {

/*
 *
 */
class Console : public UI {
public:
	Console();
	virtual ~Console();

	void Log(std::string text);
	int FatalError(std::string text);
};

} /* namespace ui */
#endif /* CONSOLE_HH_ */
