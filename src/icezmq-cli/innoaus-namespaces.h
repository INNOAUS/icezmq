//
//  innoaus-namespaces.h
//  libinnoaus
//
//  Created by Leo An on 10/26/14.
//  Copyright (c) 2014 INNOAUS. All rights reserved.
//

#ifndef __libinnoaus_innoaus_namespaces_h__
#define __libinnoaus_innoaus_namespaces_h__

namespace innoaus {};

namespace innoaus { namespace common {} };
namespace ic            = innoaus::common;

namespace innoaus { namespace common { namespace lib {} } };
namespace innoaus { namespace common { namespace lib { namespace string {} } } };
namespace innoaus { namespace common { namespace lib { namespace utils {} } } };

namespace icl           = innoaus::common::lib;
namespace icl_string    = icl::string;
namespace icl_utils     = icl::utils;

#endif /* defined(__libinnoaus__innoaus_namespaces_h__) */
