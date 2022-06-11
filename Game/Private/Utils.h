#pragma once
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>

// Print to output console
#define PRINT( s )							\
{											\
   std::ostringstream os_;					\
   os_ << s;								\
   OutputDebugString( os_.str().c_str() );  \
   OutputDebugStringW(L"\n");				\
}