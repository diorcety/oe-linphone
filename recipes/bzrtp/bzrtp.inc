DESCRIPTION = "ZRTP from Belledonne Communications"
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

DEPENDS = "polarssl"

inherit autotools-autoreconf pkgconfig library c

EXTRA_OECONF += "--with-polarssl=${STAGE_DIR}/machine${prefix}"

DEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN}-dev += "polarssl-dev"
