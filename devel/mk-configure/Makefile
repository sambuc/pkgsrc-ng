# $NetBSD: Makefile,v 1.19 2014/11/30 16:26:58 cheusov Exp $
#

DISTNAME=	mk-configure-0.29.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=	modified-bsd

DEPENDS+=	bmake-[0-9]*:../../devel/bmake

USE_LANGUAGES=		c

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

MAKE_PROGRAM=		${PREFIX}/bin/bmake

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR} \
			BMAKE=${PREFIX}/bin/bmake
MAKE_FLAGS=		PROG.awk=${AWK:Q}

AUTO_MKDIRS=		yes

EGDIR=			share/examples/mk-configure

TEST_TARGET=		test

post-install:
	cp -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}
	cp ${WRKSRC}/presentation/*.pdf ${DESTDIR}${PREFIX}/share/doc/mk-configure

.include "../../mk/bsd.prefs.mk"

CHECK_PERMS_SKIP=	*/foobar.in */hello_world3.in */prog1.awk.in
.if ${OPSYS} == "NetBSD" && ${OS_VARIANT} == Minix
MAKE_ENV+=		OPSYS=Minix MANGRP=operator BINGRP=operator
.endif

.if ${OPSYS} == SunOS && exists(/usr/xpg4/bin/awk)
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/usr/bin/awk
REPLACE.awk.new=	/usr/xpg4/bin/awk
REPLACE_FILES.awk=	mkc_check_version
.endif

.if ${OPSYS} != NetBSD && ${OPSYS} != FreeBSD && ${OPSYS} != OpenBSD && ${OPSYS} != DragonFly && ${OPSYS} != MirBSD
DEPENDS+=	bmkdep-[0-9]*:../../devel/bmkdep
.endif

.include "../../mk/bsd.pkg.mk"
