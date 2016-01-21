#ifndef __defines_h__
#define __defines_h__

#include <QDebug>

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define MAKE_VERSION_STRING(major,minor) QString("%1.").arg(major) + QString("%1").arg(minor)

#define DEF_INI_NAME "./service.ini"

#ifdef WIN32
#pragma warning(disable:4100)
#pragma warning(disable:4996)
#endif

#endif /* __defines_h__ */
