# $NetBSD: Makefile,v 1.45 2015/04/25 14:20:47 tnn Exp $

STELLA_VERSION=	3.9.2
DISTNAME=	stella-${STELLA_VERSION}-src
PKGNAME=	stella-${STELLA_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stella/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stella.sourceforge.net/
COMMENT=	Multi-platform Atari 2600 VCS emulator
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
