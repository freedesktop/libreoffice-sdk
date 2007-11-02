/*************************************************************************
 *
 *  OpenOffice.org - a multi-platform office productivity suite
 *
 *  $RCSfile: nametree.hxx,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: hr $ $Date: 2007-11-02 16:02:01 $
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

#ifndef ARY_NAMETREE_HXX
#define ARY_NAMETREE_HXX

// USED SERVICES
#include <ary/types.hxx>
#include <ary/namesort.hxx>
#include "instlist.hxx"




namespace ary
{


class NameTree
{
  public:
    typedef std::map<  String ,
                       InstanceList,
                       LesserName >             Map_Name2Inst;

    typedef Map_Name2Inst::const_iterator       const_iterator;
    typedef Map_Name2Inst::iterator             iterator;


                        NameTree();
                        ~NameTree();

    const InstanceList &
                        operator[](
                            const String  &     i_rName ) const;

    void                insert(
                            const String  &     i_rName,
                            ary::Rid            i_nId );

    const_iterator      find(
                            const String  &     i_rName );
    const_iterator      lower_bound(
                            const String  &     i_rName ) const;
    const_iterator      begin() const;
    const_iterator      end() const;

    iterator            begin();
    iterator            end();

  private:
    // DATA
    Map_Name2Inst       aNames;
};




}   // namespace ary
#endif
