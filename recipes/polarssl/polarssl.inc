DESCRIPTION = "SSL/TLS library"
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

DEPENDS = ""

inherit autotools-autoreconf pkgconfig library

PACKAGES += "${PN}-utils"

DEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN} += "${DEPENDS}"
