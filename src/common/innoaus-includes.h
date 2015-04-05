#ifndef __innoaus_includes_h__
#define __innoaus_includes_h__

#define INNOAUS_INLINE  inline

#include <common/innoaus-namespaces.h>
#include <common/innoaus-ace-includes.h>
#include <common/innoaus-ace-stopwatch.h>

#include <common/innoaus-ice-includes.h>

#if defined(INNOAUS_USE_ZMQ)
#   include <libinnoaus/innoaus-zeromq-includes.h>
#endif

#include <common/innoaus-string-utils.h>

#endif /* __innoaus_includes_h__ */
