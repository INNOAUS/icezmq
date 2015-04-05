#include "stdafx.h"
#include "Configuration.h"


Configuration::Configuration()
{
    this->properties_ = 0;
}


Configuration::~Configuration()
{
}

void Configuration::init(int argc, ACE_TCHAR* argv[])
{
    Ice::StringSeq args = Ice::argsToStringSeq(argc, argv);
    this->properties_ = Ice::createProperties(args);
    this->properties_->parseCommandLineOptions("", args);
}