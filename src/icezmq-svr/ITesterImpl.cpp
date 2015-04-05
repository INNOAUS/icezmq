#include "stdafx.h"
#include "ITesterImpl.h"
#include "IceServer.h"

ITesterImpl::ITesterImpl()
{
}


ITesterImpl::~ITesterImpl()
{
}

bool ITesterImpl::ice_invoke(const std::vector<Ice::Byte>& inParams, std::vector<Ice::Byte>& outParams, const Ice::Current& curr /* = Ice::Current() */)
{
    Ice::CommunicatorPtr communicator = curr.adapter->getCommunicator();

    Ice::InputStreamPtr in = Ice::createInputStream(communicator, inParams);
    in->startEncapsulation();
    if (curr.operation == "o")
    {
        Ice::ByteSeq message;
        icl_utils::STOPWATCH_TIMER::instance()->start();
        in->read(message);
        icl_utils::STOPWATCH_TIMER::instance()->stop();
        ICE_SERVER::instance()->totalElapsedTimeForReceiving_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();
        ICE_SERVER::instance()->messageCount_++;
        in->endEncapsulation();
        return true;
    }
    else if (curr.operation == "shutdown")
    {
        communicator->shutdown();
        return true;
    }

    return false;
}