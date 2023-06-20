FOURPLAYER_FILES:=\
	$(BUILD_DIR)/src/FourPlayer/Splitter.o\
	$(BUILD_DIR)/src/FourPlayer/FourPlayerMain.o\
	$(BUILD_DIR)/src/FourPlayer/VsSetup.o\
	$(BUILD_DIR)/src/FourPlayer/objVs.o\

DEPENDS += $(FOURPLAYER_FILES:.o=.d)

$(BUILD_DIR)/src/FourPlayer/FourPlayer.a: $(FOURPLAYER_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(FOURPLAYER_FILES) > build/FOURPLAYER_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/FOURPLAYER_ofiles
