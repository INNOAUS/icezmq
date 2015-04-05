#include "stdafx.h"
#include "ServerBaseTask.h"


ServerBaseTask::ServerBaseTask()
{
    this->messageCount_ = 0;
    this->totalElapsedTimeForReceiving_ = 0;
}


ServerBaseTask::~ServerBaseTask()
{
}
