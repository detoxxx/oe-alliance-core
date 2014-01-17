# We know about rtc
include conf/machine/include/build-extras.inc

MACHINE_OEM = "dags"

MACHINE_NAME = "\
${@base_contains('MACHINEBUILD', 'tmt2', '2T-OE' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnano', 'Nano-OE' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnanot2', 'Nano 2T' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmsingle', 'Single' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmtwin', 'Twin-OE' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios100hd', 'IOS 100HD' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios200hd', 'IOS 200HD' , '', d)}\
${@base_contains('MACHINEBUILD', 'roxxs200hd', 'Roxxs 200HD' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediaart200hd', 'MediaArt 200HD' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios300hd', 'IOS 300HD' , '', d)}\
${@base_contains('MACHINEBUILD', 'force1', 'Force 1' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1plus', 'Optimuss OS1 Plus' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2plus', 'Optimuss OS2 Plus' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1', 'Optimuss OS1' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2', 'Optimuss OS2' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediabox', 'MediaBox HD LX' , '', d)}\
"


MACHINE_BRAND = "\
${@base_contains('MACHINEBUILD', 'tmt2', 'Technomate' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnano', 'Technomate' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnanot2', 'Technomate' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmsingle', 'Technomate' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmtwin', 'Technomate' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios100hd', 'iQON' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios200hd', 'iQON' , '', d)}\
${@base_contains('MACHINEBUILD', 'roxxs200hd', 'Roxxs' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediaart200hd', 'MediaArt' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios300hd', 'iQON' , '', d)}\
${@base_contains('MACHINEBUILD', 'force1', 'iQON' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1plus', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2plus', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediabox', 'Jepssen' , '', d)}\
"

IMAGEDIR ?= "\
${@base_contains('MACHINEBUILD', 'tmt2', 'update/tm2toe/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnano', 'update/tmnanooe/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmnanot2', 'update/tmnano2t/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmsingle', 'update/tmsingle/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'tmtwin', 'update/tmtwinoe/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios100hd', 'update/ios100/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios200hd', 'update/ios200/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'roxxs200hd', 'update/ios200/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediaart200hd', 'update/ios200/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'iqonios300hd', 'update/ios300/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'force1', 'update/force1/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1plus', 'update/force1/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2plus', 'update/force1/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos1', 'update/optimussos1/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'optimussos2', 'update/optimussos2/cfe' , '', d)}\
${@base_contains('MACHINEBUILD', 'mediabox', 'update/mediabox/cfe' , '', d)}\
"

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
    kernel-module-cdfs \
    "

MACHINE_EXTRA_RRECOMMENDS = " \
    vuplus-shutdown \
    gst-plugin-dvbmediasink \
    "

include conf/machine/include/autoload-filesystems.inc

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

GLIBC_EXTRA_OECONF = "--with-tls"
DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts"

PREFERRED_PROVIDER_virtual/kernel = "linux-dags"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "vuplus-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "vuplus-blindscan-utils"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096 -F"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGE_CMD_ubi_prepend = " \
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

IMAGE_CMD_ubi_append = " \
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    cp ${DEPLOY_DIR_IMAGE}/splash.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/splash.bmp; \
    mv ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/oe_rootfs.bin; \
    gzip -f -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/oe_kernel.bin; \
    echo ${DISTRO_NAME}-${DISTRO_VERSION}.${BUILD_VERSION} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
    rm -Rf update; \
    "

TARGET_FPU = "hard"

MACHINE_FEATURES += "3dtv alsa hdmicec switchoff wifi bootsplash textlcd fan ci"

BOOTLOGO_FILENAME = "splash.bmp"

require conf/machine/include/tune-mips32.inc