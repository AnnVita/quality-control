#include "stdafx.h"
#include "CTriangleHandleError.h"

CTriangleHandleError::CTriangleHandleError(const std::string & message)
	: std::invalid_argument(message)
{ };