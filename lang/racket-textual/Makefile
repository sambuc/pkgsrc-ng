# $NetBSD: Makefile,v 1.23 2015/08/05 21:14:29 asau Exp $

PKGNAME=	racket-minimal-6.2
DISTNAME=	$(PKGNAME_NOREV)-src
CATEGORIES=	lang
MASTER_SITES_PLT=	http://download.racket-lang.org/installers/$(PKGVERSION_NOREV)/ \
		http://www.eecs.northwestern.edu/racket/$(PKGVERSION_NOREV)/ \
		http://www.cs.utah.edu/plt/installers/$(PKGVERSION_NOREV)/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/$(PKGVERSION_NOREV)/ \
		ftp://infogroep.be/pub/racket/installers/$(PKGVERSION_NOREV)/ \
		http://russell.cs.bilgi.edu.tr/racket-installers/$(PKGVERSION_NOREV)/
MASTER_SITES=	$(MASTER_SITES_PLT)
EXTRACT_SUFX=	.tgz

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://racket-lang.org/
COMMENT=	Scheme-based dialect of Lisp
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	drscheme-[0-9]* mzscheme-[0-9]* racket-[0-9]*

PATCHDIR=	$(.CURDIR)/../../lang/racket/patches

WRKSRC=		$(WRKDIR)/racket-$(PKGVERSION_NOREV)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
CONFIGURE_ARGS=	--enable-pthread
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	no
UNLIMIT_RESOURCES=	datasize
OVERRIDE_DIRDEPTH=	3

LDFLAGS.DragonFly+=	-rdynamic

CHECK_INTERPRETER_SKIP=	lib/racket/collects/meta/build/sitemap/setup.py \
			lib/racket/collects/meta/build/sitemap/sitemap_gen.py \
			lib/racket/collects/meta/build/sitemap/test_sitemap_gen.py

CHECK_INTERPRETER_SKIP+=	lib/racket/collects/tests/jpr/mon-script.ss

.for f in use-c-printf.rkt use-crypt.rkt use-esd.rkt use-magick.rkt use-sndfile.rkt use-tcl.rkt use-xmmsctrl.rkt use-xosd.rkt
REPLACE_RACKET+=	collects/ffi/examples/${f}
.endfor

REPLACE_INTERPRETER+=	racket
REPLACE.racket.old=	.*racket
REPLACE.racket.new=	$(LOCALBASE)/bin/racket
REPLACE_FILES.racket=	$(REPLACE_RACKET)

post-install:
	$(RM) -f $(DESTDIR)$(PREFIX)/lib/racket/collects/racket/draw/unsafe/png.rkt.orig
	$(RM) -f $(DESTDIR)$(PREFIX)/lib/racket/collects/racket/draw/unsafe/jpeg.rkt.orig

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
