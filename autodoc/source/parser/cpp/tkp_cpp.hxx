/*************************************************************************
 *
 *  $RCSfile: tkp_cpp.hxx,v $
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

#ifndef ADC_TKP_CPP_HXX
#define ADC_TKP_CPP_HXX

// USED SERVICES
    // BASE CLASSES
#include <tokens/tkp.hxx>
    // COMPONENTS
    // PARAMETRS

namespace autodoc
{
    class TkpDocuContext;
}

namespace csv
{
    namespace ploc
    {
        class Path;
        class DirectoryChain;
    }
}


namespace cpp {

class Context_CppStd;
class DefineDescription;
class Distributor;


/** This is a TokenParser which is able to parse tokens from
    C++ source code.
*/
class TokenParser_Cpp : public TokenParser
{
  public:
    typedef std::map< udmstri, DefineDescription* >     MacroMap;

    // LIFECYCLE
                        TokenParser_Cpp(
                            DYN autodoc::TkpDocuContext &
                                                let_drDocuContext );
    virtual				~TokenParser_Cpp();

    // OPERATIONS
    void                AssignPartners(
                            CharacterSource &   io_rCharacterSource,
                            cpp::Distributor &  o_rDealer );
    void                StartNewFile(
                            const udmstri &     i_sFileName,
                            const csv::ploc::DirectoryChain &
                                                i_rFileSubPath );
  private:
    virtual void		SetStartContext();
    virtual void        SetCurrentContext(
                            TkpContext &		io_rContext );
    virtual TkpContext &
                        CurrentContext();
    // DATA
    Dyn<Context_CppStd>	pBaseContext;
    TkpContext *        pCurContext;
    Distributor *       pDealer;
    CharacterSource *   pCharacterSource;
};


}   // namespace cpp


#endif


