/*
(c) 2018 tevador <tevador@gmail.com>

This file is part of RandomJS.

RandomJS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RandomJS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RandomJS.  If not, see<http://www.gnu.org/licenses/>.
*/

#pragma once

#include "Global.h"
#include "IVariable.h"
#include "VariableDeclaration.h"

class GlobalVariable : public Global, public IVariable {
public:
	static GlobalVariable CSUM;
	static GlobalVariable STRL;
	static GlobalVariable ESUM;

	static GlobalVariable MCYC;
	static GlobalVariable CYCL;
	static GlobalVariable MDPT;
	static GlobalVariable DPTH;

	virtual Global* clone() {
		return new GlobalVariable(getIndex(), Global::getName(), isConstant(), getInitializer());
	}

protected:
	GlobalVariable(uint32_t index, const char* name, bool constant = false, Expression* initializer = nullptr) : Global(index, name), IVariable(name, constant, initializer), declaration(this) {}

	void writeTo(std::ostream& os) const override {
		os << declaration;
	}

private:
	VariableDeclaration declaration;
};