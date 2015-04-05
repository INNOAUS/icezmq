//
//  innoaus-string-utils.cpp
//  libinnoaus
//
//  Created by Leo An on 10/26/14.
//  Copyright (c) 2014 INNOAUS. All rights reserved.
//

#include "stdafx.h"
#include "innoaus-string-utils.h"
#include <algorithm>

namespace innoaus {
namespace common {
namespace lib {
namespace string {

    std::string formatA(const char *fmt, ...)
    {
        va_list marker;
        va_start(marker ,fmt);
#ifdef _MSC_VER
        int nLen = _vscprintf(fmt, marker) + 10;
#else
        int nLen = 1024 * 1024;
#endif
        std::auto_ptr<char> data(new char[nLen]);
        char* pData = data.get();
#ifdef _MSC_VER
        vsprintf(pData, fmt, marker);
#else
        vsprintf(pData, fmt, marker);
#endif
        va_end(marker);
        
        std::string str = pData;
        return str;
    }
    

} /* string */
} /* lib */
} /* common */
} /* innoaus */

/* End of file */