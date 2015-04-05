#include "stdafx.h"
#include "IceServer.h"
#include "ITesterImpl.h"

IceServer::IceServer()
{
}


IceServer::~IceServer()
{
}

int IceServer::svc()
{
    Ice::InitializationData initData;
    initData.properties = CONF::instance()->properties();
    
    Ice::CommunicatorPtr comm = Ice::initialize(initData);
    Ice::ObjectAdapterPtr adapter = 0;
    try
    {
        int port = CONF::instance()->getServerPortByInt() + 1;
        std::string endpoint = icl_string::formatA("tcp -p %d", port);
        adapter = comm->createObjectAdapterWithEndpoints("ITesterAdapter", endpoint);
        adapter->add(new ITesterImpl, comm->stringToIdentity("ITester"));
        adapter->activate();
        comm->waitForShutdown();
    }
    catch (const Ice::Exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    try
    {
        comm->destroy();
    }
    catch (const Ice::Exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}

