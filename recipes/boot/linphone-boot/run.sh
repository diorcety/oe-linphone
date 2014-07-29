#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
DIR="$( dirname "$SOURCE" )"
while [ -h "$SOURCE" ]
do 
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
  DIR="$( cd -P "$( dirname "$SOURCE"  )" && pwd )"
done
DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

echo "Root $DIR"
unset ROOTFS
ROOTFS=$DIR

cat > $ROOTFS/.pangorc <<EOF 
[Pango]
ModulesPath=$ROOTFS/lib/pango/1.6.0/modules
ModuleFiles=$ROOTFS/lib/pango/1.6.0/modules.cache
EOF

if [ ! -d $ROOTFS/share/themes/Outcrop ]; then
	pushd $ROOTFS/share/themes/ > /dev/null
	echo "Downloading theme"
	wget http://ftp.gnome.org/Public/GNOME/teams/art.gnome.org/themes/gtk2/GTK2-Outcrop.tar.gz > /dev/null 2> /dev/null
	echo "Installing theme"
	tar zxf GTK2-Outcrop.tar.gz
	rm GTK2-Outcrop.tar.gz
	popd > /dev/null
fi

# get USER, HOME and DISPLAY and then completely clear environment
U=$USER
H=$HOME
D=$DISPLAY
P=$PWD
PA=$PATH

for i in $(env | awk -F"=" '{print $1}') ; do
unset $i ; done

# set USER, HOME and DISPLAY and set minimal path.
export USER=$U
export HOME=$H
export DISPLAY=$D
export PWD=$P
export PATH=$PA

# Configure
if [ ! -f $ROOTFS/lib/pango/1.6.0/modules.cache ]; then
echo "Configure pango"
LD_LIBRARY_PATH="$ROOTFS/lib" PANGO_RC_FILE=$ROOTFS/.pangorc $ROOTFS/bin/pango-querymodules > $ROOTFS/lib/pango/1.6.0/modules.cache 
fi

if [ ! -f $ROOTFS/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache ]; then
echo "Configure gdk"
LD_LIBRARY_PATH="$ROOTFS/lib" GDK_PIXBUF_MODULEDIR=$ROOTFS/lib/gdk-pixbuf-2.0/2.10.0/loaders $ROOTFS/bin/gdk-pixbuf-query-loaders > $ROOTFS/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache
fi

if [ ! -f $ROOTFS/lib/gtk-2.0/2.10.0/immodules.cache ]; then
echo "Configure gtk"
LD_LIBRARY_PATH="$ROOTFS/lib" GTK_PATH=$ROOTFS/lib/gtk-2.0/ $ROOTFS/bin/gtk-query-immodules-2.0 > $ROOTFS/lib/gtk-2.0/2.10.0/immodules.cache
fi

# Run
echo "Run linphone"
LD_LIBRARY_PATH="$ROOTFS/lib" PANGO_RC_FILE=$ROOTFS/.pangorc \
	GDK_PIXBUF_MODULE_FILE=$ROOTFS/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache \
	GTK_IM_MODULE_FILE=$ROOTFS/lib/gtk-2.0/2.10.0/immodules.cache \
	GTK_EXE_PREFIX=$ROOTFS \
	GTK_DATA_PREFIX=$ROOTFS \
	GTK2_RC_FILES=$ROOTFS/share/themes/Outcrop/gtk-2.0/gtkrc \
	$ROOTFS/bin/linphone "$@"
