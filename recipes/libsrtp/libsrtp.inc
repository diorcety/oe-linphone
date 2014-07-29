DESCRIPTION = "The libSRTP library is an open-source implementation of the Secure Real-time Transport Protocol (SRTP)"
LICENSE = "BSD"

RECIPE_TYPES = "machine native"

DEPENDS = "libm"

inherit autotools pkgconfig library

EXTRA_OECONF += "--enable-pic"

DEPENDS_${PN} += "${DEPENDS}"
