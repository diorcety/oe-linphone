DESCRIPTION = "oSIP is an implementation of SIP."
LICENSE = "GPLV2"

RECIPE_TYPES = "machine native"

DEPENDS = "libosip2 libssl libcrypto"
DEPENDS:>HOST_KERNEL_linux = " libresolv"

inherit autotools pkgconfig library

SRC_URI = "http://download.savannah.gnu.org/releases/exosip/${PN}-${PV}.tar.gz"

EXTRA_OECONF += "--enable-openssl"

CFLAGS:>HOST_LIBC_mingw = " -D_WIN32_WCE -D_WIN32_WINNT=0x0501 -lws2_32 -ldnsapi -liphlpapi -lcrypt32"

PACKAGES += "${PN}-utils"

DEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN}-dev += "libosip2-dev libssl-dev libcrypto-dev"

FILES_${PN}-utils += "${bindir}/sip_reg*"
