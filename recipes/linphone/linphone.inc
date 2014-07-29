DESCRIPTION = "Linphone is an internet phone or Voice Over IP phone (VoIP)."
LICENSE = "GPL"

RECIPE_TYPES = "machine native"

inherit autotools-autoreconf pkgconfig c c++ objc gettext

DEPENDS_LINPHONE_SAL = "belle-sip libxml2"
DEPENDS_LINPHONE_SAL_DEV = "belle-sip-dev libxml2-dev"
DEPENDS = "${DEPENDS_LINPHONE_SAL} libtheora speex-libspeex speex-libspeexdsp libavcodec ${DEPENDS_LIBVPX} ${DEPENDS_LIBOPUS} \
	   ${DEPENDS_CONSOLE} ${DEPENDS_V4L} ${DEPENDS_X11} ${DEPENDS_GTK} ${DEPENDS_ALSA} ${DEPENDS_SOUP} ${DEPENDS_SRTP} ${DEPENDS_ZRTP}"


RECIPE_FLAGS += "linphone_srtp linphone_console linphone_gtk linphone_assistant linphone_debug linphone_glx linphone_exosip linphone_libvpx linphone_libopus linphone_zrtp"
DEFAULT_USE_linphone_exosip = "0"
DEFAULT_USE_linphone_srtp = "1"
DEFAULT_USE_linphone_zrtp = "1"
DEFAULT_USE_linphone_gtk = "1"
DEFAULT_USE_linphone_assistant = "1"
DEFAULT_USE_linphone_debug = "0"
DEFAULT_USE_linphone_console = "1"
DEFAULT_USE_linphone_glx = "0"
DEFAULT_USE_linphone_libvpx = "1"
DEFAULT_USE_linphone_libopus = "1"

DEPENDS_SRTP = ""
DEPENDS_SRTP:USE_linphone_srtp = "libsrtp"
DEPENDS_SRTP_DEV = ""
DEPENDS_SRTP_DEV:USE_linphone_srtp = "libsrtp-dev"

DEPENDS_ZRTP = ""
DEPENDS_ZRTP:USE_linphone_zrtp = "libbzrtp"
DEPENDS_ZRTP_DEV = ""
DEPENDS_ZRTP_DEV:USE_linphone_zrtp = "libbzrtp-dev"

DEPENDS_ALSA = ""
DEPENDS_ALSA:HOST_KERNEL_linux = "libasound alsa-dev"
DEPENDS_ALSA_DEV = ""
DEPENDS_ALSA_DEV:HOST_KERNEL_linux = "libasound alsa-dev"

DEPENDS_X11 = ""
DEPENDS_X11:HOST_KERNEL_linux = "libx11 libxv libxrender"
DEPENDS_X11_DEV = ""
DEPENDS_X11_DEV:HOST_KERNEL_linux = "libx11-dev libxv-dev libxrender-dev"

DEPENDS_V4L = ""
DEPENDS_V4L:HOST_KERNEL_linux = "libv4l2 libv4l1"
DEPENDS_V4L_DEV = ""
DEPENDS_V4L_DEV:HOST_KERNEL_linux = "libv4l2-dev libv4l1-dev"

DEPENDS_CONSOLE = ""
DEPENDS_CONSOLE:USE_linphone_console = "libreadline readline-dev"
DEPENDS_CONSOLE_DEV = ""
DEPENDS_CONSOLE_DEV:USE_linphone_console = "readline-dev"

DEPENDS_GTK = ""
DEPENDS_GTK:USE_linphone_gtk = "gtk+ ${DEPENDS_GTK_MAC}"
DEPENDS_GTK_DEV = ""
DEPENDS_GTK_DEV:USE_linphone_gtk = "gtk+-dev ${DEPENDS_GTK_MAC_DEV}"

DEPENDS_SOUP = ""
DEPENDS_SOUP:USE_linphone_assistant = "libsoup"
DEPENDS_SOUP_DEV = ""
DEPENDS_SOUP_DEV:USE_linphone_assistant = "libsoup-dev"

DEPENDS_LIBOPUS = ""
DEPENDS_LIBOPUS:USE_linphone_libopus = "libopus"
DEPENDS_LIBOPUS_DEV = ""
DEPENDS_LIBOPUS_DEV:USE_linphone_libopus = "libopus-dev"

DEPENDS_LIBVPX = ""
DEPENDS_LIBVPX:USE_linphone_libvpx = "libvpx"
DEPENDS_LIBVPX_DEV = ""
DEPENDS_LIBVPX_DEV:USE_linphone_libvpx = "libvpx-dev"

