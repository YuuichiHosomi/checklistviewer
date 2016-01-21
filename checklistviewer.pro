OPENSSL_LIB_PATH = $$(OPENSSLDIR)
isEmpty(OPENSSL_LIB_PATH) { 
   error(please specify $OPENSSLDIR environment in OS)
}

PROTOBUF_LIB_PATH = $$(PROTOBUFDIR)
isEmpty(PROTOBUF_LIB_PATH) { 
   error(please specify $PROTOBUFDIR environment in OS)
}

CONFIG += openssl

HEADERS  = defedit.h \
           defines.h \
           dlgconnect.h \
           dlglogininfo.h \
           dlgtasks.h \
           htmreport.h \
           inifile.h \
           jsonparser.h \
           protobuf.h \
           requesthandler.h \
           sslclient.h \
           webclient.h \
           pbs/message.pb.h \
           pbs/message_common.pb.h \
           pbs/message_type.pb.h \
           pbs/message_workgroup.pb.h 

SOURCES  = checklistviewer_plugin_import.cpp \
           defedit.cpp \
           dlgconnect.cpp \
           dlglogininfo.cpp \
           dlgtasks.cpp \
           htmreport.cpp \
           inifile.cpp \
           jsonparser.cpp \
           main.cpp \
           protobuf.cpp \
           sslclient.cpp \
           webclient.cpp \
           pbs/message.pb.cc \
           pbs/message_common.pb.cc \
           pbs/message_type.pb.cc \
           pbs/message_workgroup.pb.cc

QT      += network widgets

INCPATH += $${PROTOBUF_LIB_PATH}/src ./pbs

LIBS   += -L$${OPENSSL_LIB_PATH}/lib
unix:LIBS = -L$$/usr/lib64 $${LIBS} -lssl -lcrypto -lrt $${PROTOBUF_LIB_PATH}/src/.libs/libprotobuf.a
win32:LIBS   += $${PROTOBUF_LIB_PATH}/lib/libprotobuf.lib

# install
target.path = ../bin
INSTALLS += target
