AC_INIT([dbus_test01], [1.0])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AX_CXX_COMPILE_STDCXX_17
AC_PROG_CXX
AC_PROG_CC

PKG_CHECK_MODULES([GTEST], [gtest >= 1.10.0])

PKG_CHECK_MODULES([DBUS], [dbus-c++-1 >= 0.9.0])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 test/Makefile
])
AC_OUTPUT
