/*************************************************************************
 *
 *  OpenOffice.org - a multi-platform office productivity suite
 *
 *  $RCSfile: html_kit.cxx,v $
 *
 *  $Revision: 1.9 $
 *
 *  last change: $Author: hr $ $Date: 2007-11-02 16:27:53 $
 *
 *  The Contents of this file are made available subject to
 *  the terms of GNU Lesser General Public License Version 2.1.
 *
 *
 *    GNU Lesser General Public License Version 2.1
 *    =============================================
 *    Copyright 2005 by Sun Microsystems, Inc.
 *    901 San Antonio Road, Palo Alto, CA 94303, USA
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License version 2.1, as published by the Free Software Foundation.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *    MA  02111-1307  USA
 *
 ************************************************************************/

#include <precomp.h>
#include "html_kit.hxx"


// NOT FULLY DEFINED SERVICES
#include <stdio.h>
#include <ary/cpp/c_slntry.hxx>
#include "hdimpl.hxx"


namespace adcdisp
{


using namespace csi::xml;
using namespace csi::html;


PageTitle_Central::PageTitle_Central( XmlElement & o_rOwner )
{
    pOut = new AnElement("h1");
    o_rOwner
        >> *pOut
            << new AlignAttr("center");
}


void
PageTitle_Left::operator()( XmlElement &        o_rOwner,
                            const char *        i_sTypeTitle,
                            const String &      i_sLocalName )
{
    o_rOwner
        >> *new Headline(2)
            << i_sTypeTitle
            << " "
            << i_sLocalName;
}

void
PageTitle_Std::operator()( XmlElement &         o_rOwner,
                           const char *         i_sTypeTitle,
                           const String &       i_sLocalName )
{
    o_rOwner
        >> *new AnElement("div")
            << new ClassAttr("title")
            >> *new Headline(2)
                << i_sTypeTitle
                << " "
                << i_sLocalName;
}

XmlElement &
PageTitle_Std::operator()( XmlElement & o_rOwner )
{
    XmlElement & ret =
        o_rOwner
            >> *new AnElement("div")
                << new ClassAttr("title")
                >> *new Headline(2);
    return ret;
}

void
OperationTitle::operator()( XmlElement &                o_owner,
                            const char *                i_itemName,
                            ary::cpp::Ce_id             i_id,
                            const ::ary::cpp::Gate &    i_gate )
{
    o_owner
        >> *new Label( OperationLabel(i_itemName, i_id, i_gate) )
            << " ";
    o_owner
        << i_itemName;
}


void
TemplateClause::operator()( XmlElement &           o_rOwner,
                            const List_TplParams & i_rTplParams )
{
    if ( i_rTplParams.size() == 0 )
        return;

    Element & rOut =
        o_rOwner
            << new LineBreak
            >> *new Paragraph
                >> *new Strong
                    << "template< ";

    List_TplParams::const_iterator
        it      = i_rTplParams.begin();
    List_TplParams::const_iterator
        itEnd   = i_rTplParams.end();

    rOut
        << (*it).Name();
    for ( ++it; it != itEnd; ++it )
    {
        rOut
            << ", "
            << (*it).Name();
    }  // end for
      rOut << " >";
}

ExplanationList::ExplanationList( XmlElement & o_rOwner,
                                  bool         i_bMemberStyle )
    :   pList( new DefList),
        pTerm(0),
        pDefinition(0),
        bMemberStyle(i_bMemberStyle)
{
    if (bMemberStyle)
        *pList << new ClassAttr("member");

    o_rOwner << pList;
}

void
ExplanationList::AddEntry( const char *        i_sTerm,
                           const char *        i_sDifferentClass )
{
    DefListTerm & rNewTerm = pList->AddTerm();
    if ( i_sDifferentClass != 0 )
    {
        rNewTerm << new ClassAttr(i_sDifferentClass);
    }
    else if (bMemberStyle)
    {
        rNewTerm << new ClassAttr("member");
    }
    if ( i_sTerm != 0 )
        rNewTerm << i_sTerm;

    pTerm = &rNewTerm;
    pDefinition = &pList->AddDefinition();
    if (bMemberStyle)
        *pDefinition << new ClassAttr("member");
}

void
ExplanationList::AddEntry_NoTerm()
{
    pTerm = 0;
    pDefinition = &pList->AddDefinition();
    if (bMemberStyle)
        *pDefinition << new ClassAttr("member");
}

ExplanationTable::ExplanationTable( XmlElement &    o_rOwner )
    :   pTable(0),
        pTerm(0),
        pDefinition(0)
{
    pTable = new Table("0", "100%", "3", "0");
    *pTable << new AnAttribute("class", "expl-table");
    o_rOwner << pTable;
}

void
ExplanationTable::AddEntry( const char *        i_sTerm,
                            const char *        i_sDifferentStyle )
{
    TableRow &
        rNewRow = pTable->AddRow();
    TableCell &
        rNewTerm = rNewRow.AddCell();
    TableCell &
        rNewDefinition = rNewRow.AddCell();

    if ( i_sDifferentStyle == 0 )
    {
        rNewTerm << new WidthAttr("15%")
                 << new StyleAttr("vertical-align:top; font-weight:bold");
    }
    else
    {
        rNewTerm << new StyleAttr(i_sDifferentStyle);
    }
    if ( i_sTerm != 0 )
        rNewTerm << i_sTerm;

    pTerm = &rNewTerm;
    pDefinition = & (rNewDefinition >> *new APureElement("pre"));
}

ParameterTable::ParameterTable( XmlElement &    o_rOwner )
    :   pTable(0),
        pTerm(0),
        pDefinition(0)
{
    pTable = new Table;
    *pTable << new AnAttribute("class", "param-table");
    o_rOwner << pTable;
}

void
ParameterTable::AddEntry()
{
    TableRow &
        rNewRow = pTable->AddRow();
    TableCell &
        rNewTerm = rNewRow.AddCell();
    TableCell &
        rNewDefinition = rNewRow.AddCell();

    pTerm = &rNewTerm;
    pDefinition = &rNewDefinition;
}

FlagTable::FlagTable( XmlElement &        o_rOwner,
                      uintt               i_nNrOfColumns )
{
    pTable = new Table;
    *pTable << new AnAttribute("class", "flag-table");
    *pTable << new AnAttribute("border", "1");
    *pTable << new AnAttribute("cellspacing", "0");
    o_rOwner << pTable;

    TableRow & rRow1 = pTable->AddRow();
    TableRow & rRow2 = pTable->AddRow();

    for ( uintt c = 0; c < i_nNrOfColumns; ++c )
    {
        TableCell & rCell1 = rRow1.AddCell();
        int nWidth = 100 / i_nNrOfColumns;
        static char sWidth[20];
        sprintf( sWidth, "%d%%", nWidth );      // SAFE SPRINTF (#100211# - checked)

        rCell1
            << new WidthAttr( sWidth )
            << new ClassAttr( "flagname" );
        TableCell & rCell2 = rRow2.AddCell();
        aCells.push_back( CellPair(&rCell1, &rCell2) );
    }   // end for
}

void
FlagTable::SetColumn( uintt               i_nColumnPosition,
                      const char *        i_sColumnName,
                      bool                i_bValue )
{
    csv_assert( i_nColumnPosition < aCells.size() );

    TableCell &
        rCell1 = *aCells[i_nColumnPosition].first;
    TableCell &
        rCell2 = *aCells[i_nColumnPosition].second;
    rCell1
        << i_sColumnName;
    if (i_bValue)
    {
        rCell2
            << new ClassAttr("flagyes")
            << "YES";
    }
    else //
    {
        rCell2
            << new ClassAttr("flagno")
            << "NO";
    }  // endif
}

void
FlagTable::SetColumn( uintt               i_nColumnPosition,
                      const char *        i_sColumnName,
                      const char *        i_sValue )
{
    csv_assert( i_nColumnPosition < aCells.size() );

    TableCell &
        rCell1 = *aCells[i_nColumnPosition].first;
    TableCell &
        rCell2 = *aCells[i_nColumnPosition].second;
    rCell1
        << i_sColumnName;
    rCell2
        << new ClassAttr( "flagtext" )
        << i_sValue;
}

IndexList::IndexList( XmlElement & o_rOwner )
    :   pList( new DefList ),
        pTerm(0),
        pDefinition(0)
{
    o_rOwner << pList;
}

void
IndexList::AddEntry()
{
    pTerm = &pList->AddTerm();
    pDefinition = &pList->AddDefinition();
}


}   // namespace adcdisp



