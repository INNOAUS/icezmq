#include "stdafx.h"
#include "ZmqClient.h"


ZmqClient::ZmqClient()
{
}


ZmqClient::~ZmqClient()
{
}

int ZmqClient::svc()
{
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) START ZMQ CLIENT\n")));
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);

    std::string endpoint = icl_string::formatA("tcp://%s:%d", CONF::instance()->getServerAddress().c_str(), CONF::instance()->getServerPort());
    socket.connect(endpoint.c_str());

    Ice::ByteSeq data;
    for (int i = 0; i < CONF::instance()->getPayloadSize(); i++)
    {
        data.push_back('a');
    }

    zmq::message_t request(CONF::instance()->getPayloadSize());
    memcpy((void*)request.data(), data.data(), CONF::instance()->getPayloadSize());
    zmq::message_t reply;

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr < CONF::instance()->getLoopCount(); request_nbr++) 
    {
        icl_utils::STOPWATCH_TIMER::instance()->start();
        socket.send(request);
        socket.recv(&reply);

        icl_utils::STOPWATCH_TIMER::instance()->stop();
        this->messageCount_++;
        if (this->totalElapsedTimeForSendingInOneSecond_.value() <= 1000000)
        {
            this->messageCountInOneSecond_++;
            this->totalElapsedTimeForSendingInOneSecond_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();
        }
        this->totalElapsedTimeForSending_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();
    
    }
    memcpy((void*)request.data(), "T\0", 2);
    socket.send(request);

    socket.close();
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe number of sent messages : %d\n"), this->messageCount_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe total elapsed time for sending : %d ms.\n"), this->totalElapsedTimeForSending_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe number of sent messages (1Sec): %d\n"), this->messageCountInOneSecond_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) \tThe total elapsed time for sending (1Sec): %d ms.\n"), this->totalElapsedTimeForSendingInOneSecond_.value()));
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) END ZMQ CLIENT\n\n")));
    return 0;
}