PRJ=..
PRJNAME=odk
TARGET=odk

# ------------------------------------------------------------------
.INCLUDE: settings.mk
.INCLUDE: makefile.pmk
# ------------------------------------------------------------------

ZIPFILE=$(PRODUCTZIPFILE)
TARGZFILE=$(PRODUCTTARGZFILE)
ZIPDIR=$(PRODUCT_NAME)

.IF "$(OS)"=="WNT"
all:\
    $(BIN)$/$(ZIPFILE)
.ELSE
all:\
    $(BIN)$/$(TARGZFILE)
.ENDIF


$(BIN)$/$(ZIPFILE) .SETDIR=$(DESTDIR)$/.. .PHONY:
    +zip -ur $(ZIPFILE) $(ZIPDIR)

$(BIN)$/$(TARGZFILE) .SETDIR=$(DESTDIR)$/.. .PHONY:
#	tar does not properly support update
    +tar cf - $(ZIPDIR) | gzip - > $(TARGZFILE)
    



