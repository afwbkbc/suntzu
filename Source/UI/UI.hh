#ifndef UI_HH_
#define UI_HH_

#include <string>

/*
 *
 */
class UI {
public:
	UI();
	virtual ~UI();

	virtual void Log(std::string text)=0;
	virtual int FatalError(std::string text)=0;
};

#endif /* UI_HH_ */
