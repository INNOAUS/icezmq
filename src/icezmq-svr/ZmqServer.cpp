#include "stdafx.h"
#include "ZmqServer.h"


int ZmqServer::svc()
{
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) START ZMQ\n")));

    //  Prepare our context and socket
    std::string endpoint = "tcp://*:" + CONF::instance()->getServerPort();
    this->socket_->bind(endpoint.c_str());

    while (true) {
        zmq::message_t request;
        icl_utils::STOPWATCH_TIMER::instance()->start();
        this->socket_->recv(&request);
        icl_utils::STOPWATCH_TIMER::instance()->stop();
        this->messageCount_++;
        this->totalElapsedTimeForReceiving_ += icl_utils::STOPWATCH_TIMER::instance()->getElapsedMicroseconds();

        //  Send reply back to client
        zmq::message_t reply(1);
        memcpy((void *)reply.data(), "W", 1);
        this->socket_->send(reply);
    }

    delete this->socket_;
    this->socket_ = 0;
    delete this->context_;
    this->context_ = 0;

    return 0;
}
