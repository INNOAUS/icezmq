#include "stdafx.h"
#include "IceClient.h"
#include "PerfTest.h"

IceClient::IceClient()
{
}


IceClient::~IceClient()
{
}

int IceClient::svc()
{
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) START ICE CLIENT\n")));

    Ice::InitializationData initData;
    initData.properties = Ice::createProperties();
    std::string endpoint = icl_string::formatA("ITester:tcp -h %s -p %d", CONF::instance()->getServerAddress().c_str(), CONF::instance()->getServerPort() + 1);
    initData.properties->setProperty("ITester.Proxy", endpoint);
    Ice::CommunicatorPtr comm = Ice::initialize(initData);

    Ice::ByteSeq data;
    for (int i = 0; i < CONF::instance()->getPayloadSize(); i++)
    {
        data.push_back('a');
    }

    try
    {
        Ice::ObjectPrx prx = comm->propertyToProxy("ITester.Proxy");

        Ice::OutputStreamPtr out = Ice::createOutputStream(comm);
        Ice::ByteSeq inParams, outParams;
        out->startEncapsulation();
        out->write(data);
        out->endEncapsulation();
        out->finished(inParams);

        for (int i = 0; i < CONF::instance()->getLoopCount(); i++)
        {
            icl_utils::STOPWATCH_TIMER::instance()->start();
            if (!prx->ice_invoke("o", Ice::Normal, inParams, outParams))
            {
                std::cout << "Unknown user exception" << std::endl;
            }
            icl_utils::STOPWATCH_TIMER::instance()->stop();
            this->messageCount_++;
            if (this->totalElapsedTimeForSendingInOneSecond_.value() <= 1000000)
            {
                this->messageCountInOneSecond_++;
                this->totalElapsedTimeForSendingInOneSecond_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();
            }
            this->totalElapsedTimeForSending_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();
        }
        {
            Ice::OutputStreamPtr out = Ice::createOutputStream(comm);
            Ice::ByteSeq inParams, outParams;
            out->startEncapsulation();
            out->endEncapsulation();
            out->finished(inParams);
            if (!prx->ice_invoke("shutdown", Ice::Normal, inParams, outParams))
            {
                std::cout << "Unknown user exception" << std::endl;
            }
        }
    }
    catch (const Ice::Exception& ex)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) Exception occurred : %s\n"), ACE_TEXT_CHAR_TO_TCHAR(ex.what())));
        ACE_UNUSED_ARG(ex);
    }

    try
    {
        comm->destroy();
    }
    catch (const Ice::Exception& ex)
    {
    	ACE_UNUSED_ARG(ex);
    }

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tMessage Size : %d\n"), CONF::instance()->getPayloadSize()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe number of sent messages : %d\n"), this->messageCount_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe total elapsed time for sending : %d ms.\n"), this->totalElapsedTimeForSending_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe number of sent messages (1Sec): %d\n"), this->messageCountInOneSecond_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe total elapsed time for sending (1Sec): %d ms.\n"), this->totalElapsedTimeForSendingInOneSecond_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) END ICE CLIENT\n\n")));

    return 0;
}
