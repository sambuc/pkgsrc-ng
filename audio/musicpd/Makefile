# $NetBSD: Makefile,v 1.109 2015/07/01 09:23:30 wiz Exp $

DISTNAME=		mpd-0.19.10
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
CATEGORIES=		audio
MASTER_SITES=		http://www.musicpd.org/download/mpd/0.19/
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player
LICENSE=		gnu-gpl-v2

CONFLICTS=		mpd-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

# See ${WRKSRC}/src/Compiler.h: mpd requires gcc>=4.6
GCC_REQD=		4.6

# MacOS X audio output is no longer enabled by default.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-osx
.endif

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
CONF_FILES=		${EGDIR}/mpd.conf ${PKG_SYSCONFDIR}/mpd.conf
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO:Q}
LDFLAGS+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	${EGDIR}

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
