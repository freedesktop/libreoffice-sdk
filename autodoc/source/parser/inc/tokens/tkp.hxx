/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: tkp.hxx,v $
 * $Revision: 1.3 $
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

#ifndef ADC_TKP_HXX
#define ADC_TKP_HXX

// USED SERVICES
    // BASE CLASSES
    // COMPONENTS
class CharacterSource;
class TkpContext;
    // PARAMETRS



/** This is the interface for parser classes, which get a sequence of tokens from
    a text.

    Start() starts to parse the text from the given i_rSource.
    GetNextToken() returns a Token on the heap as long as there are
    still characters in the text left. This can be checked by
    HasMore().

    The algorithms for parsing tokens from the text are an issue of
    the derived classes.
*/
#if 0
/**
    Parsing can be interrupted for a different source by PushSource().
    The parsing before interruption is continued after PopSource().
*/
#endif // 0

class TokenParser
{
  public:
    // LIFECYCLE
                        TokenParser();
    virtual				~TokenParser() {}

    // OPERATIONS
    /** Start parsing a character source. Any previously parsed sources
        are discarded.
    */
    virtual void   		Start(
                            CharacterSource &
                                            i_rSource );

    /** @short	Gets the next identifiable token out of the
        source code.
    */
    void				GetNextToken();

    /// @return true, if there are more tokens to parse.
    bool				HasMore() const			{ return bHasMore; }

  private:
    void                InitSource(
                            CharacterSource &
                                            i_rSource );

    virtual void		SetStartContext() = 0;
    virtual void        SetCurrentContext(
                            TkpContext &		io_rContext ) = 0;
    virtual TkpContext &
                        CurrentContext() = 0;
    // DATA
    CharacterSource *	pChars;
    bool				bHasMore;
};


#endif


