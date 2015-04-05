#include "stdafx.h"
#include "ClientBaseTask.h"


ClientBaseTask::ClientBaseTask()
{
    this->messageCount_ = 0;
    this->totalElapsedTimeForSending_ = 0;
    this->messageCountInOneSecond_ = 0;
    this->totalElapsedTimeForSendingInOneSecond_ = 0;
}


ClientBaseTask::~ClientBaseTask()
{
}

