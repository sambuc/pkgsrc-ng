# $NetBSD: Makefile,v 1.9 2015/04/11 08:51:05 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs24/:S/-/-nox11-/}

CONFLICTS+=	emacs24-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs24/files
PATCHDIR=	${.CURDIR}/../../editors/emacs24/patches
PKGDIR=		${.CURDIR}/../../editors/emacs24

.include "../../editors/emacs24/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf
CONFIGURE_ARGS+=	--without-rsvg --without-x --without-xft
CONFIGURE_ARGS+=	--without-gif --without-jpeg --without-png
CONFIGURE_ARGS+=	--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
