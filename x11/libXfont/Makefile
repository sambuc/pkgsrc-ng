# $NetBSD: Makefile,v 1.35 2015/03/17 17:40:00 tnn Exp $

DISTNAME=		libXfont-1.5.1
CATEGORIES=		x11 devel fonts
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X font Library
LICENSE=		mit AND modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xfont.pc.in

CONFIGURE_ARGS+=	--disable-devel-docs

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/fontcacheproto/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontsproto+=	fontsproto>=2.1.3
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
