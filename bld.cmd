@echo off
if "%~1" == "clean" (
	del /S /Q build\
	rmdir /S /Q build\
) else (
	mkdir build
	pushd build
	cmake ..
	cmake --build .
	popd
)
