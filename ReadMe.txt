DumpWriteTool 程序崩溃后写入dump文件的动态库
=================================================
调用该动态库的程序在程序崩溃之后，创建dump文件。


编写平台：
VS2005/Windows 7/windows sdk6（我所在的公司用的就是这开发环境）

适用平台：
WinXp、Visual、Win7、Win8以及8.1

使用说明：
①编译dumpwritetool工程，得到dumpwritetool.dll。
②在别的工程中调用initialdump.h文件里的InitialDump。
③dumpwritetool.dll与别的工程中生成的二进制文件放在同一目录下即可。

生成的dump会放在%temp%文件夹中

权利声明：
本代码以BSD协议发布，您可以自由使用本代码，代码作者不对该代码造成的任何问题承担责任。

我的联系方式：
yucoat@yucoat.com