/*************************************************************************
 *
 *  $RCSfile: sdocdist.hxx,v $
 *
 *  $Revision: 1.1.1.1 $
 *
 *  last change: $Author: np $ $Date: 2002-03-08 14:45:32 $
 *
 *  The Contents of this file are made available subject to the terms of
 *  either of the following licenses
 *
 *         - GNU Lesser General Public License Version 2.1
 *         - Sun Industry Standards Source License Version 1.1
 *
 *  Sun Microsystems Inc., October, 2000
 *
 *  GNU Lesser General Public License Version 2.1
 *  =============================================
 *  Copyright 2000 by Sun Microsystems, Inc.
 *  901 San Antonio Road, Palo Alto, CA 94303, USA
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License version 2.1, as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *  MA  02111-1307  USA
 *
 *
 *  Sun Industry Standards Source License Version 1.1
 *  =================================================
 *  The contents of this file are subject to the Sun Industry Standards
 *  Source License Version 1.1 (the "License"); You may not use this file
 *  except in compliance with the License. You may obtain a copy of the
 *  License at http://www.openoffice.org/license.html.
 *
 *  Software provided under this License is provided on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
 *  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
 *  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
 *  See the License for the specific provisions governing your rights and
 *  obligations concerning the Software.
 *
 *  The Initial Developer of the Original Code is: Sun Microsystems, Inc.
 *
 *  Copyright: 2000 by Sun Microsystems, Inc.
 *
 *  All Rights Reserved.
 *
 *  Contributor(s): _______________________________________
 *
 *
 ************************************************************************/

#ifndef ADC_CPP_SDOCDIST_HXX
#define ADC_CPP_SDOCDIST_HXX



// USED SERVICES
    // BASE CLASSES
#include "cxt2ary.hxx"
#include <ary/info/docstore.hxx>
    // COMPONENTS
    // PARAMETERS

namespace cpp
{

using ary::Documentation;

/** Implementation struct for cpp::ContextForAry.
*/

struct ContextForAry::S_DocuDistributor : public ary::info::DocuStore
{
  public:
                        S_DocuDistributor()     :   pCurRe(0) {}
                        ~S_DocuDistributor()    {}

    void                Reset()                 { pCurRe = 0; pLastStoredDocu = 0; }

    void                SetCurrentlyStoredRe(
                            ary::RepositoryEntity &
                                                io_rRe );
    void                Event_LineBreak();

  private:
    // Interface ary::info::DocuStore
    virtual void	 	do_Store2CurProject(
                            DYN Documentation &	let_drDocu );
    virtual void	 	do_Store2CurFile(
                            DYN Documentation &	let_drDocu );
    virtual void	 	do_Store2CurNamespace(
                            DYN Documentation &	let_drDocu );

    virtual void	 	do_Store2ConnectedDeclaration(
                            DYN Documentation &	let_drDocu );

    virtual void	 	do_Store2Glossary(
                            DYN Documentation &	let_drDocu,
                            const udmstri &	    i_sExplainedTerm );
    virtual void	 	do_Store2GlobalTexts(
                            DYN Documentation &	let_drDocu,
                            ary::info::GlobalTextId
                                                i_nId );
    // DATA
    ary::RepositoryEntity *
                        pCurRe;
    Dyn<Documentation>  pLastStoredDocu;
};


// IMPLEMENTATION

/*  The implementation is in header, though not all inline, because this file
    is included in cxt2ary.cxx only!
*/


void
ContextForAry::
S_DocuDistributor::SetCurrentlyStoredRe( ary::RepositoryEntity & io_rRe )
{
    pCurRe = &io_rRe;
    if ( pLastStoredDocu )
        pCurRe->Add_Documentation( *pLastStoredDocu.Release() );
}

inline void
ContextForAry::
S_DocuDistributor::Event_LineBreak()
{
    pCurRe = 0;
}

void
ContextForAry::
S_DocuDistributor::do_Store2CurProject( DYN Documentation &	let_drDocu )
{
    // KORR_FUTURE
    delete &let_drDocu;
}

void
ContextForAry::
S_DocuDistributor::do_Store2CurFile( DYN Documentation &	let_drDocu )
{
    // KORR_FUTURE
    delete &let_drDocu;
}

void
ContextForAry::
S_DocuDistributor::do_Store2CurNamespace( DYN Documentation &	let_drDocu )
{
    // KORR_FUTURE
    delete &let_drDocu;
}

void
ContextForAry::
S_DocuDistributor::do_Store2ConnectedDeclaration( DYN Documentation & let_drDocu )
{
    if ( pCurRe != 0 )
        pCurRe->Add_Documentation(let_drDocu);
    else
        pLastStoredDocu = &let_drDocu;
}

void
ContextForAry::
S_DocuDistributor::do_Store2Glossary( DYN Documentation &	let_drDocu,
                                      const udmstri &	    // i_sExplainedTerm
                                      )
{
    // KORR_FUTURE
    delete &let_drDocu;
}

void
ContextForAry::
S_DocuDistributor::do_Store2GlobalTexts( DYN Documentation &	let_drDocu,
                                      ary::info::GlobalTextId // i_nId
                                         )
{
    // KORR_FUTURE
    delete &let_drDocu;
}




}   // namespace cpp


#endif

