# $NetBSD: Makefile,v 1.30 2015/09/01 13:16:48 sevan Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
PKGREVISION=	1
COMMENT=	Tools for providing messages in different languages

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

USE_LANGUAGES=		c c++
USE_TOOLS+=		xz:run
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--with-included-libcroco
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--with-xz
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--without-emacs
CONFIGURE_ARGS+=	--disable-openmp
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
LDFLAGS.AIX+=		-Wl,-brtl

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Cygwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,--disable-auto-import
.endif

.if ${OPSYS} == "AIX"
#bug 20453 in bug-gzip list, passed onto gnulib
CONFIGURE_ENV+= ac_cv_header_wctype_h=no
.endif

post-install:
	cd ${WRKSRC}/gettext-tools/misc && ${MAKE} install DESTDIR=${DESTDIR}
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/autopoint.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/gettextize.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
