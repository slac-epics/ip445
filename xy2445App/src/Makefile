# Makefile.Host
TOP = ../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
USR_CFLAGS += -DUSE_TYPED_RSET -DUSE_TYPED_DSET -DUSE_TYPED_DRVET
#=============================

HTMLS += xycomIpac.html

DBD += ip445.dbd
DBD += Xy2445.dbd

# Source files (for depends target):
LIBSRCS += drvXy2445.c
LIBSRCS += devXy2445.c
LIBSRCS += xipIo.c

# Link everything into a library:
LIBRARY_IOC_Linux   = Xy2445 ip445
LIBRARY_IOC_vxWorks = Xy2445 ip445
LIBRARY_IOC_RTEMS   = Xy2445 ip445
Xy2445_LIBS += Ipac

include $(TOP)/configure/RULES
