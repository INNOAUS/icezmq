//
//  main.cpp
//  libtest
//
//  Created by Leo An on 4/3/15.
//  Copyright (c) 2015 Leo An. All rights reserved.
//

#include "stdafx.h"
#include "ZmqClient.h"
#include "IceClient.h"


int ACE_TMAIN(int argc, ACE_TCHAR* argv[])
{
    CONF::instance()->init(argc, argv);

    if (CONF::instance()->isZmqTest())
    {
        ZMQCLIENT::instance()->start();
    }
    else
    {
        ICECLIENT::instance()->start();
    }

    ACE_Thread_Manager::instance()->wait();
    return 0;
}

