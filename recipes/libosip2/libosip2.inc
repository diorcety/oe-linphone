DESCRIPTION = "oSIP is an implementation of SIP."
LICENSE = "GPLV2"

RECIPE_TYPES = "machine native"

DEPENDS = ""
DEPENDS:>HOST_KERNEL_linux = " libpthread"

inherit autotools pkgconfig library

require conf/fetch/gnu.conf
SRC_URI = "${GNU_MIRROR}/osip/${PN}-${PV}.tar.gz"

CFLAGS:>HOST_LIBC_mingw = " -DWIN32_USE_CRYPTO"

DEPENDS_${PN} += "${DEPENDS}"
