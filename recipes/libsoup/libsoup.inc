DESCRIPTION = "libsoup is an HTTP client/server library for GNOME."
LICENSE = "LGPL-2.1"

RECIPE_TYPES = "machine native"

DEPENDS = "libm libxml2 libgobject libgthread libgio native:glib-utils"

inherit autotools-autoreconf library pkgconfig

EXTRA_OECONF += "--without-gnome"
EXTRA_OECONF += "--disable-tls-check" #TEMP

DEPENDS_${PN} += "${DEPENDS}"
FILES_${PN}-doc += "${datadir}/gtk-doc"
