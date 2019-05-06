Install OpenCV 3.1.0 / Microsoft Visual Studio 2015 / Windows 10 64 bits

1) Download and install Microsoft Visual Studio 2015. (Do not download basic version)
	link: "https://www.visualstudio.com/downloads/"
2) Download OpenCV 3.1.0.
	link: "http://sourceforge.net/projects/opencvlibrary/files/opencv-win/3.1.0/opencv-3.1.0.exe/download"
3) Extract OpenCV to “C:\”. After extracting, you will end up having a folder called “C:\opencv”.
4) On Windows:
 	A.	In Search, search for and then select: “System” (Control Panel).
	B.	Click on the “Advanced System Settings” link.
	C.	Click Environment Variables.
	D.	In System Variables, click on “Path”.
	E.	Click on “Modify”.
	F.	Click on “New” and add the following (without quotation marks): “C:\opencv\build\x64\vc14\lib\”.
	G.	Click on “New” again and add the following (without quotation marks): “C:\opencv\build\x64\vc14\bin\”.
5) Restart Windows.
6) Open Visual Studio and create a new project.
7) On “Solution Explorer”:
	A.	Right click on the project title and then go to “Properties”.
	B.	Change Platform to “x64”.
	C.	Go to “C/C++” -> “General” -> “Additional Include Directories” and add (without quotation marks) “C:\opencv\build\include”. Click on “Apply”.
	D.	Go to “Linker” -> “General” -> “Additional Library Directories” and add (without quotation marks) “C:\opencv\build\x64\vc14\lib”. Click on “Apply”.
	E.	Go to “Linker” -> “Input” -> “Additional Dependencies” and add (without quotation marks) “opencv_world310.lib;opencv_world310d.lib;”. Click on “Apply”.
8) Try some of the shared cpp files. If everything installed correctly, all of them should work without any bugs.