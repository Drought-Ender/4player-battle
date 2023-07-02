FOURPLAYER_FILES:=\
	$(BUILD_DIR)/src/FourPlayer/Splitter.o\
	$(BUILD_DIR)/src/FourPlayer/FourPlayerMain.o\
	$(BUILD_DIR)/src/FourPlayer/VsSetup.o\
	$(BUILD_DIR)/src/FourPlayer/objVs.o\
	$(BUILD_DIR)/src/FourPlayer/CardMgr.o\
	$(BUILD_DIR)/src/FourPlayer/VsSelect.o\
	$(BUILD_DIR)/src/FourPlayer/VsOptions.o\
	$(BUILD_DIR)/src/FourPlayer/VsConfigFunc.o\
	$(BUILD_DIR)/src/FourPlayer/pelletBounceBury.o\
	$(BUILD_DIR)/src/FourPlayer/PikiModifier.o\
	$(BUILD_DIR)/src/FourPlayer/PelletModifier.o\
	$(BUILD_DIR)/src/FourPlayer/CaveScoreHell.o\
	$(BUILD_DIR)/src/FourPlayer/CherryTarget.o\





DEPENDS += $(FOURPLAYER_FILES:.o=.d)

$(BUILD_DIR)/src/FourPlayer/FourPlayer.a: $(FOURPLAYER_FILES)
	@echo Linking... $@
	$(QUIET) mkdir -p $(dir $@)
	@echo $(FOURPLAYER_FILES) > build/FOURPLAYER_ofiles
	$(QUIET) $(LD) -library $(LIBRARY_LDFLAGS) -o $@ -lcf ldscript.lcf @build/FOURPLAYER_ofiles
