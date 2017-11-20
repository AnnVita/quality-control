#pragma once
#include "stdafx.h"

class CTriangleHandleError : public std::invalid_argument
{
public:
	CTriangleHandleError(const std::string & message);
private:
	std::string m_base;
};
