DESCRIPTION = "Linphone version of antlr3"
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

DEPENDS = ""

S = "${SRCDIR}/antlr3"
B = "${SRCDIR}/antlr3/runtime/C"
CONFIGURE_SCRIPT = "${B}/configure"

inherit autotools-autoreconf pkgconfig library c

EXTRA_OECONF:>TARGET_CPU_x86_64 = " --enable-64bit"

DEPENDS_${PN} += "${DEPENDS}"
RDEPENDS_${PN} += "${DEPENDS}"
