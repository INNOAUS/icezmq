#ifndef __stdafx_h__
#define __stdafx_h__

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifdef WIN32
#pragma once

#include "targetver.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <tchar.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>
#endif // WIN32



// TODO: reference additional headers your program requires here

#define INNOAUS_USE_ZMQ
#include <common/innoaus-includes.h>

#include "Configuration.h"

#endif /* __stdafx_h__ */


