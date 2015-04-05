#ifndef __innoaus_zeromq_includes_h__
#define __innoaus_zeromq_includes_h__


#include <libinnoaus/zmq.hpp>


#ifdef _MSC_VER
#   ifndef _DEBUG
#       pragma comment(lib, "libzmq.lib")
#   else
#       pragma comment(lib, "libzmqd.lib")
#   endif
#endif /* _MSC_VER */

#endif /* __innoaus_zeromq_includes_h__ */

