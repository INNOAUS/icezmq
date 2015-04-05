//
//  main.cpp
//  libtest
//
//  Created by Leo An on 4/3/15.
//  Copyright (c) 2015 Leo An. All rights reserved.
//

#include "stdafx.h"
#include "ZmqServer.h"
#include "IceServer.h"

int ACE_TMAIN(int argc, ACE_TCHAR* argv[])
{
    CONF::instance()->init(argc, argv);

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) BEGIN ICE & ZEROMQ SERVER TESTER OUTPUT\n")));

    if (CONF::instance()->isZmqTest())
    {
        ZMQ::instance()->start();
    }
    else
    {
        ICE_SERVER::instance()->start();
    }

    ACE_Thread_Manager::instance()->wait();

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) END ICE & ZEROMQ SERVER TESTER OUTPUT\n")));
    return 0;
}

