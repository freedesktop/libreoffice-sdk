/*************************************************************************
 *
 *  $RCSfile: opageenv.hxx,v $
 *
 *  $Revision: 1.1.1.1 $
 *
 *  last change: $Author: np $ $Date: 2002-03-08 14:45:24 $
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

#ifndef ADC_DISPLAY_HTML_OPAGEENV_HXX
#define ADC_DISPLAY_HTML_OPAGEENV_HXX


// USED SERVICES
    // BASE CLASSES
    // COMPONENTS
#include <slist>
#include <cosv/ploc.hxx>
    // PARAMETERS

namespace ary
{
    namespace cpp
    {
        class DisplayGate;

        class ProjectGroup;
        class FileGroup;

        class Namespace;
        class Class;
        class Enum;
        class Typedef;
    }
}
namespace display
{
    class CorporateFrame;
}

class OuputPage_Environment
{
  public:
    // LIFECYCLE
                        OuputPage_Environment(
                            const csv::ploc::Path &
                                                io_rOutputDir,
                            const ary::cpp::DisplayGate &
                                                i_rGate,
                            const display::CorporateFrame &
                                                i_rLayout );
                        ~OuputPage_Environment();

    // OPERATIONS
    void                MoveDir_2Root();
    void                MoveDir_Down2(             /// Only one level.
                            const ary::cpp::Namespace &
                                                i_rNsp );
    void                MoveDir_Down2(             /// Only one level.
                            const ary::cpp::Class &
                                                i_rClass );
    void                MoveDir_2Project(
                            const ary::cpp::ProjectGroup &
                                                i_rProject );
    void                MoveDir_2Index();
    void                MoveDir_Up();

    void                SetFile_Overview();
    void                SetFile_AllDefs();
    void                SetFile_Index(
                            char                i_cLetter );
    void                SetFile_Help();
    void                SetFile_CurNamespace();
    void                SetFile_Class(
                            const ary::cpp::Class &
                                                i_rClass );
    void                SetFile_Enum(
                            const ary::cpp::Enum &
                                                i_rEnum );
    void                SetFile_Typedef(
                            const ary::cpp::Typedef &
                                                i_rEnum );
    void                SetFile_Operations(
                            const ary::cpp::FileGroup *
                                                i_pFile = 0 );  /// Only needed for global functions.
    void                SetFile_Data(
                            const ary::cpp::FileGroup *
                                                i_pFile = 0 );  /// Only needed for global variables.
    void                SetFile_CurProject();
    void                SetFile_File(
                            const ary::cpp::FileGroup &
                                                i_rFile );
    void                SetFile_Defs(
                            const ary::cpp::FileGroup &
                                                i_rFile );
    // INQUIRY
    const ary::cpp::Namespace *
                        CurNamespace() const;
    const ary::cpp::Class *
                        CurClass() const;
    const csv::ploc::Path &
                        CurPath() const;
    const ary::cpp::DisplayGate &
                        Gate() const;
    const display::CorporateFrame &
                        Layout() const;
    uintt               Depth() const;

  private:
    struct CheshireCat;
    Dyn<CheshireCat>    pi;
};


#endif


