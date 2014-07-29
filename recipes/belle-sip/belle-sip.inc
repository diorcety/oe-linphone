DESCRIPTION = "SIP stack from Belledonne Communications"
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

inherit autotools-autoreconf pkgconfig library c

DEPENDS = "polarssl antlr3c libm"
DEPENDS:>HOST_KERNEL_linux = " libpthread"
DEPENDS:>HOST_KERNEL_darwin = " libpthread"

RECIPE_FLAGS += "bellesip_debug"

DEFAULT_USE_bellesip_debug = "0"

EXTRA_OECONF += "--with-antlr=${STAGE_DIR}/machine${prefix} --with-polarssl=${STAGE_DIR}/machine${prefix} ${EXTRA_OECONF_DEBUG}"
EXTRA_OECONF_DEBUG = "--enable-debug=no"
EXTRA_OECONF_DEBUG:USE_bellesip_debug = "--enable-debug=yes"

CFLAGS += " -D_GNU_SOURCE"

DEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN}-dev += "polarssl-dev antlr3c-dev"
