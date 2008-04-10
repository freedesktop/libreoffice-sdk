/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: filecoll.hxx,v $
 * $Revision: 1.4 $
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

#ifndef ADC_FILECOLL_HXX
#define ADC_FILECOLL_HXX

// USED SERVICES
    // BASE CLASSES
#include <autodoc/filecoli.hxx>
    // COMPONENTS
    // PARAMETERS



class FileCollector : public autodoc::FileCollector_Ifc
{
  public:
    // LIFECYCLE
                        FileCollector(
                            uintt       		i_nRoughNrOfFiles = 0 );

    // OPERATIONS
    virtual uintt       AddFilesFrom(
                            const char *		i_sRootDir,
                            const char *		i_sFilter,
                            E_SearchMode		i_eSearchMode );
    virtual uintt       AddFile(
                            const char *		i_sFilePath );
    virtual void        EraseAll();

    // INQUIRY
    virtual const_iterator
                        Begin() const;
    virtual const_iterator
                        End() const;
    virtual uintt       Size() const;

  private:
    // DATA
    StringVector        aFoundFiles;
};


#endif

