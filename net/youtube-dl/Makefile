# $NetBSD: Makefile,v 1.67 2015/09/12 20:14:39 wiz Exp $

VERSION_DATE=	2015.08.09
DISTNAME=	youtube-dl-${VERSION_DATE}
PKGNAME=	youtube-dl-${VERSION_DATE:S/.//S/.//}
CATEGORIES=	net
MASTER_SITES=	http://youtube-dl.org/downloads/${VERSION_DATE}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rg3.github.io/youtube-dl/
COMMENT=	Download videos from youtube.com
LICENSE=	public-domain

DEPENDS+=	mozilla-rootcerts-openssl-[0-9]*:../../security/mozilla-rootcerts-openssl

# Unfortunately at the moment upstream youtube-dl does not provide a changelog.
# When updating net/youtube-dl you can find a complete list of changes here:
#  https://github.com/rg3/youtube-dl/compare/${OLD_VERSION_DATE}...${NEW_VERSION_DATE}
# ...where OLD_VERSION_DATE is the previous VERSION_DATE and NEW_VERSION_DATE is
# the version you are going to commit.

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/youtube-dl
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX} MANDIR=${PREFIX}/${PKGMANDIR} \
		BASHCOMPDIR=${PREFIX}/share/bash-completion/completions \
		FISHCOMPDIR=${PREFIX}/share/fish/completions
INSTALLATION_DIRS=	share/youtube-dl
CHECK_INTERPRETER_SKIP=	share/youtube-dl/youtube-dl

post-patch:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/youtube-dl.sh
	${ECHO} 'exec ${PYTHONBIN} ${PREFIX}/share/youtube-dl/youtube-dl "$$@"' >> ${WRKSRC}/youtube-dl.sh

post-install:
	mv ${DESTDIR}${PREFIX}/bin/youtube-dl ${DESTDIR}${PREFIX}/share/youtube-dl
	${INSTALL_SCRIPT} ${WRKSRC}/youtube-dl.sh ${DESTDIR}${PREFIX}/bin/youtube-dl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
