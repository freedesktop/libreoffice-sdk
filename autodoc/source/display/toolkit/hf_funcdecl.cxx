/*************************************************************************
 *
 *  $RCSfile: hf_funcdecl.cxx,v $
 *
 *  $Revision: 1.1 $
 *
 *  last change: $Author: np $ $Date: 2002-11-01 17:15:23 $
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
#include <toolkit/hf_funcdecl.hxx>


// NOT FULLY DEFINED SERVICES
                                                                   
const String C_sValignTop("top");                                                                   
                     
 
HF_FunctionDeclaration::HF_FunctionDeclaration( Xml::Element & o_rParent )
    :   HtmlMaker(o_rParent),
        pFront(0),
        pTypes(0),
        pNames(0)
{                         
    Xml::Element &
        rRow = CurOut()
                >> *new Html::Table    
                    << new Xml::AnAttribute("border","0")
                    >> *new Html::TableRow;
    pFront = &(rRow >> *new Html::TableCell << new Html::VAlignAttr(C_sValignTop));
    pTypes = &(rRow >> *new Html::TableCell << new Html::VAlignAttr(C_sValignTop));
    pNames = &(rRow >> *new Html::TableCell << new Html::VAlignAttr(C_sValignTop));
}  

HF_FunctionDeclaration::~HF_FunctionDeclaration()
{
}   

Xml::Element &      
HF_FunctionDeclaration::Add_ReturnLine()
{
    (*pTypes) << new Xml::XmlCode("&nbsp;<br>\n");
    (*pNames) << new Xml::XmlCode("&nbsp;<br>\n");
    return *pFront;
}   

Xml::Element &      
HF_FunctionDeclaration::Add_RaisesLine( const char * i_sRaisesText,
                                        bool         i_bSuppressExtraLine )
{                                                                  
    if (NOT i_bSuppressExtraLine)
    {
        (*pTypes) << new Xml::XmlCode("&nbsp;<br>");
        (*pNames) << new Xml::XmlCode("&nbsp;<br>\n");
    }
    (*pTypes) 
        << new Xml::XmlCode("<p class=\"raise\">")
        << i_sRaisesText 
        << new Xml::XmlCode("( </p>\n");
    return *pNames;
}

 