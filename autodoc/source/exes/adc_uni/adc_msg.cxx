/*************************************************************************
 *
 *  $RCSfile: adc_msg.cxx,v $
 *
 *  $Revision: 1.2 $
 *
 *  last change: $Author: obo $ $Date: 2005-01-27 11:20:06 $
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
#include <adc_msg.hxx>


// NOT FULLY DEFINED SERVICES
#include <cosv/file.hxx>
#include <cosv/template/tpltools.hxx>


namespace autodoc
{


Messages::Messages()
    :   aMissingDocs(),
        aParseErrors(),
        aInvalidConstSymbols(),
        aUnresolvedLinks(),
        aTypeVsMemberMisuses()
{
}

Messages::~Messages()
{
}

void
Messages::WriteFile(const String & i_sOutputFilePath)
{
    csv::File
        aOut(i_sOutputFilePath, csv::CFM_CREATE);
    aOut.open();

    // KORR_FUTURE Enable this when appropriate:
    WriteParagraph( aOut,
                    aParseErrors,
                    "Incompletely Parsed Files",
                    "Stopped parsing at " );

    WriteParagraph( aOut,
                    aMissingDocs,
                    "Entities Without Documentation",
                    " in " );

    WriteParagraph( aOut,
                    aInvalidConstSymbols,
                    "Incorrectly Written Const Symbols",
                    " in " );

    WriteParagraph( aOut,
                    aUnresolvedLinks,
                    "Unresolved Links",
                    " in\n        " );

    WriteParagraph( aOut,
                    aTypeVsMemberMisuses,
                    "Confusion or Misuse of <Type> vs. <Member>",
                    " in " );
    aOut.close();
}

void
Messages::Out_MissingDoc(   const String &      i_sEntity,
                            const String &      i_sFile,
                            uintt               i_nLine)
{
    AddValue( aMissingDocs,
              i_sEntity,
              i_sFile,
              i_nLine );
}

void
Messages::Out_ParseError(   const String &      i_sFile,
                            uintt               i_nLine)
{
    aParseErrors[Location(i_sFile,i_nLine)] = String::Null_();
}

void
Messages::Out_InvalidConstSymbol( const String &      i_sText,
                                  const String &      i_sFile,
                                  uintt               i_nLine)
{
    AddValue( aInvalidConstSymbols,
              i_sText,
              i_sFile,
              i_nLine );
}

void
Messages::Out_UnresolvedLink( const String &      i_sLinkText,
                              const String &      i_sFile,
                              uintt               i_nLine)
{
    AddValue( aUnresolvedLinks,
              i_sLinkText,
              i_sFile,
              i_nLine );
}

void
Messages::Out_TypeVsMemberMisuse( const String &      i_sLinkText,
                                  const String &      i_sFile,
                                  uintt               i_nLine)
{
    AddValue( aTypeVsMemberMisuses,
              i_sLinkText,
              i_sFile,
              i_nLine );
}

Messages &
Messages::The_()
{
    static Messages TheMessages_;
    return TheMessages_;
}

void
Messages::AddValue( MessageMap &        o_dest,
                    const String &      i_sText,
                    const String &      i_sFile,
                    uintt               i_nLine )
{
    String &
        rDest = o_dest[Location(i_sFile,i_nLine)];
    StreamLock
        slDest(2000);
    if (NOT rDest.empty())
        slDest() << rDest;
    slDest() << "\n    " << i_sText;
    rDest = slDest().c_str();
}

void
Messages::WriteParagraph( csv::File &         o_out,
                          const MessageMap &  i_source,
                          const String &      i_title,
                          const String &      i_firstIntermediateText )
{
    StreamStr   aLine(2000);

    // Write title of paragraph:
    aLine << i_title
          << "\n";
    o_out.write(aLine.c_str());

    aLine.seekp(0);
    for (uintt i = i_title.size(); i > 0; --i)
    {
        aLine << '-';
    }
    aLine << "\n\n";
    o_out.write(aLine.c_str());

    // Write Content
    MessageMap::const_iterator it = i_source.begin();
    MessageMap::const_iterator itEnd = i_source.end();
    for ( ; it != itEnd; ++it )
    {
        aLine.seekp(0);
        aLine << (*it).first.sFile;
        // Nobody wants to see this, if we don't know the line:
        if ((*it).first.nLine != 0)
        {
            aLine << ", line "
                  << (*it).first.nLine;
        }
        if (NOT (*it).second.empty())
        {
            aLine << ':'
                  << (*it).second
                  << "\n";
        }
        o_out.write(aLine.c_str());
    }
    o_out.write("\n\n\n");
}

}   // namespace autodoc
