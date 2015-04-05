#ifndef __perftest_ice__
#define __perftest_ice__

#include <Ice/BuiltinSequences.ice>

module perftest
{
	interface ITester
	{
		void o(Ice::ByteSeq data);
		void shutdown();
	};

}; /* perftest */

#endif /* __perftest_ice__ */