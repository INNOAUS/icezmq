top_srcdir  = ../..

SERVER      = icezmq-cli

TARGETS     = $(SERVER)

OBJS        = icezmq-cli.o \
              Configuration.o \
              ClientBaseTask.o \
              IceClient.o \
              ZmqClient.o \
              innoaus-ace-stopwatch.o \
              innoaus-string-utils.o


SRCS        = $(OBJS:.o=.cpp)
SLICE_SRCS  =

include $(top_srcdir)/config/Make.rules


CPPFLAGS    := -I. -I.. -I/usr/include -I/opt/local/include -I/usr/include/postgresql $(CPPFLAGS)
CPPFLAGS    := -DACE_AS_STATIC_LIBS $(CPPFLAGS)
#ifeq ($(OPTIMIZE), yes)
#    CPPFLAGS := -O3 $(CPPFLAGS)
#endif

LDFLAGS		:= -L$(top_srcdir)/lib -L/usr/lib -L/opt/local/lib -L/Library/Developer/Ice-3.5/lib/c++11 $(LDFLAGS)
LINKWITH    := -lzmq -lACE -lIce -lIceUtil -lGlacier2 -lIceStorm

$(SERVER): $(OBJS)
	rm -f $@
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(DB_RPATH_LINK) $(LIBS) $(LINKWITH)
	cp $@ $(top_srcdir)/bin
clean::


