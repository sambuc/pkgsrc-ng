# $NetBSD: Makefile,v 1.20 2015/06/12 10:49:42 wiz Exp $

DISTNAME=	SVN-Notify-2.84
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Notify/
COMMENT=	Perl module for mailing messages for Subversion repository activity
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/SVN/Notify/.packlist
PERL5_MODULE_TYPE=	Module::Build

# Recommended dependencies
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Net-SMTP_auth-[0-9]*:../../mail/p5-Net-SMTP_auth
DEPENDS+=	p5-Text-Trac-[0-9]*:../../textproc/p5-Text-Trac

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
