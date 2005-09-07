#*************************************************************************
#
#   OpenOffice.org - a multi-platform office productivity suite
#
#   $RCSfile: makefile.mk,v $
#
#   $Revision: 1.2 $
#
#   last change: $Author: rt $ $Date: 2005-09-07 17:30:46 $
#
#   The Contents of this file are made available subject to
#   the terms of GNU Lesser General Public License Version 2.1.
#
#
#     GNU Lesser General Public License Version 2.1
#     =============================================
#     Copyright 2005 by Sun Microsystems, Inc.
#     901 San Antonio Road, Palo Alto, CA 94303, USA
#
#     This library is free software; you can redistribute it and/or
#     modify it under the terms of the GNU Lesser General Public
#     License version 2.1, as published by the Free Software Foundation.
#
#     This library is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#     Lesser General Public License for more details.
#
#     You should have received a copy of the GNU Lesser General Public
#     License along with this library; if not, write to the Free Software
#     Foundation, Inc., 59 Temple Place, Suite 330, Boston,
#     MA  02111-1307  USA
#
#*************************************************************************

PRJ=..$/..$/..

PRJNAME=autodoc
TARGET=display_html


# --- Settings -----------------------------------------------------

ENABLE_EXCEPTIONS=true
PRJINC=$(PRJ)$/source

.INCLUDE :  settings.mk
.INCLUDE : $(PRJ)$/source$/mkinc$/fullcpp.mk


# --- Files --------------------------------------------------------

OBJFILES= \
    $(OBJ)$/aryattrs.obj    \
    $(OBJ)$/cfrstd.obj	    \
    $(OBJ)$/chd_udk2.obj	\
    $(OBJ)$/cre_link.obj	\
    $(OBJ)$/dsply_cl.obj	\
    $(OBJ)$/dsply_da.obj    \
    $(OBJ)$/dsply_op.obj	\
    $(OBJ)$/easywri.obj	    \
    $(OBJ)$/hd_chlst.obj  	\
    $(OBJ)$/hd_docu.obj  	\
    $(OBJ)$/hdimpl.obj  	\
    $(OBJ)$/html_kit.obj  	\
    $(OBJ)$/nav_main.obj  	\
    $(OBJ)$/navibar.obj  	\
    $(OBJ)$/outfile.obj     \
    $(OBJ)$/opageenv.obj    \
    $(OBJ)$/pagemake.obj    \
    $(OBJ)$/pm_aldef.obj    \
    $(OBJ)$/pm_base.obj     \
    $(OBJ)$/pm_class.obj    \
    $(OBJ)$/pm_help.obj     \
    $(OBJ)$/pm_index.obj    \
    $(OBJ)$/pm_namsp.obj    \
    $(OBJ)$/pm_start.obj    \
    $(OBJ)$/protarea.obj


# --- Targets ------------------------------------------------------

.INCLUDE :  target.mk



