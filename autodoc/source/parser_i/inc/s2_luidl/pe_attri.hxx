/*************************************************************************
 *
 *  $RCSfile: pe_attri.hxx,v $
 *
 *  $Revision: 1.3 $
 *
 *  last change: $Author: np $ $Date: 2002-11-01 17:15:46 $
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

#ifndef ADC_UIDL_PE_ATTRI_HXX
#define ADC_UIDL_PE_ATTRI_HXX



// USED SERVICES
    // BASE CLASSES

#include <s2_luidl/parsenv2.hxx>
#include <s2_luidl/pestate.hxx>
    // COMPONENTS
    // PARAMETERS
#include <ary/idl/i_gate.hxx>
#include <ary/idl/i_property.hxx>


namespace ary
{
     namespace idl
    {
         class Service;
    }
}

namespace csi
{
namespace uidl
{


class PE_Variable;

class PE_Attribute : public UnoIDL_PE,
                     public ParseEnvState
{
  public:
    typedef ary::idl::Ce_id                     Ce_id;
    typedef ary::idl::Type_id                   Type_id;
    typedef ary::idl::Property::Stereotypes     Stereotypes;
       
    enum E_ParsedType
    {
        parse_attribute,
        parse_property
    };
    
       
                        PE_Attribute(
                            Ce_id &             i_rCurOwner,
                            E_ParsedType        i_eCeType );

    virtual void	 	EstablishContacts(
                            UnoIDL_PE *			io_pParentPE,
                            ary::n22::Repository &
                                                io_rRepository,
                            TokenProcessing_Result &
                                                o_rResult );
    virtual				~PE_Attribute();

    virtual void	  	ProcessToken(
                            const Token &		i_rToken );

    virtual void		Process_Stereotype(
                            const TokStereotype &
                                                i_rToken );
    virtual void		Process_MetaType(
                            const TokMetaType &	i_rToken );
    virtual void		Process_Punctuation(
                            const TokPunctuation &
                                                i_rToken );
    virtual void		Process_Default();

    void				PresetOptional()		{ bIsOptional = true; }
    void				PresetStereotypes(
                            Stereotypes::E_Flags
                                                i_eFlag )
                                                { aStereotypes.Set_Flag(i_eFlag); }
  private:
    enum E_State
    {
        e_none,
        e_start,
        expect_variable,
        in_variable
    };

    virtual void		InitData();
    virtual void		ReceiveData();
    virtual void		TransferData();
    virtual UnoIDL_PE &	MyPE();

    // DATA
    E_State             eState;
    Ce_id *             pCurOwner;

    Dyn<PE_Variable>	pPE_Variable;

        // object-data
    Type_id	            nCurParsedType;
    String 			    sCurParsedName;
    bool				bIsOptional;
    Stereotypes         aStereotypes;
    E_ParsedType        eCeType;
};


}   // namespace uidl
}   // namespace csi


#endif

