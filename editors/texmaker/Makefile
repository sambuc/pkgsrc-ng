# $NetBSD: Makefile,v 1.54 2015/07/15 15:09:38 wiz Exp $

DISTNAME=	texmaker-4.4.1
PKGREVISION=	7
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texmaker.pro DESKTOPDIR=${PREFIX}/share/applications ICONDIR=${PREFIX}/share/pixmaps

.include "options.mk"

.include "../../print/poppler-includes/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
