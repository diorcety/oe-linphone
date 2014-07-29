if not exist etc/ (
	md "etc/"
)
if not exist etc/pango/ (
	md "etc/pango/"
)
if not exist etc/pango/pango.modules (
	call "bin/pango-querymodules" > etc/pango/pango.modules
)
if not exist lib/gdk-pixbuf-2.0/2.10.0/loaders.cache (
	call "bin/gdk-pixbuf-query-loaders" > lib/gdk-pixbuf-2.0/2.10.0/loaders.cache
)
if not exist lib/gtk-2.0/2.10.0/immodules.cache (
	call "bin/gtk-query-immodules-2.0" > lib/gtk-2.0/2.10.0/immodules.cache
)
call "bin/linphone"
