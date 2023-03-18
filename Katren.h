#ifndef _katren_h_
#define _katren_h_
#include "Strofa.h"

class Katren : public Strofa
{
public:
	Katren() : Strofa(4) {}

	bool operator*() const override;
	char oznaka() const override;
};

#endif