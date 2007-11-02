/*************************************************************************
 *
 *  OpenOffice.org - a multi-platform office productivity suite
 *
 *  $RCSfile: dht_helper.hxx,v $
 *
 *  $Revision: 1.2 $
 *
 *  last change: $Author: hr $ $Date: 2007-11-02 15:39:50 $
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

#ifndef ARY_DOC_DHT_HELPER_HXX
#define ARY_DOC_DHT_HELPER_HXX



namespace ary
{
namespace doc
{
namespace ht
{

class Component;
class Interpreter;


/** Joins two strings with a separator and creates a component
    from the result.

    If ->i_str2 is empty, only i_str1 is used without the separator.
*/
Component           Create_Component(
                        const Interpreter & i_intepreter,
                        const String &      i_str1,
                        char                i_separator,
                        const String &      i_str2 );

/** Joins two strings with a separator and creates a component
    from the result.

    If ->i_str2 is empty, only i_str1 is used without the separator.
*/
void                Resolve_ComponentData(
                        String &            o_1,
                        String &            o_2,
                        char                i_separator,
                        const String &      i_data );



}   // namespace ht
}   // namespace doc
}   // namespace ary

#endif
