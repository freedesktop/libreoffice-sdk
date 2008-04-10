/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: prs_code.hxx,v $
 * $Revision: 1.5 $
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

#ifndef AUTODOC_PRS_CODE_HXX
#define AUTODOC_PRS_CODE_HXX



namespace csv
{
    namespace ploc
    {
        class Path;
    }
}

namespace ary
{
    class Repository;
}

namespace autodoc
{
    class FileCollector_Ifc;
    class DocumentationParser_Ifc;




/** Interface for parsing code of a programming language and
    delivering the information into an Autodoc Repository.
**/
class CodeParser_Ifc
{
  public:
    virtual				~CodeParser_Ifc() {}

    virtual void		Setup(
                            ary::Repository &   o_rRepository,
                            const autodoc::DocumentationParser_Ifc &
                                                i_rDocumentationInterpreter ) = 0;

    virtual void		Run(
                            const autodoc::FileCollector_Ifc &
                                                i_rFiles ) = 0;
};




} // namespace autodoc
#endif
