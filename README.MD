# CompilerExplorer

[![Build Status](https://travis-ci.org/dobokirisame/CompilerExplorer.svg?branch=master)](https://travis-ci.org/dobokirisame/CompilerExplorer)

----------
QtCreator plugin based on  https://github.com/mattgodbolt/compiler-explorer (https://gcc.godbolt.org/)

License: MIT




----------
> **Build instruction**
>
>Download QtCreator sources from http://download.qt.io. It Should be exactly as your QtCreator version(Help->About QtCreator)  
>Copy qt_deps.pri.template file to qt_deps.pri and edit it  
>

----------
> **Instruction**
>
>Install NodeJS  
>Clone and make compiler-explorer (https://github.com/mattgodbolt/compiler-explorer)  
>Build plugin with Qt your QtCreator based on (Help->About QtCreator)  
>Install library in your QtCreator plugins directory  
>Turn on in plugins list  
>

----------
> **Instruction for Windows**
>
>If you use Linux or macOs there will be no problem for you to start local compiler-explorer server with local compilers.  
>But if you use MSYS2 with MinGW64 on Windows OS you might have one.  
>Go to **c-preload/Makefile**  
>Change this line **$(CC) -std=c99 -shared -O1 -fPIC $^ -o $@ $(LDL)**  
>To something like this **$(GCC) --std=c++1z -shared -O3 -fPIC $^ -o $@ $(LDL)"**  
>Then go to **c-preload/preload.c**  
>Edit line **resolved = realpath(path, resolvedBuf);**  
>Just make **resolved =  NULL;**  
>Add yor configuration file (**c++.local.properties**)  
>https://github.com/mattgodbolt/compiler-explorer/issues/468  
>  
> ```javascript  
>compilers=gcc  
>compiler.gcc.exe=/msys64/mingw64/bin/gcc.exe  
>compiler.gcc.name=GCC  
>```  
>If you run "make" it'll probably failed.  
>Because "make" command starts nodeJS server with supervisor module.  
>IDK why but this module doesn't work well on Windows OS.  
>So just run  
> ```javascript   
>/your/NodeJs/Location/node ./app.js  
>```  
> 