DEPENDS_GTK_MAC = ""
DEPENDS_GTK_MAC:HOST_KERNEL_darwin = "gtk-mac-integration"
DEPENDS_GTK_MAC_DEV = ""
DEPENDS_GTK_MAC_DEV:HOST_KERNEL_darwin = "gtk-mac-integration-dev"

CFLAGS += " -D_GNU_SOURCE -D_ISOC99_SOURCE -Wno-error=unused-function"

EXTRA_OECONF += "${EXTRA_OECONF_CONSOLE} ${EXTRA_OECONF_GTK} ${EXTRA_OECONF_ASSISTANT} ${EXTRA_OECONF_DEBUG} ${EXTRA_OECONF_X11} ${EXTRA_OECONF_GLX} ${EXTRA_OECONF_ZRTP} --enable-relativeprefix --enable-broken-srtp --with-srtp=${STAGE_DIR}/machine${prefix} --disable-strict"
EXTRA_OECONF_GTK = "--enable-gtk_ui=no"
EXTRA_OECONF_GTK:USE_linphone_gtk = "--enable-gtk_ui=yes"
EXTRA_OECONF_ASSISTANT = "--enable-assistant=no"
EXTRA_OECONF_ASSISTANT:USE_linphone_assistant = "--enable-assistant=yes"
EXTRA_OECONF_DEBUG = "--enable-debug=no"
EXTRA_OECONF_DEBUG:USE_linphone_debug = "--enable-debug=yes"
EXTRA_OECONF_X11 = "--enable-x11=no --enable-xv=no"
EXTRA_OECONF_X11:HOST_KERNEL_linux = "--enable-x11=yes --enable-xv=yes"
EXTRA_OECONF_CONSOLE = "--enable-console_ui=no"
EXTRA_OECONF_CONSOLE:USE_linphone_console = "--enable-console_ui=yes"
EXTRA_OECONF_GLX = "--disable-glx"
EXTRA_OECONF_GLX:USE_linphone_glx = "--enable-glx"
EXTRA_OECONF_ZRTP = "--disable-zrtp"
EXTRA_OECONF_ZRTP:USE_linphone_zrtp = "--enable-zrtp"

RDEPENDS_${PN} += "${DEPENDS_CONSOLE} ${DEPENDS_SOUP} ${DEPENDS_GETTEXT} ${DEPENDS_GTK} ${PN}-liblinphone ${PN}-libmediastreamer ${PN}-libortp"
RDEPENDS_${PN}-dev += "${DEPENDS_CONSOLE_DEV} ${DEPENDS_SOUP_DEV} ${DEPENDS_GETTEXT_DEV} ${DEPENDS_GTK_DEV} ${PN}-liblinphone-dev ${PN}-libmediastreamer-dev ${PN}-libortp-dev"

FILES_${PN}-dev += "${datadir}/tutorials/linphone"
FILES_${PN}-locale += "${libdir}/locale"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "tools"
RDEPENDS_${PN}-tools += "${PN}-libxml2lpc ${PN}-liblp2xml"
FILES_${PN}-tools += "${bindir}/lpc2xml_test ${bindir}/xml2lpc_test"

inherit auto-package-libs
AUTO_PACKAGE_LIBS = "linphone mediastreamer ortp xml2lpc lpc2xml"
AUTO_PACKAGE_LIBS_DEV_DEPENDS = "${PN}-dev_${PV}"
RDEPENDS_${PN}-liblinphone += ""
RDEPENDS_${PN}-libortp += "${DEPENDS_LINPHONE_SAL} ${DEPENDS_SRTP} ${DEPENDS_ZRTP}"
RDEPENDS_${PN}-libortp-dev += "${DEPENDS_LINPHONE_SAL_DEV} ${DEPENDS_SRTP_DEV} ${DEPENDS_ZRTP_DEV}"
RDEPENDS_${PN}-libmediastreamer += "speex-libspeex speex-libspeexdsp libavcodec libtheora ${DEPENDS_LIBVPX} ${DEPENDS_LIBOPUS} ${DEPENDS_X11} ${DEPENDS_V4L} ${DEPENDS_ALSA}"
RDEPENDS_${PN}-libmediastreamer-dev += "speex-libspeex-dev speex-libspeexdsp-dev libavcodec-dev libtheora-dev ${DEPENDS_LIBVPX_DEV} ${DEPENDS_LIBOPUS_DEV} ${DEPENDS_X11_DEV} ${DEPENDS_V4L_DEV} ${DEPENDS_ALSA_DEV}"
FILES_${PN} += " ${datadir}/sounds ${datadir}/pixmaps ${datadir}/applications ${datadir}/images"
