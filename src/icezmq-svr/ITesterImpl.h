#ifndef __ITesterImpl_h__
#define __ITesterImpl_h__

#pragma once

#include "PerfTest.h"

class ITesterImpl : public Ice::Blobject
{
public:
    ITesterImpl();
    virtual ~ITesterImpl();

    virtual bool ice_invoke(const std::vector<Ice::Byte>& inParams, std::vector<Ice::Byte>& outParams, const Ice::Current& curr = Ice::Current());
};


#endif /* __ITesterImpl_h__ */

