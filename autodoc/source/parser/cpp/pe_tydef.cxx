/*************************************************************************
 *
 *  $RCSfile: pe_tydef.cxx,v $
 *
 *  $Revision: 1.1.1.1 $
 *
 *  last change: $Author: np $ $Date: 2002-03-08 14:45:31 $
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

#include <precomp.h>
#include "pe_tydef.hxx"


// NOT FULLY DECLARED SERVICES
#include <ary/cpp/c_rwgate.hxx>
#include <ary/cpp/ca_type.hxx>
#include <all_toks.hxx>
#include "pe_type.hxx"


namespace cpp {


PE_Typedef::PE_Typedef(Cpp_PE * i_pParent )
    :   Cpp_PE(i_pParent),
        pStati( new PeStatusArray<PE_Typedef> ),
        // pSpType,
        // pSpuType,
        // sName
        nType(0)
{
    Setup_StatusFunctions();

    pSpType    = new SP_Type(*this);
    pSpuType   = new SPU_Type(*pSpType, 0, &PE_Typedef::SpReturn_Type);
}

PE_Typedef::~PE_Typedef()
{
}

void
PE_Typedef::Call_Handler( const cpp::Token & i_rTok )
{
    pStati->Cur().Call_Handler(i_rTok.TypeId(), i_rTok.Text());
}

void
PE_Typedef::Setup_StatusFunctions()
{
    typedef CallFunction<PE_Typedef>::F_Tok	F_Tok;
    static F_Tok stateF_start[] = 		{ On_start_typedef };
    static INT16 stateT_start[] = 		{ Tid_typedef };

    static F_Tok stateF_expectName[] =	{ On_expectName_Identifier };
    static INT16 stateT_expectName[] =  { Tid_Identifier };

    static F_Tok stateF_afterName[] = 	{ On_afterName_Semicolon };
    static INT16 stateT_afterName[] =   { Tid_Semicolon };

    SEMPARSE_CREATE_STATUS(PE_Typedef, start, Hdl_SyntaxError);
    SEMPARSE_CREATE_STATUS(PE_Typedef, expectName, Hdl_SyntaxError);
    SEMPARSE_CREATE_STATUS(PE_Typedef, afterName, Hdl_SyntaxError);
}

void
PE_Typedef::InitData()
{
    pStati->SetCur(start);

    sName.clear();
    nType = 0;
}

void
PE_Typedef::TransferData()
{
    pStati->SetCur(size_of_states);

    ary::cpp::Typedef &
    rTypedef = Env().AryGate().Store_Typedef(
                        Env().Context(), sName, nType );
    Env().Event_Store_Typedef(rTypedef);
}

void
PE_Typedef::Hdl_SyntaxError( const char * i_sText)
{
    StdHandlingOfSyntaxError(i_sText);
}

void
PE_Typedef::SpReturn_Type()
{
    pStati->SetCur(expectName);

    nType = pSpuType->Child().Result_Type().Id();
}

void
PE_Typedef::On_start_typedef( const char * )
{
    pSpuType->Push(done);
}

void
PE_Typedef::On_expectName_Identifier( const char * i_sText )
{
    SetTokenResult(done, stay);
    pStati->SetCur(afterName);

    sName = i_sText;
}

void
PE_Typedef::On_afterName_Semicolon( const char * )
{
    SetTokenResult(done, pop_success);
}

}   // namespace cpp



