#############################################################################
# Makefile for building: ProjectOnline
# Generated by qmake (3.0) (Qt 5.3.1)
# Project:  ..\ProjectOnline\ProjectOnline.pro
# Template: app
# Command: C:\Qt531\5.3\msvc2012_opengl\bin\qmake.exe -spec win32-msvc2012 CONFIG+=debug -o Makefile ..\ProjectOnline\ProjectOnline.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\Qt531\5.3\msvc2012_opengl\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = copy /y
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: ..\ProjectOnline\ProjectOnline.pro ..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\win32-msvc2012\qmake.conf ..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\spec_pre.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\common\shell-win32.conf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\qconfig.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axbase.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axserver.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_core.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_core_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_declarative.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_declarative_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designer.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_enginio.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_enginio_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_gui.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_help.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_help_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_network.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_network_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_nfc.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_opengl.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_platformsupport_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_positioning.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qml.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quick.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_script.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_script_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sensors.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_serialport.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sql.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_svg.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_testlib.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_uitools.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkit.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkit_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkitwidgets.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkitwidgets_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_websockets.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_widgets.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_winextras.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xml.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt_functions.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt_config.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\qt_config.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\win32-msvc2012\qmake.conf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\spec_post.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exclusive_builds.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\default_pre.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\default_pre.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\resolve_config.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exclusive_builds_post.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\default_post.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\rtti.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\precompile_header.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\warn_on.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\resources.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\moc.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\opengl.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\uic.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\windows.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\testcase_targets.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exceptions.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\yacc.prf \
		..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\lex.prf \
		..\ProjectOnline\ProjectOnline.pro \
		C:/Qt531/5.3/msvc2012_opengl/lib/qtmaind.prl \
		C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Cored.prl \
		C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Widgets.prl \
		C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Sql.prl \
		C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Gui.prl \
		C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Core.prl
	$(QMAKE) -spec win32-msvc2012 CONFIG+=debug -o Makefile ..\ProjectOnline\ProjectOnline.pro
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\spec_pre.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\common\shell-win32.conf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\qconfig.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axbase.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axserver.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_concurrent.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_core.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_core_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_declarative.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_declarative_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designer.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designer_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_enginio.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_enginio_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_gui.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_gui_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_help.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_help_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimedia.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_network.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_network_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_nfc.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_opengl.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_platformsupport_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_positioning.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_printsupport.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qml.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qml_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmltest.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quick.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quick_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_script.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_script_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_scripttools.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sensors.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_serialport.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sql.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_sql_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_svg.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_svg_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_testlib.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_uitools.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkit.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkit_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkitwidgets.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_webkitwidgets_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_websockets.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_widgets.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_winextras.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xml.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xml_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt_functions.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt_config.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\qt_config.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\win32-msvc2012\qmake.conf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\spec_post.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exclusive_builds.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\default_pre.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\default_pre.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\resolve_config.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exclusive_builds_post.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\default_post.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\rtti.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\precompile_header.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\warn_on.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\qt.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\resources.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\moc.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\opengl.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\uic.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\win32\windows.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\testcase_targets.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\exceptions.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\yacc.prf:
..\..\..\..\Qt531\5.3\msvc2012_opengl\mkspecs\features\lex.prf:
..\ProjectOnline\ProjectOnline.pro:
C:/Qt531/5.3/msvc2012_opengl/lib/qtmaind.prl:
C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Cored.prl:
C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Widgets.prl:
C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Sql.prl:
C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Gui.prl:
C:/Qt531/5.3/msvc2012_opengl/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2012 CONFIG+=debug -o Makefile ..\ProjectOnline\ProjectOnline.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
	-$(DEL_FILE) ProjectOnline.exp
	-$(DEL_FILE) ProjectOnline.ilk
	-$(DEL_FILE) ProjectOnline.idb
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) ProjectOnline.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
