# $NetBSD: Makefile,v 1.17 2015/09/04 12:52:49 mef Exp $
#

DISTNAME=		Test-Memory-Cycle-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Memory-Cycle/
COMMENT=		Check for memory leaks and circular memory references

DEPENDS+=		p5-Devel-Cycle-[0-9]*:../../devel/p5-Devel-Cycle
# for make test
BUILD_DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Memory/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
