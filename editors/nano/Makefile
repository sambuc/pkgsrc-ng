# $NetBSD: Makefile,v 1.49 2015/08/18 07:31:06 wiz Exp $

DISTNAME=	nano-2.4.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v2.4/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	Small and friendly text editor (a free replacement for Pico)
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-color
CONFIGURE_ARGS+=	--enable-multibuffer
CONFIGURE_ARGS+=	--enable-nanorc
CONFIGURE_ARGS+=	--enable-extra

# Looks like that IRIX 5.x lacks vsnprintf() functions,
# which are required to make this work, so glib2 is used instead.
.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
.  include "../../devel/glib2/buildlink3.mk"
.endif

.include "options.mk"

INSTALLATION_DIRS+=	share/examples/nano
CONF_FILES+=		share/examples/nano/nanorc ${PKG_SYSCONFDIR}/nanorc

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/nanorc.sample ${DESTDIR}${PREFIX}/share/examples/nano/nanorc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
